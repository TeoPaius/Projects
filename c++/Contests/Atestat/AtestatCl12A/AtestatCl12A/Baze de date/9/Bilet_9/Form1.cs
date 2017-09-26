using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bilet_9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dataSet1.Tren' table. You can move, or remove it, as needed.
            this.trenTableAdapter.Fill(this.dataSet1.Tren);

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            trenTableAdapter.SelectTip(dataSet1.Tren, textBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            trenTableAdapter.DestSelect(dataSet1.Tren, textBox2.Text);
        }
    }
}
