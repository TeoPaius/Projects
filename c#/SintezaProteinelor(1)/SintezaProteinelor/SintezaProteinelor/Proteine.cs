using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SintezaProteinelor
{
    public partial class Proteine : Form
    {
        //private int[, ,] p = new int[4, 4, 4];
        private string Adn;
        private string AN;


        private string ARNmADN(string x)
        {
            string aux = x;
            switch (x)
            {
                case "a":
                    aux = "T";
                    break;
                case "u":
                    aux = "A";
                    break;
                case "g":
                    aux = "C";
                    break;
                case "c":
                    aux = "G";
                    break;
            }

            return aux;
        }

        private string ARNmARNt(string x)
        {
            string aux = null;
            switch (x)
            {
                case "a":
                    aux += "U";
                    break;
                case "t":
                    aux += "A";
                    break;
                case "u":
                    aux += "A";
                    break;
                case "g":
                    aux += "C";
                    break;
                case "c":
                    aux += "G";
                    break;
            }

            return aux;
        }

        private void ANConvert()
        {
            string x;
            int leng = 0;
            while (leng <= arnmTxt.Text.Length - 3)
            {
                x = arnmTxt.Text.Substring(leng, 3);

                leng += 3;
                switch (x)
                {
                    case ("UUU"):
                        AN += "Fenilalanina "; break;
                    case ("UUC"):
                        AN += "Fenilalanina "; break;
                    case ("UUA"):
                        AN += "Leucină "; break;
                    case ("UUG"):
                        AN += "Leucina "; break;
                    case ("CUU"):
                        AN += "Leucina "; break;
                    case ("CUC"):
                        AN += "Leucina "; break;
                    case ("CUA"):
                        AN += "Leucina "; break;
                    case ("CUG"):
                        AN += "Leucina "; break;
                    case ("AUU"):
                        AN += "Isoleucina "; break;
                    case ("AUC"):
                        AN += "Isoleucina "; break;
                    case ("AUA"):
                        AN += "Isoleucina "; break;
                    case ("AUG"):
                        AN += "Metionina "; break;
                    case ("GUU"):
                        AN += "Valina "; break;
                    case ("GUC"):
                        AN += "Valina "; break;
                    case ("GUA"):
                        AN += "Valina "; break;
                    case ("GUG"):
                        AN += "Valina "; break;
                    case ("UCU"):
                        AN += "Serina "; break;
                    case ("UCC"):
                        AN += "Serina "; break;
                    case ("UCA"):
                        AN += "Serina "; break;
                    case ("UCG"):
                        AN += "Serina "; break;
                    case ("CCU"):
                        AN += "Prolină "; break;
                    case ("CCC"):
                        AN += "Prolină "; break;
                    case ("CCA"):
                        AN += "Prolină "; break;
                    case ("CCG"):
                        AN += "Prolină "; break;
                    case ("ACU"):
                        AN += "Treonina "; break;
                    case ("ACC"):
                        AN += "Treonina "; break;
                    case ("ACA"):
                        AN += "Treonina "; break;
                    case ("ACG"):
                        AN += "Treonina "; break;
                    case ("GCU"):
                        AN += "Alanină "; break;
                    case ("GCC"):
                        AN += "Alanină "; break;
                    case ("GCA"):
                        AN += "Alanină "; break;
                    case ("GCG"):
                        AN += "Alanină "; break;
                    case ("UAC"):
                        AN += "Tirosină "; break;
                    case ("UAA"):
                        AN += "STOP "; break;
                    case ("UAU"):
                        AN += "STOP "; break;
                    case ("CAU"):
                        AN += " Histidină "; break;
                    case ("CAC"):
                        AN += " Histidină "; break;
                    case ("CAA"):
                        AN += "Glutamină "; break;
                    case ("CAG"):
                        AN += "Glutamină "; break;
                    case ("AAU"):
                        AN += "Asaragină "; break;
                    case ("AAC"):
                        AN += "Asparagină "; break;
                    case ("AAA"):
                        AN += "Lisină "; break;
                    case ("AAG"):
                        AN += "Lisină "; break;
                    case ("GAU"):
                        AN += "Asparaginază "; break;
                    case ("GAC"):
                        AN += "Asparaginază "; break;
                    case ("GAA"):
                        AN += "Acid glutamic "; break;
                    case ("GAG"):
                        AN += "Acid glutamic "; break;
                    case ("UGU"):
                        AN += "Cisteină "; break;
                    case ("UGC"):
                        AN += "Cisteină "; break;
                    case ("UGA"):
                        AN += "STOP "; break;
                    case ("UGG"):
                        AN += "Triptofan "; break;
                    case ("CGU"):
                        AN += "Arginină "; break;
                    case ("CGC"):
                        AN += "Arginină "; break;
                    case ("CGA"):
                        AN += "Arginină "; break;
                    case ("CGG"):
                        AN += "Arginină "; break;
                    case ("AGU"):
                        AN += "Serină "; break;
                    case ("AGC"):
                        AN += "Serină "; break;
                    case ("AGA"):
                        AN += "Arginină "; break;
                    case ("AGG"):
                        AN += "Arginină "; break;
                    case ("GGU"):
                        AN += "Glicină "; break;
                    case ("GGC"):
                        AN += "Glicină "; break;
                    case ("GGA"):
                        AN += "Glicină "; break;
                    case ("GGG"):
                        AN += "Glicină "; break;
                }
            }

        }
        public Proteine()
        {
            InitializeComponent();
        }

        private void trsBtn_Click(object sender, EventArgs e)
        {
            ANConvert();
            outTxt.Text = "AA " + AN;
        }

        private void inpTxt_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 'u' && e.KeyChar != 'c' && e.KeyChar != 'a' && e.KeyChar != 'g' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            else
            {


                if (e.KeyChar == (char)Keys.Back)
                {
                    adnTxt.Text = adnTxt.Text.Substring(0, adnTxt.Text.Length - 1);
                    arntTxt.Text = arntTxt.Text.Substring(0, arntTxt.Text.Length - 1);
                }
                else
                {
                    string aux;

                    if (arnmTxt.Text.Length >= 3)
                    {
                        aux = arnmTxt.Text.ToString();

                        aux = e.KeyChar.ToString();
                        aux = ARNmADN(aux);
                        adnTxt.Text += aux;
                        aux = arnmTxt.Text.ToString();
                        aux = e.KeyChar.ToString();
                        aux = ARNmARNt(aux);
                        arntTxt.Text += aux;
                    }
                }
            }
        }

        private void adnTxt_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 't' && e.KeyChar != 'c' && e.KeyChar != 'a' && e.KeyChar != 'g' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            else
            {
                if (e.KeyChar == (char)Keys.Back)
                {
                    arnmTxt.Text = arnmTxt.Text.Substring(0, arnmTxt.Text.Length - 1);
                    arntTxt.Text = arntTxt.Text.Substring(0, arntTxt.Text.Length - 1);
                }
                else
                {
                    string aux;
                    if (arntTxt.Text.Length >= 3)
                    {
                        aux = arntTxt.Text.ToString();
                        aux = e.KeyChar.ToString();
                        aux = ARNmARNt(aux);
                        arnmTxt.Text += aux;
                        aux = arnmTxt.Text.ToString();
                        aux = e.KeyChar.ToString();
                        aux = ARNmARNt(aux);
                        arntTxt.Text += aux;
                    }
                }
            }
        }

        private void arntTxt_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 'u' && e.KeyChar != 'c' && e.KeyChar != 'a' && e.KeyChar != 'g' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            else
            {
                if (e.KeyChar == (char)Keys.Back)
                {
                    arnmTxt.Text = arnmTxt.Text.Substring(0, arnmTxt.Text.Length - 1);
                    adnTxt.Text = adnTxt.Text.Substring(0, adnTxt.Text.Length - 1);
                }
                else
                {
                    string aux;
                    if (arntTxt.Text.Length >= 3)
                    {
                        aux = arntTxt.Text.ToString();
                        aux = e.KeyChar.ToString();
                        aux = ARNmARNt(aux);
                        arnmTxt.Text += aux;
                        aux = arnmTxt.Text.ToString();
                        aux = e.KeyChar.ToString();
                        aux = ARNmADN(aux);
                        adnTxt.Text += aux;
                    }
                }
            }
        }

         /* ARNm -> ADN same 
        * ARNm -> ARNt same ARNt -> ARNm same ADN  -> ARNm
        */

    }
}
