using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private int time = 0;
        private int cnt = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            time += 1;
            label4.Text = string.Format("{0}", time);
            p1.PerformStep();
            if (time == 30)
            {
                timer1.Stop();
                p1.Enabled = false;
            }

        }

        private void button4_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            if (time == 30)
            {
                time = 0;
                p1.Value = 0;
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            p1.Enabled = false;
            if (time == 30)
            {
                time = 0;
                p1.Value = 0;
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (textBox1.Text == "Buhai")
                {
                    textBox2.Enabled = true;
                    label3.Enabled = true;
                    groupBox1.Enabled = true;

                }
                else
                {
                    MessageBox.Show("Mai incearca");
                }
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(textBox1.Text + " " + textBox2.Text + " " + 15);
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(textBox1.Text + " " + textBox2.Text + " " + 16);
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(textBox1.Text + " " + textBox2.Text + " " + 17);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pb1.Image = imageList1.Images[cnt % 3]; 
            cnt++;
        }

      
       
        
    }
}
