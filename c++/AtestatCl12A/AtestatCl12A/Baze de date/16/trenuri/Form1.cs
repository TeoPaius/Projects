using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace trenuri
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.trenuri' table. You can move, or remove it, as needed.
            this.trenuriTableAdapter.Fill(this.database1DataSet.trenuri);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            trenuriTableAdapter.FillBy(database1DataSet.trenuri, Convert.ToInt32(textBox1.Text));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            trenuriTableAdapter.FillBy1(database1DataSet.trenuri, textBox2.Text);
        }
    }
}
