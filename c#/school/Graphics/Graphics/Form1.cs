using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

 

namespace Graphics
{
    public partial class Form1 : Form
    {

        public Point origin;
        public int start, end;
        public int offset;
        public Thread tr;
        public Point[] curve;
        public Point[] curve2;


        public Form1()
        {
            InitializeComponent();
            origin = new Point(200, 200);
            start = 0;
            end = 180;
            offset = 0;
            curve = new Point[181];
            curve2 = new Point[181];
            tr = new Thread(new ThreadStart(GetPath));

            System.Windows.Forms.Timer t = new System.Windows.Forms.Timer();
            t.Interval = 10;
            t.Tick += new EventHandler(Form1_Draw);

            t.Start();
           
            

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void GetPath()
        {
            for (int i = 0; i <= 180; ++i)
            {
                //  gr.DrawEllipse(new Pen(Color.Blue), i, -(float)Math.Sin(Math.PI/180*(i+offset)) * 90, 1, 1);
                curve[i] = new Point(i, -(int)(Math.Sin(Math.PI / 180 * (i + offset)) * 90));
                curve2[i] = new Point(i, -(int)(Math.Cos(Math.PI / 180 * (i + offset)) * 90));
                //curve[i] = new Point(offset, 2);
            }
        }
        public void Form1_Draw(object sender, EventArgs e)
        {
            Refresh();
            
            label1.Text = offset.ToString();
           
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            System.Drawing.Graphics gr = e.Graphics;
            gr.TranslateTransform(origin.X, origin.Y);



            gr.DrawEllipse(new Pen(Color.Red), new RectangleF(0, 0, 1, 1));
            gr.DrawLine(new Pen(Color.Black), new Point(0,100), new Point(0, -100));
            gr.DrawLine(new Pen(Color.Black), new Point(-100,0), new Point(200, 0));
            //if (tr.ThreadState != ThreadState.Running)
               // tr.Start();
            //if(tr.ThreadState != ThreadState.Running)
                for(int i = 0; i <= 180; ++i)
                {

                    curve[i] = new Point(i, -(int)(Math.Sin(Math.PI / 180 * (i + offset)) * 90));
                    curve2[i] = new Point(i, -(int)(Math.Cos(Math.PI / 180 * (i + offset)) * 90));
                 
                }
            offset++;
            
            gr.DrawCurve(new Pen(Color.Blue), curve);
            gr.DrawCurve(new Pen(Color.Green), curve2);

        }
    }
}
