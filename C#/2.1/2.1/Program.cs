using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._1
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 100; i < 1000; ++i)
            {
                int a = i / 100, b = i / 10 % 10, c = i % 10;
                if (a * a * a+ b * b * b + c * c * c == i)
                {
                    Console.Write(i.ToString() + " ");
                }
            }
            Console.WriteLine("\nDONE");
            Console.ReadKey();
        }
    }
}
