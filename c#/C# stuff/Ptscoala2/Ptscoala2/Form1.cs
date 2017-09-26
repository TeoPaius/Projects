using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ptscoala2
{
    public partial class x : Form
    {
        private int time = 0;
        public x()
        {
            InitializeComponent();
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            time += 1;
            progressBar1.PerformStep();
            if (time == 100)
            {
                time = 0;
                timer1.Stop();
                progressBar1.Enabled = false;
                MessageBox.Show("Instalare reusita");
                
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            Application.UseWaitCursor = true;
            if (time == 100)
            {
                Application.UseWaitCursor = false;
                time = 0;
                progressBar1.Value = 0;
            }
        }

        
        private void button2_Click(object sender, EventArgs e)
        {
            Application.UseWaitCursor = false;
            time = 0;
            timer1.Stop();
            progressBar1.Enabled = false;
            MessageBox.Show("Instalare oprita \nPuteti continua instalarea mai tarziu");

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                button1.Enabled = true;
            }
            else
                button1.Enabled = false;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

  
       
    }
}
