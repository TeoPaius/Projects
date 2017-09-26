using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Poly1
{
    class Shape 
    {
        public virtual void Draw()
        {
            Console.WriteLine("Draw a shape");
        }
    }

    class Circle : Shape 
    {
        public override void Draw()
        {
            Console.WriteLine("Draw a Circle");
        }
    }

    class Rectangle : Shape 
    {
        public override void Draw()
        {
            Console.WriteLine("Draw a Rectangle");
        }
    }

    class Square : Rectangle 
    {
        public override void Draw()
        {
            Console.WriteLine("Draw a Square");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Shape[] shapes = new Shape[4]
            {
                new Circle(), new Rectangle(),
                new Square(), new Shape()
            };
            // POLIMORFISM
            foreach (var shape in shapes)
                shape.Draw();
        }
    }
}
