using System;
using System.Windows.Forms;
using System.Threading;
using System.Diagnostics;
using System.Net.Sockets;

namespace ChatClient
{
    static class Program
    {
        public static SplashScreen splashScreen = null;
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Thread splashThread = new Thread(new ThreadStart(
                delegate
                {
                    splashScreen = new SplashScreen();
                    Application.Run(splashScreen);
                }
                ));

            splashThread.SetApartmentState(ApartmentState.STA);
            splashThread.Start();
            
            using (LoginDialog loginForm = new LoginDialog())
            {
                
                loginForm.Load += new EventHandler(loginForm_Load);
                
    
                if (loginForm.ShowDialog() == DialogResult.OK)
                {
                    
                    Application.Run(new Client(loginForm.LoginInfoName));
                }
                else
                    Application.Exit();
            }
        }

        static void loginForm_Load(object sender, EventArgs e)
        {
            if (splashScreen == null)
            {
                return;
            }
            
            splashScreen.Invoke(new Action(splashScreen.Close));
        
            splashScreen.Dispose();
         
            splashScreen = null;
        }
    }
}
