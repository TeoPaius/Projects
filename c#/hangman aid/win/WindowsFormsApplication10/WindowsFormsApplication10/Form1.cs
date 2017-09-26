using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;


namespace WindowsFormsApplication10
{
    public partial class Form1 : Form
    {
        private String[] coada = new String[101]; //vectorul unde punem din XML
        private String WRONG = ""; // literele gresite introduse
        private char[] Cuvant_curent = new char[101]; //cuvantul curent = coada[nr_curent]
        private int litere_gresite = 0, litere = 0, cuvinte_totale = 0, incercari = 0;
        private char[] cuvant_afisat = new char[202]; // cuvantul afisat *pt spatiu* A _ _ _ _ D
        const int LITERE_MAXIM = 4;
        Buton dynamicButtonst = new Buton();
        Buton dynamicButtonex = new Buton();
        public bool checked_at_least_once = true;
        public Form1() // constructor pentru Form1
        {
            loadword(); //incarca din xml in vector
            fasiru(); //construieste sirul afisat ex: _ _ _ _ 
            InitializeComponent();
            fabut();// face formul
            loadmenu();
            incarcapoze();
            
            
            codeaza(); // codeaza cuvantul afisat ex A _ _ _ _ D

            //fabut();
        }

       

        private void loadmenu()
        {
            pictureBox0.Visible = false;
            label1.Visible = false;
            label4.Visible = false;
            textBox1.Visible = false;
            dynamicButtonst.Visible = true;

            checkchar.Visible = false;
            
            dynamicButtonex.Visible = true;
        }

        private void incarcapoze()
        {
            string cale = System.IO.Directory.GetCurrentDirectory();

            String cale2 = Convert.ToString(incercari) + ".png";

            Image poza = Image.FromFile(cale + "/resurse/" + cale2);
            pictureBox0.Image = poza;


        }


        private void fasiru()
        {

            for (int i = 0; i < cuvant_afisat.Length; i += 2)
                cuvant_afisat[i] = '_';
            for (int i = 1; i < cuvant_afisat.Length; i += 2)
                cuvant_afisat[i] = ' ';

        }
        private void fabut() 
        {
            


            dynamicButtonst.Height = 80;
            dynamicButtonst.Width = 400;

            dynamicButtonst.Location = new Point((this.Size.Height)/2 - 40, (this.Size.Height)/2 - 130);
            dynamicButtonst.Text = "START";
            dynamicButtonst.Name = "DynamicButton";
            dynamicButtonst.Click += new EventHandler(ButonStart_Click);
           
            Controls.Add(dynamicButtonst);

            dynamicButtonex.Height = 80;
            dynamicButtonex.Width = 400;
            dynamicButtonex.Location = new Point((this.Size.Height) / 2 - 40, (this.Size.Height)/ 2);
            dynamicButtonex.Text = "EXIT";
            dynamicButtonex.Name = "DynamicButton2";
            dynamicButtonex.Click += new EventHandler(ButonExit_Click_1);
            Controls.Add(dynamicButtonex);

        }

        private void DynamicButton_Click(object sender, EventArgs e)
        {

        } 

        private void Form1_Load(object sender, EventArgs e)
        {

        } // a nu se sterge, afecteaza designer

        private void Form1_KeyDown(object sender, KeyEventArgs e) //faci exit apasand esc
        {
            if (e.KeyCode.Equals(Keys.Escape))
                Application.Exit();
        }

        private void loadword()
        {
            XmlDocument doc = new XmlDocument();
            string cale = System.IO.Directory.GetCurrentDirectory();

            doc.Load(cale + "/date.xml");
            int i = 0;
            foreach (XmlNode xmlNode in doc.DocumentElement.ChildNodes)
            {
                coada[i] = xmlNode.Attributes["vall"].Value; i++;
            }

            cuvinte_totale = i;
        }
        void afiseaza()
        {
            String afiseaza = null;
            for (int i = 0; i < Cuvant_curent.Length * 2; i++)
                afiseaza += Convert.ToString(cuvant_afisat[i]);

            label1.Text = afiseaza;
        }
        private void codeaza()
        {
            Random rand = new Random(DateTime.Now.Millisecond);
            int nr_curent = rand.Next(cuvinte_totale);
            Cuvant_curent = coada[nr_curent].ToCharArray();
            char init, final;
            init = Cuvant_curent[0];
            final = Cuvant_curent[coada[nr_curent].Length - 1];
            //MessageBox.Show(Convert.ToString(cuvant_afisat[0]) + Convert.ToString(cuvant_afisat[1]));
            int kk = 0;
            for (int i = 0; i < Cuvant_curent.Length; i++)
            {
                if (!Cuvant_curent[i].Equals(""))
                {
                    litere++;
                }
                if (init == Cuvant_curent[i])
                    cuvant_afisat[kk] = init;
                if (final == Cuvant_curent[i])
                    cuvant_afisat[kk] = final;
                kk = kk + 2;
            }
            
            float marime;

            if (Cuvant_curent.Length > 15)
            {
                marime = 40;
            }
            else if (Cuvant_curent.Length > 10)
                marime = 20;
            else marime = 60;
                label1.Font = new Font(label1.Font.Name, marime, label1.Font.Style, label1.Font.Unit);
         

            afiseaza();
        }

        private void winner() //functia de win
        {
            var ans = MessageBox.Show("Vrei sa mai incerci?", "Bravo! Ai castigat!", MessageBoxButtons.RetryCancel);
            if (ans == DialogResult.Retry)
            {
                curata();
                fasiru();
                codeaza();
            }
            else
                loadmenu();
        }

        private void pierdut()//functia de lose
        {
            incercari++;
            incarcapoze();
           
            var rezultat = MessageBox.Show("Vrei sa mai incerci?", "You lost!", MessageBoxButtons.RetryCancel);

            if (rezultat == DialogResult.Retry)
            {
                curata();
                fasiru();
                codeaza();
            }
            else
            {
                loadmenu();
            }
            //MessageBox.Show(Convert.ToString(nr_curent));
            //Application.ExitThread();

        }


        private void verifica(String carr)//verifica daca carr este in sir
        {
            int kk = 0;
            bool ok = false;
            bool castig = false;
            char car = carr.ToCharArray()[0];



            for (int i = 0; i < litere; i++)
            {
                if (car == Cuvant_curent[i])
                {
                    cuvant_afisat[kk] = car;
                    ok = true;
                }
                if (cuvant_afisat[kk] == '_')
                    castig = true;

                kk += 2;
            }

            //MessageBox.Show(Convert.ToString(car));

            if (ok == true) { afiseaza(); if (castig == false) winner(); }
            else {  scade(carr); }
        }




        private void scade(String litera)//scade punctajul
        {
            int sz = WRONG.Length;
            char c = litera.ToCharArray()[0];
            bool ok = true;
            for (int i = 0; i < sz; ++i)
            {
                if (WRONG[i] == c)
                    ok = false;
            }
            if (ok == false)
            { 
                MessageBox.Show("Litera gresita care a mai fost introdusa " + Convert.ToString(incercari));
            }
         
            if(ok==true)
                WRONG += litera;


            

            if (incercari < LITERE_MAXIM)
            {
                
                if (ok == true)
                {
                    incercari++;
                    label4.Text += litera + " ";
                    litere_gresite++;
                }

            }
            else
                if(ok==true)pierdut();
            
           incarcapoze();
            
        }


        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode.Equals(Keys.Enter))
            {

                if (textBox1.Text != null && textBox1.Text != " " && textBox1.Text != "") { verifica(textBox1.Text); textBox1.Text = null; }
            }
        }

        private void curata()
        {
            label4.Text = "Litere gresite: ";
            WRONG = "";
            litere_gresite = 0;
            incercari = 0;
            litere = 0;
            incarcapoze();

            float marime;
            marime = 129.75f;

            label1.Font = new Font(label1.Font.Name, marime, label1.Font.Style, label1.Font.Unit);
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox0_Click(object sender, EventArgs e)
        {

        }

        private void ButonStart_Click(object sender, EventArgs e)
        {
            pictureBox0.Visible = true;
            label1.Visible = true;
            label4.Visible = true;
            textBox1.Visible = true;
            dynamicButtonst.Visible = false;
            dynamicButtonex.Visible = false;
            checkchar.Visible = true;
        }

        private void ButonExit_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }

        
        
        private void checkchar_CheckedChanged(object sender, EventArgs e)
        {
            Form_butoane formm = new Form_butoane(this);
            if (checkchar.Checked == true && checked_at_least_once == true) 
            {
                formm.Visible = true;
                checked_at_least_once = true;
                checkchar.Checked = false;
            }
            else
            {
               // formm.Close();
                checked_at_least_once = false;
            }
        }

        public void addlabel(String s)
        {
            textBox1.Text = s;
        }

    }
}