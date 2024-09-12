using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Square:Rectangle
    {
        private float edge;
        public Square(float edge) 

        public void ToString()
        {
            base.TinhDienTich(edge,edge);
            base.TinhChuVi(edge,edge);
            Console.WriteLine("Hinh vuong co Dien Tich {0}, Chu Vi {1} ",TinhChuVi(Length,Width));
        }
    }
}
