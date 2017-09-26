using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;

namespace Client
{
    public partial class Form1 : Form
    {

        public static TcpClient client;
        NetworkStream stream;

        public Form1()
        {
            InitializeComponent();

            string server_ip = "192.168.0.100";
            int port = 8998;

            client = new TcpClient(server_ip, port);
            stream = client.GetStream();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string text = Message_Tb.Text;
            if (text == "Kill it")
            {
                this.Close();
            }
            else if (text != "")
            {
                Message_Tb.Text = "";
                Message_Tb.Focus();
                Byte[] b = Encoding.ASCII.GetBytes(text);

                stream.Write(b, 0, b.Length);
                Chat_Tb.Text += ("Sent :" + text);
                Chat_Tb.Text += "\r\n";

                b = new Byte[256];

                String response = null;
                Int32 bytes = stream.Read(b, 0, b.Length);

                response = Encoding.ASCII.GetString(b, 0, bytes);
                Chat_Tb.Text += ("Received :" + response);
                Chat_Tb.Text += "\r\n";
            }


        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            string KillMessage = "Kill it";
            Byte[] killb = Encoding.ASCII.GetBytes(KillMessage);
            stream.Write(killb, 0, killb.Length);
           
        }
    }
}
