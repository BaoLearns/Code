using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._3
{
    class Program
    {
        private struct Relation
        {
            public int number;
            public string name;
        }
        static void Main(string[] args)
        {
            int[] numbers = new int[] { 1002, 1005, 1001, 1004, 1003 };
            string[] name = new string[] { "Wang", "Zhang", "Bob", "Alice", "Ben" };
            Relation[] relation = new Relation[5];
            for (int i = 0; i < 5; ++i)
            {
                relation[i].number = numbers[i];
                relation[i].name = name[i];
            }
            for (int i = 0; i < 5; ++i)
            {
                Console.Write("第{0}个学生的学号与姓名：", i);
                Console.Write(numbers[i].ToString() + " ");
                Console.Write(name[i] + "\n");
            }
            Array.Sort(numbers);
            Console.WriteLine("以学号排序：");
            for (int i = 0; i < 5; ++i)
            {
                Console.Write("第{0}个学生的学号与姓名：", i);
                Console.Write(numbers[i].ToString() + " ");
                for (int j = 0; j < 5; ++j)
                {
                    if(numbers[i] == relation[j].number)
                        Console.Write(relation[j].name + "\n");
                }
            }
            Console.WriteLine("以姓名排序：");
            Array.Sort(name);
            for (int i = 0; i < 5; ++i)
            {
                Console.Write("第{0}个学生的学号与姓名：", i);
                for (int j = 0; j < 5; ++j)
                {
                    if (name[i] == relation[j].name)
                        Console.Write(relation[j].number + " ");
                }
                Console.Write(name[i].ToString() + "\n");
                
            }
            Console.WriteLine("DONE");
            Console.ReadKey();


        }
    }
}
