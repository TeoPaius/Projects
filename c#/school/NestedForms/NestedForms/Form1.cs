using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NestedForms
{
    public partial class Form1 : Form
    {

        Form1 x;
        Form2 y;
        public int var2 = 3;
        public Form1()
        {
            InitializeComponent();
            y = new Form2(this);
            y.Show();
            MessageBox.Show(y.var.ToString());
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var2 = 5;
        }
    }
}
