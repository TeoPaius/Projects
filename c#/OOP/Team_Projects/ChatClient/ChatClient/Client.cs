using System;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
using System.Diagnostics;
using System.Threading;

namespace ChatClient
{
    public partial class Client : Form
    {
        #region Private Members

        private Socket clientSocket;
        private string clientName;
        private EndPoint serverEp;
        private byte[] clientDataStream;
        private string clientPass;
      
        private delegate void DisplayMessageDelegate(string message);
        private DisplayMessageDelegate displayMessageDelegate = null;

        #endregion

        #region Public Properties
        public Socket ClientSocket
        {
            get { return clientSocket; }
            set { clientSocket = value; }
        }

        public EndPoint ServerEp
        {
            get { return serverEp; }
            set { serverEp = value; }
        }
        

        public string ClientName
        {
            get { return clientName; }
            set { clientName = value; }
        }

        public string ClientPass
        {
            set { clientPass = value; }
        }
        #endregion

        #region Constructor

        public Client()
        {
            InitializeComponent();
            this.BringToFront();
        }

        public Client(string _clientName)
        {
            InitializeComponent();
            clientName = _clientName;
            BringToFront();
        }

        #endregion

        #region Events

        private void sendBtn_Click(object sender, EventArgs e)
        {
            try
            {
                Packet sendData = new Packet();
                sendData.ChatName = clientName;
                sendData.ChatMessage = messageText.Text.Trim();
                sendData.ChatDataIdentifier = DataIdentifier.Message;

                byte[] byteData = sendData.GetDataStream();
                clientSocket.BeginSendTo(byteData, 0, byteData.Length, SocketFlags.None, serverEp, new AsyncCallback(SendData), null);
                messageText.Text = string.Empty;
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Send Error : " + ex.Message, "UDP Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void Client_FormClosing(object sender, FormClosingEventArgs e)
        {
            
            try
            {
                if (clientSocket != null)
                {
                    Packet sendData = new Packet();

                    sendData.ChatDataIdentifier = DataIdentifier.LogOut;
                    sendData.ChatName = clientName;
                    sendData.ChatMessage = null;

                    byte[] byteData = sendData.GetDataStream();

                    clientSocket.SendTo(byteData, 0, byteData.Length, SocketFlags.None, serverEp);

                    clientSocket.Close();
                }
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Closing Error : " + ex.Message, "UDP Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void exitBtn_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Client_Load(object sender, EventArgs e)
        {
            userLbl.Text = "Logged in as " + clientName;
            Connect();
            displayMessageDelegate = new DisplayMessageDelegate(DisplayMessage);
        }

        #endregion

        #region Send And Receive

        private void SendData(IAsyncResult ar)
        {
            try
            {
                clientSocket.EndSend(ar);
                //Debug.WriteLine("Send data in client");
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Send Data : " + ex.Message, "UDP Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ReceiveData(IAsyncResult ar)
        {
            try
            {
                clientSocket.EndReceive(ar);
                Packet receivedData = new Packet(clientDataStream);

                Debug.WriteLine(receivedData.ChatDataIdentifier + " " + receivedData.ChatName + " " + receivedData.ChatMessage);

                if (receivedData.ChatMessage != null)
                    Invoke(displayMessageDelegate, new object[] { receivedData.ChatMessage });

                clientDataStream = new byte[1024];

                clientSocket.BeginReceiveFrom(clientDataStream, 0, clientDataStream.Length, SocketFlags.None, ref serverEp, new AsyncCallback(ReceiveData), null);

            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Receive Data : " + ex.Message, "UDP Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion

        #region Private Methods

        private void DisplayMessage(string message)
        {
            chatText.Text += message + Environment.NewLine;
            
        }

        private void Connect()
        {
            try
            {
                Packet sendData = new Packet();
                sendData.ChatDataIdentifier = DataIdentifier.Online;
                sendData.ChatName = clientName;
                sendData.ChatMessage = null;

                clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPAddress serverIp = IPAddress.Parse("192.168.0.100");
                IPEndPoint server = new IPEndPoint(serverIp, 30000);
                serverEp = (EndPoint)server;

                byte[] data = sendData.GetDataStream();
                clientSocket.Connect(serverEp);
                clientSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, serverEp, new AsyncCallback(SendData), null);
                clientDataStream = new byte[1024];
                clientSocket.BeginReceiveFrom(clientDataStream, 0, clientDataStream.Length, SocketFlags.None, ref serverEp, new AsyncCallback(ReceiveData), serverEp);
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Connection Error : " + ex.Message, "UDP Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion

    }
}
