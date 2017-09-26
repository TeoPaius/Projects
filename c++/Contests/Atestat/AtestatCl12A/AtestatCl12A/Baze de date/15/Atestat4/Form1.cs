using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;

namespace Atestat4
{
    public partial class Form1 : Form
    {
        SqlConnection conn;

        public Form1()
        {
            InitializeComponent();
            
           

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Albume' table. You can move, or remove it, as needed.
            this.albumeTableAdapter.Fill(this.database1DataSet.Albume);

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            this.albumeTableAdapter.InsertQuery(textBox1.Text, textBox2.Text, Convert.ToInt32(textBox3.Text), textBox4.Text);
            this.albumeTableAdapter.Fill(this.database1DataSet.Albume);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.albumeTableAdapter.FillBy(this.database1DataSet.Albume, Convert.ToInt32(textBox5.Text));
        }
    }
}
