using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Tester
{
    public partial class Form2 : Form
    {
        int k = 0;
        int total;
        int[] a = new int[50];
        int[] b = new int[50];
        int finalizare = 0;
        int nrLinii;
        FileStream fisier;
        
        List<string> lines = new List<string>();
        int i = 0;
        public Form2()
        {
            InitializeComponent();
        }

        private void btnFinalizare_Click(object sender, EventArgs e)
        {
             if (finalizare == 0)
             {
                 for (int k = 0; k < nrLinii; k++)
                     if (a[k] == b[k] && a[k] != 0 && b[k] != 0 || (a[k]==5 && b[k]==5))
                         total += 10;
                lblAfisare.Text = "Ati obtinut " + total.ToString() + " puncte";
                 btnAnterior.Visible = false;
                 btnUrmator.Visible = false;
                 finalizare = 1;
             }
             else
             {
                 System.Windows.Forms.MessageBox.Show("Acesta operatie a fost executata!!! Selectati botonul Inchidere");
                 
             }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
            OpenFileDialog dlgOpenFile = new OpenFileDialog();
            dlgOpenFile.Filter = "Text Files (*.txt)|*.txt";
            dlgOpenFile.Title = "Type File";
            if (dlgOpenFile.ShowDialog() == DialogResult.Cancel)
            {
                this.Close();
                return;
            }
            
            else
            {
                try
                {
                    fisier = new FileStream(dlgOpenFile.FileName, FileMode.Open, FileAccess.Read);
                }
                catch (Exception)
                {
                    MessageBox.Show("Eroare la deschiderea fisierului", "Eroare fisier", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);

                }

            }
            Initializare();
            using (StreamReader r = new StreamReader(fisier))
            {
                string line;
                while ((line = r.ReadLine()) != null)
                {
                    lines.Add(line);
                }
                r.Close();
            }
            nrLinii = lines.Count/8;

            txtIntrebare.Text = lines[0].ToString();
            int tip = Convert.ToInt32(lines[7]);
            for (int j = 0; j < 4; j++)
            {
                if (tip == 0)
                {
                    RadioButton rbButon = new RadioButton();
                    rbButon.Location = new Point(25, j * 35);
                    rbButon.Size =new Size(150,17);
                    rbButon.Text = lines[j + 1].ToString();
                    pnlRaspunsuri.Controls.Add(rbButon);
                }
                if (tip == 1)
                {
                    CheckBox chkButon = new CheckBox();
                    chkButon.Location = new Point(25, j * 35);
                    chkButon.Size = new Size(150, 17);
                    chkButon.Text = lines[j + 1].ToString();
                    pnlRaspunsuri.Controls.Add(chkButon);
                }
            }

        }

        private void btnAnterior_Click(object sender, EventArgs e)
        {
            i = i - 8;
            if (i >= 0 && i < lines.Count)
            {
                pnlRaspunsuri.Controls.Clear();
                Raspunsuri();
                k--;

            }
            else
            {

                MessageBox.Show("Sunteti pe prima inregistrare!!");
                i = i + 8;
            }
        }

        private void btnUrmator_Click(object sender, EventArgs e)
        {
            i = i + 8;
            if (i > 0 && i < lines.Count)
            {
                pnlRaspunsuri.Controls.Clear();
                Raspunsuri();
                //i=i+8;
                k++;
            }
            else
            {

                MessageBox.Show("Sunteti pe ultima inregistrare!!");
                i = i - 8;
            }
        }
        public void Raspunsuri()
        {

            txtIntrebare.Text = lines[i].ToString();
            int tip = Convert.ToInt32(lines[i + 7]);
          
            for (int j = 0; j < 4; j++)
            {
                if (tip == 0)
                {
                    RadioButton rbButon = new RadioButton();
                    rbButon.Location = new Point(25, j * 35);
                    rbButon.Size = new Size(150, 17);
                    rbButon.Text = lines[i + 1 + j].ToString();
                    pnlRaspunsuri.Controls.Add(rbButon);
                }
                if (tip == 1)
                {
                    CheckBox chkButon = new CheckBox();
                    chkButon.Location = new Point(25, j * 35);
                    chkButon.Size = new Size(150, 17);
                    chkButon.Text = lines[i + 1 + j].ToString();
                    pnlRaspunsuri.Controls.Add(chkButon);
                }
            }
        }

        private void btnValidare_Click(object sender, EventArgs e)
        {
            a[k] = b[k]=0;
                string ind = lines[i+5].ToString();
                string[] c = ind.Split(',');
                
                string puncte = lines[i + 6].ToString();
                
                foreach (Control ctlControl in pnlRaspunsuri.Controls)
                {
                    if (ctlControl is RadioButton)
                    {
                        RadioButton rb = (RadioButton)ctlControl;
                        if (rb.Checked )
                        {
                            if (rb.TabIndex == Convert.ToInt32(ind) - 1)
                            {
                                a[k] = rb.TabIndex + 1;
                                b[k] = Convert.ToInt32(ind);
                            }
                        }

                    }
                    if(ctlControl is CheckBox)
                    {
                    CheckBox chk =(CheckBox)ctlControl;
                    if (chk.Checked)
                    { 
                        if (chk.TabIndex == Convert.ToInt32(c[0]) - 1 || chk.TabIndex == Convert.ToInt32(c[1]) - 1)
                        {
                            
                            a[k] = 5;
                            b[k] = 5;
                            
                        }
                    }
                    
                    }
                }
        }

        public void Initializare()
        {
            for (int j = 0; j < nrLinii; j++)
                a[j] = b[j] = 0;
            i = 0;
        }

        private void btnInchidere_Click(object sender, EventArgs e)
        {
            this.Close();
            
        }

    }
}
