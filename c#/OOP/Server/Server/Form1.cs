using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace Server
{
    public partial class Form1 : Form
    {
        TcpListener server;
        TcpClient client;
        TcpClient client2;
        Thread ClientThread;
        Thread ClientThread2;
        Thread ListeningThread;
        Thread ListeningThread2;
        bool killed = false;
        int cnt = 0;
        public Form1()
        {

            InitializeComponent();
            ClientThread = new Thread(new ThreadStart(this.Start));
            ClientThread.IsBackground = true;
            ClientThread.Priority = ThreadPriority.Lowest;
            /*
            ClientThread2 = new Thread(new ThreadStart(this.Start));
            ClientThread2.IsBackground = true;
            ClientThread2.Priority = ThreadPriority.Lowest;
            */
            ListeningThread = new Thread(new ThreadStart(Listening));     
            ListeningThread.Priority = ThreadPriority.Lowest;
            //ListeningThread.IsBackground = true;
/*
            ListeningThread2 = new Thread(new ThreadStart(Listening));
            ListeningThread2.Priority = ThreadPriority.Lowest;
           ListeningThread2.IsBackground = true;
*/
            textBox1.Text += "Listening Started";
            textBox1.Text += "\r\n";
            int port = 8998;
            IPAddress ip = IPAddress.Parse("192.168.0.100");

            server = new TcpListener(IPAddress.Any, port);
            server.Start();

            ListeningThread.Start();
            //ListeningThread2.Start();
            //this.Activate();


        }

        public void Listening()
        {
            while (true)
            {
                
                client = server.AcceptTcpClient();
                NetworkStream stream = client.GetStream();

                


                textBox1.Text += '\n';
                textBox1.Text += "Client Connected" + "\r\n";

                ClientThread = new Thread(new ThreadStart(Start));
                ClientThread.Start();
            }
        }

        public void Start()
        {
            

            Byte[] b = new Byte[256];
            string data = null;

            while (true)
            {
                /*
            client = server.AcceptTcpClient();
            
            textBox1.Text += '\n';
            textBox1.Text += "Connected" + "\r\n";
            */
            NetworkStream stream = client.GetStream();

            int i;
            while (stream.CanRead)
            {
                    i = stream.Read(b, 0, b.Length);
                data = System.Text.Encoding.ASCII.GetString(b, 0, i);
                    if (data == "Kill it")
                    
                    {
                        client.Close();
                       // server.Stop();
                        textBox1.Text += "Client Disconnected";
                        textBox1.Text += "\r\n";
                        ClientThread.Abort();
                       
                    }
                textBox1.Text += String.Format("Received {0}", data);
                textBox1.Text += "\r\n";

                data = data.ToUpper();
                byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);
                stream.Write(msg, 0, msg.Length);

                textBox1.Text += String.Format("Sent {0}", data);
                textBox1.Text += "\r\n";
                 
            }

             }
            System.Threading.Thread.Sleep(100);
        }
    
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
          

            killed = true;

            server.Stop();
            if(ClientThread.IsAlive)
                ClientThread.Abort();
            ListeningThread.Abort();

        }

        
    }
}
