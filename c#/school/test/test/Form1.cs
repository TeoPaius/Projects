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
using System.Runtime.InteropServices;


namespace test
{
    public partial class Form1 : Form
    {
        [DllImport("user32.dll")]
        static extern IntPtr GetDC(IntPtr hwnd);

        [DllImport("user32.dll")]
        static extern Int32 ReleaseDC(IntPtr hwnd, IntPtr hdc);

        [DllImport("gdi32.dll")]
        static extern uint GetPixel(IntPtr hdc, int nXPos, int nYPos);

        static public System.Drawing.Color GetPixelColor(int x, int y)
        {
            IntPtr hdc = GetDC(IntPtr.Zero);
            uint pixel = GetPixel(hdc, x, y);
            ReleaseDC(IntPtr.Zero, hdc);
            Color color = Color.FromArgb((int)(pixel & 0x000000FF),
                         (int)(pixel & 0x0000FF00) >> 8,
                         (int)(pixel & 0x00FF0000) >> 16);
            return color;
        }

        public Form1()
        {
            InitializeComponent();
           
            Bitmap bm = new Bitmap(1900,1080);

            for (int i = 20; i <= 100; i++)
                for(int j = 20; j <= 100; ++j)
                    bm.SetPixel(i, j, GetPixelColor(i, j));

            Bitmap bm2 = new Bitmap(bm, pictureBox1.Size);
            pictureBox1.Image = bm2;
            
            
           

        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            pictureBox1.BackColor = GetPixelColor(this.PointToScreen(e.Location).X, this.PointToScreen(e.Location).Y);
           // MessageBox.Show((e.X + this.Location.X).ToString() + ' ' + (e.Y + this.Location.Y).ToString() + ' ' + GetPixelColor(e.X + this.Location.X, e.Y + this.Location.Y).ToString());
        }
    }
}
