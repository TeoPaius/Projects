using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{

    class Singleton
    {
        private static Singleton s;
        private int z;

        private Singleton()
        {
            Console.WriteLine("S-a construit singletonul");
            z = 2;
        }

        public static Singleton GetInstance()
        {
            if(s == null)
            {
                s = new Singleton();
            }
            return s;
        }

        public void AddZ()
        {
            z++;
            Console.WriteLine(z);
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            Singleton a = Singleton.GetInstance();
            a.AddZ();
            Singleton b = Singleton.GetInstance();
            b.AddZ();
            Singleton.GetInstance().AddZ();
        }
    }
}
