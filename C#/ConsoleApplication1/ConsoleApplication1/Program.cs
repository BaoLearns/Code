using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class A
    {
        public A()
        {
            Console.WriteLine("class A init function called");
        }
        ~A()
        {
            Console.WriteLine("class A relase");
        }
    }
    class B : A
    {
        public B()
        {
            Console.WriteLine("class B init function called");
        }
        ~B()
        {
            Console.WriteLine("class B relase");
        }
    }
    class C : B
    {
        public C()
        {
            Console.WriteLine("class C init function called");
        }
        ~C()
        {
            Console.WriteLine("class C relase");
        }
    }
    class Program
    {
        static void foo() 
        {
            C c = new C();
            
        }
        static void Main(string[] args)
        {
            foo();
            Console.ReadKey();
        }
    }
}
