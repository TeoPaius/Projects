using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication10
{

    public class Form_butoane : Form
    {
        Buton butonel1 = new Buton();
        Buton butonel2 = new Buton();
        Buton butonel3 = new Buton();
        Buton butonel4 = new Buton();
        Buton butonel5 = new Buton();
        Buton butonel6 = new Buton();
        Buton butonel7 = new Buton();

        Buton butonel8 = new Buton();
        Buton butonel9 = new Buton();
        Buton butonel10 = new Buton();
        Buton butonel11 = new Buton();
        Buton butonel12 = new Buton();
        Buton butonel13 = new Buton();
        Buton butonel14 = new Buton();
        Buton butonel15 = new Buton();
        Buton butonel16 = new Buton();

        private readonly Form1 _form1;

        public Form_butoane(Form1 formulet)
        {
            InitializeComponent();
            
            _form1 = formulet;
            this.ClientSize = new System.Drawing.Size(220, 220);
            genbut();
            this.FormClosing += new FormClosingEventHandler(inchidere);
        }

        private void genbut()
        {
            int lung = 40, lat = 40;
            butonel1.Height = lat;
            butonel1.Width = lung;
            butonel1.Location = new Point(20, 20);
            butonel1.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel1.Text = "é";
            butonel1.Name = "butonel1";
            butonel1.Click += new EventHandler(addchar);
            Controls.Add(butonel1);
            butonel2.Height = lat;
            butonel2.Width = lung;
            butonel2.Location = new Point(65, 20);
            butonel2.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel2.Text = "à";
            butonel2.Name = "butonel2";
            butonel2.Click += new EventHandler(addchar);
            Controls.Add(butonel2);
            Controls.Add(butonel3);
            butonel3.Height = lat;
            butonel3.Width = lung;
            butonel3.Location = new Point(110, 20);
            butonel3.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel3.Text = "è";
            butonel3.Click += new EventHandler(addchar);
            Controls.Add(butonel4);
            butonel4.Height = lat;
            butonel4.Width = lung;
            butonel4.Location = new Point(155, 20);
            butonel4.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel4.Text = "ù";
            butonel4.Click += new EventHandler(addchar);
            Controls.Add(butonel5);
            butonel5.Height = lat;
            butonel5.Width = lung;
            butonel5.Location = new Point(20, 65);
            butonel5.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel5.Text = "â";
            butonel5.Click += new EventHandler(addchar);
            Controls.Add(butonel6);
            butonel6.Height = lat;
            butonel6.Width = lung;
            butonel6.Location = new Point(65, 65);
            butonel6.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel6.Text = "ê";
            butonel6.Click += new EventHandler(addchar);
            Controls.Add(butonel7);
            butonel7.Height = lat;
            butonel7.Width = lung;
            butonel7.Location = new Point(110, 65);
            butonel7.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel7.Text = "î";
            butonel7.Click += new EventHandler(addchar);
            Controls.Add(butonel8);
            butonel8.Height = lat;
            butonel8.Width = lung;
            butonel8.Location = new Point(155, 65);
            butonel8.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel8.Text = "ô";
            butonel8.Click += new EventHandler(addchar);
            Controls.Add(butonel9);
            butonel9.Height = lat;
            butonel9.Width = lung;
            butonel9.Location = new Point(20, 110);
            butonel9.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel9.Text = "û";
            butonel9.Click += new EventHandler(addchar);
            Controls.Add(butonel10);
            butonel10.Height = lat;
            butonel10.Width = lung;
            butonel10.Location = new Point(65, 110);
            butonel10.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel10.Text = "ë";
            butonel10.Click += new EventHandler(addchar);
            Controls.Add(butonel11);
            butonel11.Height = lat;
            butonel11.Width = lung;
            butonel11.Location = new Point(110, 110);
            butonel11.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel11.Text = "ï";
            butonel11.Click += new EventHandler(addchar);
            Controls.Add(butonel12);
            butonel12.Height = lat;
            butonel12.Width = lung;
            butonel12.Location = new Point(155, 110);
            butonel12.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel12.Text = "ü";
            butonel12.Click += new EventHandler(addchar);
            Controls.Add(butonel13);
            butonel13.Height = lat;
            butonel13.Width = lung;
            butonel13.Location = new Point(20, 155);
            butonel13.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel13.Text = "ÿ";
            butonel13.Click += new EventHandler(addchar);
            Controls.Add(butonel14);
            butonel14.Height = lat;
            butonel14.Width = lung;
            butonel14.Location = new Point(65, 155);
            butonel14.Font = new Font("Roboto", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            butonel14.Text = "ç";
            butonel14.Click += new EventHandler(addchar);




        }

        private void addchar(object sender, EventArgs e)
        {
            Button aux = (Button)sender;
            _form1.addlabel(aux.Text);

        }

        private void inchidere(object sender, FormClosingEventArgs e)
        {
            _form1.checked_at_least_once = true;
         
            //MessageBox.Show("da");
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // Form_butoane
            // 
            this.ClientSize = new System.Drawing.Size(264, 264);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_butoane";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.ResumeLayout(false);

        }
    }

}