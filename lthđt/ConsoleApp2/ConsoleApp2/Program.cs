using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class DongVat
    {
        internal int legs, eyes;

        public DongVat(int legs, int eyes)
        {
            this.legs = legs;
            this.eyes = eyes;
        }

        public void Run()
        {
            Console.WriteLine("Running...");
        }
        public void Sleep()
        {
            Console.WriteLine("Sleeping...");
        }
    }

    class Dog : DongVat
    {
        private bool duoi;

        public Dog(int legs, int eyes, bool duoi)
        : base(legs, eyes)
        {
            this.duoi = duoi;
        }

        private void Bark()
        {
            Console.WriteLine("Barking...");
        }
        private void TailWagging()
        {
            Console.WriteLine("Wagging...");
        }
    }

    class Chicken : DongVat
    {
        private int canh;

        public Chicken(int legs, int eyes, int canh)
        : base(legs, eyes)
        {
            this.canh = canh;
        }

        private void Fly()
        {
            Console.WriteLine("Flying...");
        }
        private void Wavingwings()
        {
            Console.WriteLine("Wagging...");
        }
    }
}
