using System;
using System.Windows.Forms;

using System.Threading;
using System.Net;
using System.Net.Sockets;

namespace ChatClient
{
    public partial class LoginDialog : Form
    {

        #region Private Members

        private string loginName;
        private readonly AutoResetEvent _signal = new AutoResetEvent(false);
        private string loginPass;
        private EndPoint serverEp;
        private byte[] loginDataStream;
        private bool clickFlag = false;
        private Socket loginSocket;

     //   private delegate void LoginMessageDelegate(string message);
     //   private LoginMessageDelegate loginMessageDelegate = null;


        #endregion

        #region Properties
        
        public string LoginInfoPass
        {
            get { return loginPass; }
        }

        public string LoginInfoName
        {
            get { return loginName; }
        }
        public string FLoginLbl
        {
            set { fLogInLbl.Text = value; }
        }

        #endregion

        #region Constructor

        public LoginDialog()
        {
            InitializeComponent();
            BringToFront();
            Thread.Sleep(1100);

        }

        #endregion

        #region Send and Receive

        private void SendData(IAsyncResult ar)
        {
            try
            {
                loginSocket.EndSend(ar);
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("SendData :" + ex.Message, "UDP Login Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ReceiveData(IAsyncResult ar)
        {
            try
            {
                loginSocket.EndReceive(ar);

                Packet receivedData = new Packet(loginDataStream);

                if (receivedData.ChatDataIdentifier == DataIdentifier.FLogIn)
                {
                    clickFlag = true;
                    DisplayMessage(receivedData.ChatMessage);
                }
                else
                {
                    clickFlag = false;
                }
                _signal.Set();

            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("ReceivedData " + ex.Message, "Login Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion

        #region Events

        private void loginBtn_Click(object sender, EventArgs e)
        {
            loginName = userTxt.Text.Trim();
            loginPass = passTxt.Text.Trim();
            Connect();
        }

        private void DisplayMessage (string message)
        {
            fLogInLbl.Text = message;
        }

        private void exitBtn_Click(object sender, EventArgs e)
        {
            clickFlag = false;
            Close();
        }

        private void signUpLbl_Click(object sender, EventArgs e)
        {
            Visible = false;
            using (SignUpDialog signUp = new SignUpDialog())
            {
                if (signUp.ShowDialog() == DialogResult.OK)
                    userTxt.Text = signUp.LoginUser;
                else
                    Close();

            }
            Visible = true;
        }

        private void LoginDialog_Load(object sender, EventArgs e)
        {
        }

        #endregion

        #region Private Methods

        private void Connect()
        {
            Packet sendData = new Packet();
            sendData.ChatDataIdentifier = DataIdentifier.LogIn;
            sendData.ChatName = loginName + ":" + loginPass;
            sendData.ChatMessage = null;

            loginSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            IPAddress serverIp = IPAddress.Parse("192.168.0.100");
            IPEndPoint server = new IPEndPoint(serverIp, 30000);
            serverEp = (EndPoint)server;

            byte[] data = sendData.GetDataStream();
            loginSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, serverEp, new AsyncCallback(SendData), null);
            loginDataStream = new byte[1024];
            loginSocket.BeginReceiveFrom(loginDataStream, 0, loginDataStream.Length, SocketFlags.None, ref serverEp, new AsyncCallback(ReceiveData), null);
            _signal.WaitOne();
        }

        #endregion

        private void LoginDialog_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (clickFlag == true)
                e.Cancel = true;
            else
                e.Cancel = false;
        }

    }
}
