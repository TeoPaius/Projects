using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace oti
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet1.test' table. You can move, or remove it, as needed.
       
            MessageBox.Show(Properties.Resources.TextFile1);
            string[] lines = Properties.Resources.TextFile1.Split(',');
            MessageBox.Show(Convert.ToDouble(lines[2]).ToString());

            DataTable dt = new DataTable();
            DataColumn dc = new DataColumn("col1");
            DataColumn dc2 = new DataColumn("col2");
            DataColumn dc3 = new DataColumn("col3");
            database1DataSet1.test.Columns.Add("asa", typeof(int));
            //this.testTableAdapter.Fill(this.database1DataSet1.test);

            dataGridView1.DataSource = database1DataSet1.test;
            DataGridViewRow dr = new DataGridViewRow();
            r.
           

            database1DataSet1.test.rows
            
            dt.Columns.Add(dc);
            dt.Columns.Add(dc2);
            dt.Columns.Add(dc3);

            

          
          

        }
    }
}
