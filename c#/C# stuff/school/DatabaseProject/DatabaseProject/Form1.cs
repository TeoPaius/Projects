using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace DatabaseProject
{
    public partial class Form1 : Form
    {

        #region Private members
        private PictureBox[] pbList;
        private int pbSize = 30;
        private int start = 20;
        private byte[] config;
        private int count;

        #endregion

        public class Item
        {
            public int value;
            public Item(int val)
            {
                value = val;
            }
            
            public override string ToString()
            {
                return value.ToString();
            }

        }

        public Form1()
        {
            InitializeComponent();
            pbList = new PictureBox[26];
            config = new byte[26];

            count = (int)configsTableAdapter.ScalarQuery1();
            for(int i = 1; i <= count; ++i)
            {
                comboBox1.Items.Add(new Item(i));
            }

            for (int i = 1; i <= 25; ++i)
            {
                pbList[i] = new PictureBox();
                this.Controls.Add(pbList[i]);
            }
            int cnt = 1;

            for(int j = 1; j <= 5; ++j)
            {
                for(int i = 1; i <= 5; ++i)
                {
                    pbList[cnt].Location = new Point(start + pbSize * (i - 1), start + pbSize * (j - 1));
                    pbList[cnt].Size = new Size(pbSize, pbSize);
                    pbList[cnt].BorderStyle = BorderStyle.FixedSingle;
                    pbList[cnt].BackColor = Color.White;
                    pbList[cnt].Click += new EventHandler(ColorChange);
                    cnt++;
                }
            }

            
        }

     

        void ColorChange(object sender, EventArgs e)
        {
            PictureBox temp = (PictureBox)sender;
            if (temp.BackColor == Color.White)
                temp.BackColor = Color.Black;
            else
                temp.BackColor = Color.White;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Configs' table. You can move, or remove it, as needed.
            this.configsTableAdapter.Fill(this.database1DataSet.Configs);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            char[] array = new char[26];
            for (int i = 1; i <= 25; ++i)
            {
                if (pbList[i].BackColor == Color.Black)
                   array[i] = '0';
                if (pbList[i].BackColor == Color.White)
                    array[i] = '1';
            }
            DateTime dt = DateTime.Now;

            configsTableAdapter.InsertQuery(new string(array), dt);
            count++;
            comboBox1.Items.Add(new Item(count));
            label2.Text = DateTime.Now.ToString();
            configsTableAdapter.Fill(database1DataSet.Configs);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            char[] array = new char[26];
            Item aux = (Item)comboBox1.SelectedItem;
            array = configsTableAdapter.ScalarQuery(aux.value).ToCharArray();
            for(int i = 1; i <= 25; ++i)
            {
                if (array[i] == '0')
                    pbList[i].BackColor = Color.Black;
                if (array[i] == '1')
                    pbList[i].BackColor = Color.White;
            }
            label2.Text = configsTableAdapter.ScalarQuery2(aux.value).ToString();
        }

        private void configsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.configsBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.database1DataSet);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen p = new Pen(Color.Red);
            e.Graphics.DrawLine(p, new Point(0, 0), new Point(200, 200));
        }
    }
}
