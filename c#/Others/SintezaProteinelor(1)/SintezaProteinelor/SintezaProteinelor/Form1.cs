using System.Windows.Forms;

namespace SintezaProteinelor
{
    public partial class Form1 : Form
    {
        /* ARNm -> ADN same 
        * ARNm -> ARNt same ARNt -> ARNm same ADN  -> ARNm
        */  
        private string AN;


        private char ARNmADN(char x)
        {
            char aux = x;
            switch (x)
            {
                case 'A':
                    aux = 'T';
                    break;
                case 'U':
                    aux = 'A';
                    break;
                case 'G':
                    aux = 'C';
                    break;
                case 'C':
                    aux = 'G';
                    break;
            }

            return aux;
        }

        private char ARNmARNt(char x)
        {
            char aux = x;
            switch (x)
            {
                case 'A':
                    aux = 'U';
                    break;
                case 'T':
                    aux = 'A';
                    break;
                case 'U':
                    aux = 'A';
                    break;
                case 'G':
                    aux = 'C';
                    break;
                case 'C':
                    aux = 'G';
                    break;
            }

            return aux;
        }

        public Form1()
        {
            InitializeComponent();
        }
    }
}

