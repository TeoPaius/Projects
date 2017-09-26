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

        private void addBtn_Click(object sender, EventArgs e)
        {
            tabelTableAdapter.Insert(numeTB.Text, int.Parse(blocTB.Text),
                int.Parse(apTB.Text), angTB.Checked);
            if (angBtn.Text == "Locatari angajati")
                tabelTableAdapter.Fill(this.dataSet.Tabel);
            else
                tabelTableAdapter.Angajati(dataSet.Tabel);
                
        }

        private void angBtn_Click(object sender, EventArgs e)
        {
            if ( angBtn.Text == "Locatari angajati")
            {
                tabelTableAdapter.Angajati(dataSet.Tabel);
                angBtn.Text = "Toti locatarii";
            }
            else
            {
                this.tabelTableAdapter.Fill(this.dataSet.Tabel);
                angBtn.Text = "Locatari angajati";
            }
        }
    }
}
