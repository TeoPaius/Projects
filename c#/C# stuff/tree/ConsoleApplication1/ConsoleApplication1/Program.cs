using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
   class SingleObject {

   private static SingleObject instance = new SingleObject();

   private SingleObject(){}


   public static SingleObject getInstance(){
      return instance;
   }

   public void showMessage(){
      Console.WriteLine("Hello World!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
              SingleObject obj = SingleObject.getInstance();
              SingleObject obj2 = SingleObject.getInstance();
              obj.showMessage();
              obj2.showMessage();
           

        }
    }
}
