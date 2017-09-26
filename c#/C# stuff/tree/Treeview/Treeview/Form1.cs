using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Treeview
{
    public partial class Form1 : Form
    {
        string a;

        public Form1()
        {
            InitializeComponent();
            Image a = Image.FromFile("Texture-Background-Dark-Spot-HD.jpg");
            Bitmap aux = new Bitmap(a, new Size(this.Height, this.Width));
            this.BackgroundImage = aux;
            timer1.Start();
        }

      

        private void button1_Click(object sender, EventArgs e)
        {
            if (pictureBox1.BackgroundImage != null)
            {
                Bitmap a = new Bitmap(pictureBox1.BackgroundImage);
                a.RotateFlip(RotateFlipType.Rotate90FlipNone);
                Bitmap b = new Bitmap(a);
                pictureBox1.BackgroundImage = b;
            }
        }




        //private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        //{
        //    if (treeView1.SelectedNode.LastNode == null)
        //    {
        //        a = treeView1.SelectedNode.Name;
        //        a += ".jpg";
        //        Image img = Image.FromFile(Path.Combine(Environment.CurrentDirectory, a));
        //        Bitmap b = new Bitmap(img, new Size(pictureBox1.Height, pictureBox1.Width));
        //        pictureBox1.BackgroundImage = b;
        //    }
        //    else
        //    {
        //        pictureBox1.BackgroundImage = null;
        //    }
        ////}

      

        private void treeView1_NodeMouseDoubleClick_1(object sender, TreeNodeMouseClickEventArgs e)
        {
            if (treeView1.SelectedNode.Nodes.Count == 0)
            {
                a = treeView1.SelectedNode.Name;
                a += ".jpg";
                Image img = Image.FromFile(Path.Combine(Environment.CurrentDirectory, a));
                Bitmap b = new Bitmap(img, new Size(pictureBox1.Height, pictureBox1.Width));
                pictureBox1.BackgroundImage = b;
            }
            else
            {
                pictureBox1.BackgroundImage = null;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.BackgroundImage = null;
            Form2 a = new Form2();
            a.Show();
            this.Close();
            
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                treeView1.Visible = true;
                button1.Visible = true;
                button2.Visible = true;
                pictureBox1.BackgroundImage = null;
                label3.Visible = false;
            }
            else
            {
                treeView1.Visible = false;
                pictureBox1.BackgroundImage = null;
            }
            timer1.Stop();
        }

        int cnt = 10;
        private void timer1_Tick(object sender, EventArgs e)
        {
            cnt--;
            label2.Text = cnt.ToString();
            if (cnt == 5)
            {
                label3.Visible = true;
            }
            
            if (cnt == 0)
            {
                pictureBox1.BackgroundImage = null;
                Form2 a = new Form2();
                a.Show();
                this.Close();
                
            }
            if (cnt == 3)
            {
                label2.Visible = false;
                Image aux1 = Image.FromFile("download (1).jpg");
                Bitmap b1 = new Bitmap(aux1, new Size(pictureBox1.Height, pictureBox1.Width));
                pictureBox1.BackgroundImage = b1;
            }
            if (cnt == 2)
            {
                Image aux2 = Image.FromFile("download (2).jpg");
                Bitmap b2 = new Bitmap(aux2, new Size(pictureBox1.Height, pictureBox1.Width));
                pictureBox1.BackgroundImage = b2;
            }
            if (cnt == 1)
            {
                Image aux3 = Image.FromFile("download (3).jpg");
                Bitmap b3 = new Bitmap(aux3, new Size(pictureBox1.Height, pictureBox1.Width));
                pictureBox1.BackgroundImage = b3;
            }
          
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Image a = Image.FromFile("Texture-Background-Dark-Spot-HD.jpg");
            Bitmap aux = new Bitmap(a, new Size(this.Height, this.Width));
            this.BackgroundImage = aux;
        }

       


        

        

        
    }
}
