using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._5
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 2; ; ++i)
            {
                if (i % 2 == 1 && i % 3 == 1 && i % 4 == 1)
                {
                    Console.WriteLine(i.ToString());
                    break;
                }
            }
            Console.WriteLine("DONE");
            Console.ReadKey();
        }
    }
}
