using System;
using System.Drawing;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using System.Diagnostics;
using System.Threading;

namespace ChatClient
{
    public partial class SignUpDialog : Form
    {
        #region Private Members

        private WaterMarkTextBox usernameTextBox;
        private WaterMarkTextBox passwordTextBox;
        private WaterMarkTextBox firstNameTextBox;
        private WaterMarkTextBox lastNameTextBox;
        private WaterMarkTextBox mailTextBox;
        private WaterMarkTextBox phoneTextBox;
        private bool verify = false;
        private Socket signSocket;
        private byte[] signDataStream;
        private EndPoint serverEp;
        private readonly AutoResetEvent _signal = new AutoResetEvent(false);
        private bool clickFlag = false;
        private string loginUser;

        #endregion

        #region SignUp Info

        private string username;
        private string password;
        private string firstName;
        private string lastName;
        private string mail;
        private string phone;
        private Label failLabel;

        #endregion

        #region Properties

        public string LoginUser
        {
            get { return loginUser; }
        }

        public bool Verify
        {
            get { return verify; }
        }

        #endregion

        #region Constructor

        public SignUpDialog()
        {

            InitializeComponent();
            this.ActiveControl = sendButton;

            #region Initializations

            failLabel = new Label();
            failLabel.Anchor = (AnchorStyles.Left | AnchorStyles.Right);
            failLabel.TextAlign = ContentAlignment.MiddleLeft;
            failLabel.Text = "failLabel";

            #endregion

            #region Textbox creation and positioning

            usernameTextBox = new WaterMarkTextBox("Username*");
            passwordTextBox = new WaterMarkTextBox("Password*");
            firstNameTextBox = new WaterMarkTextBox("First Name");
            lastNameTextBox = new WaterMarkTextBox("Last Name");
            mailTextBox = new WaterMarkTextBox("Mail Address*");
            phoneTextBox = new WaterMarkTextBox("Phone Number");

            passwordTextBox.PasswordChar = '*';
            passwordTextBox.IsPassword = true;

            phoneTextBox.IsNumber = true;


            flowLayoutPanel1.Controls.Add(usernameTextBox);
            flowLayoutPanel1.Controls.Add(passwordTextBox);
            flowLayoutPanel1.Controls.Add(failLabel);


            flowLayoutPanel2.Controls.Add(firstNameTextBox);
            flowLayoutPanel2.Controls.Add(lastNameTextBox);
            flowLayoutPanel2.Controls.Add(mailTextBox);
            flowLayoutPanel2.Controls.Add(phoneTextBox);



            #endregion
        }

        #endregion

        public string GetInfo()
        {
            string info =  password + '%' + firstName + '%' + lastName + '%' + mail + '%' + phone;
            return info;
        }  // pass % fname % lname % mail % phone

        class WaterMarkTextBox : TextBox
        {

            #region Private Members

            private Font oldFont = null;
            private bool waterMarkEnabled = false;
            private string waterText = "text";
            private Color waterMarkColor = Color.Gray;
            private Size defaultSize = new Size(100, 10);
            private bool isNumber;
            private bool isPassword;
            private bool nonNumberPressed;



            #endregion

            #region Properties

            public bool IsPassword
            {
                set { isPassword = value; }
                get { return isPassword; }
            }

            public bool IsNumber
            {
                set { isNumber = value; }
                get { return isNumber; }
            }

            public string WaterText
            {
                set { waterText = value; }
            }
            #endregion

            #region Events

            protected override void OnCreateControl()
            {
                base.OnCreateControl();
                WaterMarkToggle(null, null);
            }

            protected override void OnPaint(PaintEventArgs e)
            {
                Font drawFont = new Font(Font.FontFamily,
                Font.Size, Font.Style, Font.Unit);

                SolidBrush drawBrush = new SolidBrush(waterMarkColor);
                if (Text != "")
                {
                    
                    drawBrush = new SolidBrush(Color.Black);
                    if (isPassword)
                    {
                        e.Graphics.DrawString(new string('*', Text.Length),
                        drawFont, drawBrush, new PointF(0.0F, 0.0F));
                    }
                    else
                    {
                    e.Graphics.DrawString(Text,
                    drawFont, drawBrush, new PointF(0.0F, 0.0F));
                }
                }
                else if (Text == "")
                {
                    e.Graphics.DrawString(waterText,
                    drawFont, drawBrush, new PointF(0.0F, 0.0F));
                    
                }
                
                base.OnPaint(e);
            }

 

            private void JoinEvents(bool join)
            {
                this.TextChanged += new EventHandler(WaterMarkToggle);
                this.LostFocus += new EventHandler(WaterMarkToggle);
                this.GotFocus += new EventHandler(WaterMarkToggle);
                this.KeyDown += new KeyEventHandler(KeyPressFilter);
                this.KeyPress += new KeyPressEventHandler(KeyPressAccept);
                //this.Enter += new System.EventHandler(WaterMarkToggle);
               // this.Leave += new System.EventHandler(WaterMarkToggle);
                //this.MouseMove += new System.Windows.Forms.MouseEventHandler(WaterMarkToggle);
            }

            #endregion

            #region Constructor

            public WaterMarkTextBox()
            {
                JoinEvents(true);
                Size = defaultSize;
            }

            public WaterMarkTextBox(string _text)
            {
                waterText = _text;
                JoinEvents(true);
                Size = defaultSize;
                
            }

            
            #endregion

            private void KeyPressAccept(object sender, KeyPressEventArgs args)
            {
                if (nonNumberPressed)
                    args.Handled = true;
            }

            private void KeyPressFilter(object sender, KeyEventArgs args)
            {
                nonNumberPressed = false;
                if (IsNumber)
                {
                    if (args.KeyCode < Keys.D0 || args.KeyCode > Keys.D9)
                        if (args.KeyCode < Keys.NumPad0 || args.KeyCode > Keys.NumPad9)
                            if (args.KeyCode != Keys.Back)
                            {
                                nonNumberPressed = true;
                                
                            }
                }
            }

            private void WaterMarkToggle(object sender, EventArgs args)
            {
                if (this.Text.Length <= 0)
                {

                    EnableWaterMark();
                }
                else
                    DisableWaterMark();
                Refresh();
            }

            private void EnableWaterMark()
            {
                this.SetStyle(ControlStyles.UserPaint, true);
                waterMarkEnabled = true;
                Refresh();
            }

            private void DisableWaterMark()
            {
                if (Text == "")
                    Text = "UserName";

            }
        }

        #region Private Methods
        
        private void SendData(IAsyncResult ar)
        {
            try
            {
                signSocket.EndSend(ar);
                //Debug.WriteLine("Send");
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error while sending data" + ex.Message, "SignUpDialog", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ReceiveData(IAsyncResult ar)
        {
            try
            {
                signSocket.EndReceive(ar);

                Packet receiveData = new Packet(signDataStream); 

                if (receiveData.ChatDataIdentifier == DataIdentifier.FSignUp)
                {
                    clickFlag = true;
                    LabelIncorrect();
                    //Debug.WriteLine("Receive");
                }
                else
                {
                    clickFlag = false;
                    loginUser = receiveData.ChatName;
                    MessageBox.Show("You Have Successfully Signed Up.", "Succes Sign Up", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    // verify = true;
                }
                //signSocket.BeginReceiveFrom(signDataStream, 0, signDataStream.Length, SocketFlags.None, ref serverEp, new AsyncCallback(ReceiveData), null);
                //Debug.WriteLine("Receive");
                _signal.Set();
            }
            catch (ObjectDisposedException ex)
            {

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error while sending data" + ex.Message, "SignUpDialog", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void LabelIncorrect()
        {
            failLabel.ForeColor = Color.Red;
            failLabel.Text = "Username Incorrect or Already in use !";
        }

        private void sendButton_Click(object sender, EventArgs es)
        {
            clickFlag = true;
            username = usernameTextBox.Text;
            password = passwordTextBox.Text;
            firstName = firstNameTextBox.Text;
            lastName = lastNameTextBox.Text;
            mail = mailTextBox.Text;
            phone = phoneTextBox.Text;

            if (username == "" || password == "" || mail == "" || firstName == "" || lastName == "" )
            {
                errorLabel.Visible = true;
            }
            else
            {
                Packet sendData = new Packet();
                sendData.ChatDataIdentifier = DataIdentifier.SignUp;
                sendData.ChatName = username;
                sendData.ChatMessage = GetInfo();
                signSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPAddress serverIp = IPAddress.Parse("192.168.0.100");
                IPEndPoint server = new IPEndPoint(serverIp, 30000);
                serverEp = (EndPoint)server;

                byte[] data = sendData.GetDataStream();
                signSocket.BeginSendTo(data, 0, data.Length, SocketFlags.None, serverEp, new AsyncCallback(SendData), null);
                signDataStream = new byte[1024];
                //Debug.WriteLine("Begin Receive");
                signSocket.BeginReceiveFrom(signDataStream, 0, signDataStream.Length, SocketFlags.None, ref serverEp, new AsyncCallback(ReceiveData), null);
                _signal.WaitOne();

            }
            //Debug.WriteLine("ButtonClicked");
        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        #endregion

        private void SignUpDialog_FormClosing(object sender, FormClosingEventArgs e)
        {
            //Debug.WriteLine("Clooossinnggg");
            if (clickFlag == true)
                e.Cancel = true;
            else
                e.Cancel = false;
        }

        private void SignUpDialog_Load(object sender, EventArgs e)
        {
            failLabel.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            clickFlag = false;
            Close();
        }
    }

}
