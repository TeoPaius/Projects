using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BazaDeDataS21
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'databaseDataSet.TabelAnimale' table. You can move, or remove it, as needed.
            this.tabelAnimaleTableAdapter.Fill(this.databaseDataSet.TabelAnimale);

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if(txtGreutate.Text=="" || txtSpecia.Text=="")
            { MessageBox.Show("Completarea casutelor este obligatorie"); return; }
            float x;
            bool ok = float.TryParse(txtGreutate.Text, out x);
            if(ok)
            {
                tabelAnimaleTableAdapter.InsertQuery(txtSpecia.Text, sexCB.Checked, dtpDataNasterii.Value.ToString(), float.Parse(txtGreutate.Text));
                tabelAnimaleTableAdapter.Fill(databaseDataSet.TabelAnimale);
            }
            else { MessageBox.Show("Greutatea nu este in format corespunzator"); }
            
        }

        private void sortBtn_Click(object sender, EventArgs e)
        {
            tabelAnimaleTableAdapter.FillBy(databaseDataSet.TabelAnimale);
        }
    }
}
