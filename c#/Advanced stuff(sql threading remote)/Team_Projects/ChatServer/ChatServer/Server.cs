using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;

using System.Net.Sockets;
using System.Net;
using MySql.Data.MySqlClient;
using System.Threading;

namespace ChatServer
{
    

    public partial class Server : Form
    {
        #region Private Members

        private struct Client
        {
            public EndPoint endPoint;
            public string name;
        }

        private struct ClientInfo
        {
            
            public string firstName;
            public string lastName;
            public string mail;
            public string phone;
        }

        private ArrayList clientList;
        private Socket serverSocket;
        private MySqlConnection mySqlConnection;
        private string clientPass;

        private byte[] serverDataStream = new byte[1024];

        private delegate void UpdateStatusDelegate(string status);
        private UpdateStatusDelegate updateStatusDelegate = null;

        #endregion

        #region Constructor

        public Server()
        {
            InitializeComponent();
        }

        #endregion

        #region Send and Receive

        public void SendData(IAsyncResult asyncResult)
        {
            try
            {
                serverSocket.EndSend(asyncResult);
            }
            catch (Exception ex)
            {
                MessageBox.Show("SendData Error: " + ex.Message, "UDP Server", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ReceiveData(IAsyncResult asyncResult)
        {
            try
            {
                byte[] data;
                Packet receivedData = new Packet(serverDataStream);

                Packet sendData = new Packet();
                IPEndPoint clients = new IPEndPoint(IPAddress.Any, 0);
                EndPoint epSender = (EndPoint)clients;
                serverSocket.EndReceiveFrom(asyncResult, ref epSender);
                //Debug.WriteLine(epSender);

                sendData.ChatDataIdentifier = receivedData.ChatDataIdentifier;

                // Username/password split
                switch (receivedData.ChatDataIdentifier)
                {
                    case DataIdentifier.LogIn:
                        string[] userPassAux = new string[2];
                        userPassAux = receivedData.ChatName.Split(':');
                        receivedData.ChatName = userPassAux[0];
                        clientPass = userPassAux[1];

                        if (!MySqlVerifyClient(receivedData.ChatName, clientPass, epSender.ToString(), mySqlConnection))
                        {
                            sendData.ChatDataIdentifier = receivedData.ChatDataIdentifier = DataIdentifier.FLogIn;
                            sendData.ChatName = receivedData.ChatName;
                            sendData.ChatMessage = "Username or Password Incorrect";
                        }

                        data = sendData.GetDataStream();
                        serverSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, epSender, new AsyncCallback(SendData), epSender);
                        serverSocket.BeginReceiveFrom(serverDataStream, 0, serverDataStream.Length, SocketFlags.None, ref epSender, new AsyncCallback(ReceiveData), epSender);
                        break;
                    case DataIdentifier.SignUp:
                        if (!MySqlExistentUser(receivedData.ChatName, mySqlConnection))
                        {

                            ClientInfo info = new ClientInfo();
                            string[] infoStr = new string[5];
                            infoStr = receivedData.ChatMessage.Split('%');
                            clientPass = infoStr[0];
                            info.firstName = infoStr[1];
                            info.lastName = infoStr[2];
                            info.mail = infoStr[3];
                            info.phone = infoStr[4];
                            MySqlAddClient(receivedData.ChatName, clientPass, epSender.ToString(), mySqlConnection, info.firstName, info.lastName, info.mail, info.phone);

                        }
                        else
                        {

                            sendData.ChatDataIdentifier = DataIdentifier.FSignUp;



                        }
                        sendData.ChatName = receivedData.ChatName;
                        data = sendData.GetDataStream();

                        serverSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, epSender, new AsyncCallback(SendData), epSender);

                        serverSocket.BeginReceiveFrom(serverDataStream, 0, serverDataStream.Length, SocketFlags.None, ref epSender, new AsyncCallback(ReceiveData), epSender);
                        break;
                    default:
                        sendData.ChatName = receivedData.ChatName;

                        switch (receivedData.ChatDataIdentifier)
                        {
                            case DataIdentifier.Message:
                                sendData.ChatMessage = string.Format("{0} : {1}", receivedData.ChatName, receivedData.ChatMessage);
                                break;
                            case DataIdentifier.Online:
                                Client client = new Client();
                                client.endPoint = epSender;
                                client.name = receivedData.ChatName;
                                clientList.Add(client);
                                sendData.ChatMessage = string.Format("- {0} is online -", receivedData.ChatName);
                                break;
                            case DataIdentifier.LogOut:
                                foreach (Client c in clientList)
                                    if (c.endPoint.Equals(epSender))
                                    {
                                        clientList.Remove(c);
                                        break;
                                    }
                                sendData.ChatMessage = string.Format("- {0} has gone offline -", receivedData.ChatName);
                                break;
                        }
                        data = sendData.GetDataStream();
                        foreach (Client c in clientList)
                            if (c.endPoint != epSender || sendData.ChatDataIdentifier != DataIdentifier.Online)
                                 serverSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, c.endPoint, new AsyncCallback(SendData), c.endPoint);

                        serverSocket.BeginReceiveFrom(serverDataStream, 0, serverDataStream.Length, SocketFlags.None, ref epSender, new AsyncCallback(ReceiveData), epSender);
                        Invoke(updateStatusDelegate, new object[] { sendData.ChatMessage });
                        break;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("ReceiveData Error: " + ex.Message, "UDP Server", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion

        #region Events

        private void UpdateStatus(string status)
        {
            textStatus.Text += status + Environment.NewLine;
        }


        private void exitBtn_Click(object sender, EventArgs e)
        {
            Close();
        }

        #endregion

        #region MySql Methods

        private void MysqlFirstTimeSetup()
        {

            string mySqlServer = "localhost";
            string mySqlUser = "root";
            string mySqlPassword = "teodor12";
            string mySqlDatabase = "chatterbox";
            string connectionString = "SERVER=" + mySqlServer + ";" + "UID=" + mySqlUser + ";" + "PASSWORD=" + mySqlPassword + ";";
            MySqlConnection conn = new MySqlConnection(connectionString);
            conn.Open();

            string query = "select count(SCHEMA_NAME) from INFORMATION_SCHEMA.SCHEMATA where SCHEMA_NAME = \"chatterbox\";";
            MySqlCommand command = new MySqlCommand(query, conn);

            if (command.ExecuteScalar().ToString() == "0")
            {
                query = string.Format("CREATE DATABASE {0}", mySqlDatabase);
                command = new MySqlCommand(query, conn);
                command.ExecuteNonQuery();

                query = "CREATE TABLE chatterbox.clients (id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT, " +
                    "Name varchar(100) NOT NULL, " +
                    "Password varchar(100) NOT NULL, " +
                    "IP varchar(45) NOT NULL )";
                command = new MySqlCommand(query, conn);
                command.ExecuteNonQuery();

                query = "CREATE TABLE chatterbox.client_details (id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT, " +
                    "idClient int(10) NOT NULL, " +
                    "FirstName varchar(100) NOT NULL, " +
                    "LastName varchar(100) NOT NULL, " +
                    "MailAdress varchar(100), " +
                    "PhoneNumber varchar(100) )";
                command = new MySqlCommand(query, conn);
                command.ExecuteNonQuery();

            }

            conn.Close();
        }

        private void ConnectToMySqlServer(MySqlConnection _mySqlConnection)
        {
            try
            {
                _mySqlConnection.Open();
            }
            catch (MySqlException ex)
            {
                //0: Cannot connect to server.
                //1045: Invalid user name and/or password.
                switch (ex.Number)
                {
                    case 0:
                        MessageBox.Show("Could not connect to the server.  Contact administrator");
                        break;

                    case 1045:
                        MessageBox.Show("Invalid username/password, please try again");
                        break;
                }
            }
        }

        private void MySqlAddClient(string _name, string _password, string _ip, MySqlConnection _connection, string _clientFName, string _clientLName, string _clientMail, string _clientPhone )  
        {
            string query = string.Format("INSERT INTO clients(Name, Password, IP) VALUES('{0}', '{1}', '{2}');", 
                _name, _password, _ip);
            MySqlCommand command = new MySqlCommand(query, _connection);
            command.ExecuteNonQuery();



            query = string.Format("SELECT id FROM clients where Name = '{0}'", _name);
            command = new MySqlCommand(query, _connection);
            int idstring = (int)command.ExecuteScalar();

            query = string.Format("INSERT INTO client_details(idClient, FirstName, LastName, MailAdress, PhoneNumber) VALUES('{0}', '{1}', '{2}','{3}','{4}');"
                , idstring, _clientFName, _clientLName, _clientMail, _clientPhone);

            command = new MySqlCommand(query, _connection);
            command.ExecuteNonQuery();
            
        }

        private bool MySqlVerifyClient(string _name, string _password, string _ip, MySqlConnection _connection)    
        {
            
            foreach (Client c in clientList)
            {
                if(_name == c.name)
                {
                    return false;
                }
            }

            string query = string.Format("SELECT count(*) FROM clients where Name = '{0}' AND Password = '{1}';", _name, _password);
            MySqlCommand command = new MySqlCommand(query, _connection);
            int aux = int.Parse(command.ExecuteScalar() + "");
            if (aux == 1)
            {

                return true;
            }
            return false;
            
        }

        private bool MySqlExistentUser(string _name, MySqlConnection _connection)
        {
            string query = string.Format("SELECT count(*) FROM clients where Name = '{0}';", _name);
            MySqlCommand command = new MySqlCommand(query, _connection);
            int aux = int.Parse(command.ExecuteScalar() + "");
            if (aux == 1)
            {
                return true;
            }
            return false;
        }

        

        #endregion

     

        private void Server_Load(object sender, EventArgs e)
        {
            try
            {

                #region MySql Connection

                MysqlFirstTimeSetup();

                string mySqlServer = "localhost"; 
                string mySqlUser = "root";
                string mySqlPassword = "teodor12";
                string mySqlDatabase = "chatterbox";
                string connectionString;
                connectionString = "SERVER=" + mySqlServer + ";" + "DATABASE=" +
                                    mySqlDatabase + ";" + "UID=" + mySqlUser + ";" + "PASSWORD=" + mySqlPassword + ";";

                mySqlConnection = new MySqlConnection(connectionString);

                ConnectToMySqlServer(mySqlConnection);
                
                #endregion

            

                #region Server Connection

                clientList = new ArrayList();
                updateStatusDelegate = new UpdateStatusDelegate(UpdateStatus);
                serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPEndPoint server = new IPEndPoint(IPAddress.Any, 30000);
                serverSocket.Bind(server);
                IPEndPoint clients = new IPEndPoint(IPAddress.Any, 0);
                EndPoint epSender = (EndPoint)clients;
                serverSocket.BeginReceiveFrom(serverDataStream, 0, serverDataStream.Length, SocketFlags.None, ref epSender, new AsyncCallback(ReceiveData), epSender);
                statusLabel.Text = "Status : Listening";

                #endregion
            }
            catch (Exception ex)
            {
                statusLabel.Text = "Error";
                MessageBox.Show("Load Error: " + ex.Message, "UDP Server", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Server_FormClosing(object sender, FormClosingEventArgs e)
        {
            mySqlConnection.Close();
        }
    }
}
