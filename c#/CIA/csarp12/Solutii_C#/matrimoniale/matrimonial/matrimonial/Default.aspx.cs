using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

namespace matrimonial
{
    public partial class _Default : System.Web.UI.Page
    {
        public matrimonial.DataSet1TableAdapters.persTableAdapter p = new matrimonial.DataSet1TableAdapters.persTableAdapter();
        protected void Page_Load(object sender, EventArgs e)
        {
           
        }

        protected void GridView1_Sorting(object sender, GridViewSortEventArgs e)
        {

        }

        protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        protected void Button2_Click(object sender, EventArgs e)
        {

            if (TextBox1.Text != "" && TextBox2.Text != "" && TextBox3.Text != "" && TextBox4.Text != "" && TextBox5.Text != "")
            {
                p.Insert(TextBox1.Text, TextBox2.Text, Convert.ToInt16(TextBox3.Text), TextBox4.Text, TextBox5.Text);
                GridView1.DataBind();
                TextBox1.Text = TextBox2.Text = TextBox3.Text = TextBox4.Text = TextBox5.Text = "";
            }
            else Label8.Text = " Date invalide";
        }

        protected void Button3_Click(object sender, EventArgs e)
        {
           Button3.Text="Media varstei este "+ (p.Media()).ToString();
        }
    }
}
