using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Atestat11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void table1BindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.table1BindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.database1DataSet);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Table1' table. You can move, or remove it, as needed.
            this.table1TableAdapter.Fill(this.database1DataSet.Table1);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string nume = textBox2.Text;
            string partid = textBox3.Text;
            string judet = textBox4.Text;
            table1TableAdapter.InsertQuery(nume, partid, judet);
            this.table1TableAdapter.Fill(this.database1DataSet.Table1); 

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string partid = textBox5.Text;
            this.table1TableAdapter.Afisare(database1DataSet.Table1, partid);
        }
    }
}
