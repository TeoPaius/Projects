using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Luni
{

    

    public partial class Form1 : Form
    {
        class WaterMarkTextBox : TextBox
        {

            #region Private Members

            private Font oldFont = null;
            private bool waterMarkEnabled = false;
            private string waterText = "text";
            private Color waterMarkColor = Color.Gray;
            private Size defaultSize = new Size(100, 10);
            private static int thingsRemaining = 5;

            #endregion

            #region Properties
            public string WaterText
            {
                set { waterText = value; }
            }
            #endregion

            protected override void OnCreateControl()
            {
                base.OnCreateControl();
                WaterMarkToggle(null, null);
            }

            protected override void OnPaint(PaintEventArgs e)
            {
                Font drawFont = new Font(Font.FontFamily,
                Font.Size, Font.Style, Font.Unit);

                SolidBrush drawBrush = new SolidBrush(waterMarkColor);
                if (Text != "")
                {
                    e.Graphics.DrawString(Text,
                    drawFont, drawBrush, new PointF(0.0F, 0.0F));
                }
                else if (Text == "")
                {
                    e.Graphics.DrawString(waterText,
                    drawFont, drawBrush, new PointF(0.0F, 0.0F));
                }

                base.OnPaint(e);

            }

            #region Constructors

            public WaterMarkTextBox()
            {
                JoinEvents(true);
                Size = defaultSize;
            }

            public WaterMarkTextBox(string _text)
            {
                waterText = _text;
                JoinEvents(true);
                Size = defaultSize;
            }

            #endregion 

            private void JoinEvents(bool join)
            {
                this.TextChanged += new System.EventHandler(WaterMarkToggle);
                this.LostFocus += new System.EventHandler(WaterMarkToggle);
                this.GotFocus += new System.EventHandler(WaterMarkToggle);
                this.KeyDown += new KeyEventHandler(MyClickEvent);
                //this.MouseMove += new System.Windows.Forms.MouseEventHandler(WaterMarkToggle);
            }

            private void MyClickEvent(object sender, KeyEventArgs e)
            {   
                
                if(e.KeyCode == Keys.Enter)
                {
                    if (thingsRemaining > 0 && Text != "")
                    { 
                        thingsRemaining--;
                        this.ReadOnly = true;
                        this.TabStop = false;
                    }
                    SendKeys.Send("{TAB}");
                    
                }
                if(thingsRemaining == 0)
                {
                   // string finalString = string.Format("Optiunile alese sunt:{0}, {1}, {2}, {3}, {4}", );
                }
            }

            private void WaterMarkToggle(object sender, EventArgs args)
            {
                if (this.Text.Length <= 0)
                {

                    EnableWaterMark();
                }
                else
                    DisableWaterMark();
                Refresh();
            }

            private void EnableWaterMark()
            {
                this.SetStyle(ControlStyles.UserPaint, true);
                waterMarkEnabled = true;
                Refresh();
            }

            private void DisableWaterMark()
            {
                if (Text == "")
                    Text = "UserName";

            }
        }


        public Form1()
        {
            InitializeComponent();
            this.ActiveControl = statusStrip1;

            WaterMarkTextBox wtb1 = new WaterMarkTextBox("Optiunea 1");
            WaterMarkTextBox wtb2 = new WaterMarkTextBox("Optiunea 2");
            WaterMarkTextBox wtb3 = new WaterMarkTextBox("Optiunea 3");
            WaterMarkTextBox wtb4 = new WaterMarkTextBox("Optiunea 4");
            WaterMarkTextBox wtb5 = new WaterMarkTextBox("Optiunea 5");

            flowLayoutPanel1.Controls.Add(wtb1);
            flowLayoutPanel1.Controls.Add(wtb2);
            flowLayoutPanel1.Controls.Add(wtb3);
            flowLayoutPanel1.Controls.Add(wtb4);
            flowLayoutPanel1.Controls.Add(wtb5);



        }

       
    }
}
