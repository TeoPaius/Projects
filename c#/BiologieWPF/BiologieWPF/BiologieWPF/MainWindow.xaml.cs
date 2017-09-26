using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BiologieWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            //MainForm.
        }

        private void btnPoza3_Click(object sender, RoutedEventArgs e)
        {
           
        }

        private void btnExit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void btnPoza3_Click_1(object sender, RoutedEventArgs e)
        {
           // MessageBox.Show("hello");
            WindowGIF win = new WindowGIF();
            win.Show();
        }

        private void btnPoza1_Click(object sender, RoutedEventArgs e)
        {
            Window1 form1 = new Window1();
            form1.ShowDialog();
        }

        private void btnPoza2_Click(object sender, RoutedEventArgs e)
        {
            Window2 form2 = new Window2();
            form2.ShowDialog();
        }

        private void ARNtxtbox_GotFocus(object sender, RoutedEventArgs e)
        {
            ARNtxtbox.Text = "";
        }

        private void ADNtxtbox_GotFocus(object sender, RoutedEventArgs e)
        {
            ADNtxtbox.Text = "";
        }

        private void TRANStxtbox_GotFocus(object sender, RoutedEventArgs e)
        {
            TRANStxtbox.Text = "";
        }

        private void ARNtxtbox_LostFocus(object sender, RoutedEventArgs e)
        {
            if(ARNtxtbox.Text == "")
            {
                ARNtxtbox.Text = "Introduceti secventa ARNm";
            }

        }

        private void ADNtxtbox_LostFocus(object sender, RoutedEventArgs e)
        {
            if (ADNtxtbox.Text == "")
            {
                ADNtxtbox.Text = "Introduceti secventa ADN";
            }
        }

        private void TRANStxtbox_LostFocus(object sender, RoutedEventArgs e)
        {
            if (TRANStxtbox.Text == "")
            {
                TRANStxtbox.Text = "Introduceti secventa ARNt";
            }
        }
    }
}
