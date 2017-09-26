using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
            char[] a = new char[] { '1', '2' };
            string x = new string(a);
            
            x = Properties.Resources.TextFile1.ToString();
            //MessageBox.Show(x);

            Graphics gr = this.CreateGraphics();
            // gr.DrawEllipse(new Pen(Color.Red), 0, 0, this. Width, this.Height);
            PaintEventArgs er = new PaintEventArgs(gr, ClientRectangle);
            OnPaint(er);
            timer1.Start();
            dataGridView1.Rows[0].Cells[0].Value = 2;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawEllipse(new Pen(Color.Red),this.ClientRectangle);
       
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Graphics gr = this.CreateGraphics();
            // gr.DrawEllipse(new Pen(Color.Red), 0, 0, this. Width, this.Height);
            PaintEventArgs er = new PaintEventArgs(gr, ClientRectangle);
     


        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            pictureBox1.Location = new Point(pictureBox1.Location.X + 1, pictureBox1.Location.Y);
        }
    }
}
