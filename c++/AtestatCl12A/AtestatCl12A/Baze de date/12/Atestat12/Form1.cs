using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Atestat12
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void fotbalBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.fotbalBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.database1DataSet);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Fotbal' table. You can move, or remove it, as needed.
            this.fotbalTableAdapter.Fill(this.database1DataSet.Fotbal);

        }

        private void addButton_Click(object sender, EventArgs e)
        {
            int di = (int) numericDI.Value;
            int etapa = (int) numericEtapa.Value;
            string gazde = textBoxGazda.Text;
            string oaspeti = textBoxOaspeti.Text;

            fotbalTableAdapter.InsertMeci(di, etapa, gazde, oaspeti, 0, 0);
            fotbalTableAdapter.Fill(this.database1DataSet.Fotbal);
        }

        private void sortButton_Click(object sender, EventArgs e)
        {
            fotbalTableAdapter.Sort(database1DataSet.Fotbal);
        }
    }
}
