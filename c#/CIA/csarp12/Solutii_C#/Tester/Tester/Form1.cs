using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Tester
{
    public partial class Form1 : Form
    {

        //Form2 forma2 = new Form2();
        public Form1()
        {
            InitializeComponent();
            
        }

        private void lansareTestToolStripMenuItem_Click(object sender, EventArgs e)
        {
            lblNumeUtilizator.Visible = true;
            lblParola.Visible = true;
            txtNumeUtilizator.Visible = true;
            txtParola.Visible = true;
            btnLogare.Visible = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblNumeUtilizator.Visible = false;
            lblParola.Visible = false;
            txtNumeUtilizator.Visible = false;
            txtParola.Visible = false;
            btnLogare.Visible = false;
            
           
        }
        

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string nume = txtNumeUtilizator.Text.ToString();
            string parola =txtParola.Text.ToString();
            if (nume == "candidat" && parola == "cia2012")
            {
                txtNumeUtilizator.Text="";
                txtParola.Text = "";
                Form2 forma2 = new Form2();
                forma2.Show();
                
                
            }
            else
            {
                MessageBox.Show("Nume de utilizator sau parola gresita!!!\n Va rugam sa incercati din nou!");
            }
        }

        private void inchidereToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
    }
}
