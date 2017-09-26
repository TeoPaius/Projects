using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Test2' table. You can move, or remove it, as needed.
            this.test2TableAdapter.Fill(this.database1DataSet.Test2);


        }

        private void button1_Click(object sender, EventArgs e)
        {
            test2TableAdapter.Insert(textBox1.Text, textBox2.Text);
            test2TableAdapter.Fill(database1DataSet.Test2);
        }
    }
}
