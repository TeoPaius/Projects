using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Diagnostics;

namespace SqlRemote
{
    public partial class Form1 : Form
    {
        private SqlConnection conn = null;
        private SqlCommand cmd = null;
        private SqlDataReader rd = null;

        public Form1()
        {
            InitializeComponent();
        }
        public void Connect()
        {
            conn = new SqlConnection(Properties.Settings.Default.connString);
            try
            {
                conn.Open();
            }
            catch ( Exception ex )
            {
                Debug.WriteLine(ex.ToString());
            }
        }

        public void SelectAll()
        {
            dgw.Rows.Clear();
            Connect();
            string query = "SELECT * FROM Tari";
            using (cmd = new SqlCommand(query, conn))
            {
                try
                {
                    rd = cmd.ExecuteReader();
                    while (rd.Read())
                    {
                        string[] rows = new string[3]
                         {
                             rd[0].ToString(),
                             rd[1].ToString(),
                             rd[2].ToString()
                         };

                        dgw.Rows.Add(rows);
                    }
                    rd.Close();
                }
                catch (Exception ex)
                {
                    Debug.WriteLine(ex.ToString());
                }
                finally
                {
                    conn.Close();
                }
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dgw.ColumnCount = 3;
            dgw.Columns[0].HeaderText = "ID";
            dgw.Columns[1].HeaderText = "Tara";
            dgw.Columns[2].HeaderText = "Populatie";

            SelectAll();
        }
    }
}
