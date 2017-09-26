using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ChatClient
{
    public partial class SplashScreen : Form
    {
        private double opacityIncrement = .05;
        private const int timerInterval = 50;

        public SplashScreen()
        {
            InitializeComponent();
            Opacity = .0;
            showTimer.Interval = timerInterval;
            showTimer.Start();
        }

        private void showTimer_Tick(object sender, EventArgs e)
        {
            if (Opacity < 1)
                Opacity += opacityIncrement;
        }
    }
}