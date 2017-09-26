using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiectul1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dataSet.Tabel' table. You can move, or remove it, as needed.
            this.tabelTableAdapter.Fill(this.dataSet.Tabel);

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            tabelTableAdapter.InsertQuery(int.Parse(textBoxISBN.Text), 
                textBoxAutor.Text, textBoxTitlu.Text, int.Parse(textBoxAn.Text),
                int.Parse(textBoxAn.Text));
            tabelTableAdapter.Fill(this.dataSet.Tabel);

        }

        private void buttonAfis_Click(object sender, EventArgs e)
        {
            tabelTableAdapter.FillBy2(this.dataSet.Tabel, int.Parse(textBoxAfis.Text));
        }
    }
}
