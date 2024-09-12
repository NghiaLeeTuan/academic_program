using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Rectangle
    {
        private float length;
        private float witdth;

        public Rectangle() { }
        public Rectangle(float length, float width) { }

        public float Length
        {
            set
            {
                if (length < 0) length = 0;
                else length = value;
            }
            get { return length; }
        }
        public float Width
        {
            set
            {
                if (witdth < 0) witdth = 0;
                else witdth = value;
            }
            get { return witdth; }
        }
        public float TinhDienTich(float length, float witdth)
        {
            return length * witdth;
        }

        public float TinhChuVi(float length, float width)
        {
            return (length + witdth)/2;
        }
        public void toString()
        {
            Console.WriteLine("Hinh chu nhat co Dien Tich {0}, Chu Vi {1}",TinhDienTich(length,witdth),TinhChuVi(length,witdth));
        }
    }
}
