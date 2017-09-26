using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Albume
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dataSet1.Albume' table. You can move, or remove it, as needed.
            this.albumeTableAdapter.Fill(this.dataSet1.Albume);

        }

        private void button1_Click(object sender, EventArgs e)
        {

            albumeTableAdapter.InsertArtist(textBox1.Text, textBox2.Text, int.Parse(textBox3.Text),
                textBox4.Text);

            this.albumeTableAdapter.Fill(this.dataSet1.Albume);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            albumeTableAdapter.FillBy(this.dataSet1.Albume , textBox5.Text);
        }

    }
}
