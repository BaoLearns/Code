using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._4
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] scores = new double[,] { { 56, 89, 60.5, 93 }, { 95, 95, 78, 90.5}, {72, 71, 81, 90}, {65, 59, 67, 78},{71, 92, 67, 78} };
            for (int i = 0; i < 5; ++i)
            {
                double avg = 0;
                for (int j = 0; j < 4; ++j)
                    avg += scores[i, j];
                avg = avg / 4.0;
                Console.WriteLine("第{0}个学生的四门成绩分别是{1} {2} {3} {4}，所以平均成绩是{5}", i, scores[i, 0], scores[i, 1], scores[i, 2], scores[i,  3], avg);
            }
            Console.WriteLine("DONE");
            Console.ReadKey();
        }
    }
}
