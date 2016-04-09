using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt16(Console.ReadLine());
            int sum = 0, temp = 0;
            for (int i = 1; i <= n; ++i)
            {
                temp += i;
                sum += temp;
            }
            Console.WriteLine(sum.ToString());
            Console.WriteLine("DONE");
            Console.ReadKey();
        }
    }
}
