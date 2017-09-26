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
    public partial class Form2 : Form
    {
        public int var = 2;
        private Form1 father;
        public Form2()
        {
            InitializeComponent();
        }
        public Form2(Form1 frm)
        {
            InitializeComponent();
            father = frm;
            MessageBox.Show(father.var2.ToString());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(father.var2.ToString());
        }
    }
}
