using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Nguoi
   {
            // Khai báo thuộc tính
            public string maso;
            public string hoten;
            public string gioitinh;
            public Nguoi(string maso, string hoten, string gioitinh)
            {
                this.maso = maso;
                this.hoten = hoten;
                this.gioitinh = gioitinh;
            }
            public virtual void Nhap()
            {
                Console.Write("Nhap ma so: ");
                maso = Console.ReadLine();
                Console.Write("Nhap ho ten: ");
                hoten = Console.ReadLine();
                Console.Write("Nhap gioi tinh: ");
                gioitinh = Console.ReadLine();
            }
            public virtual void HienThi()
            {
                Console.WriteLine("Ma so: {0}, Ho ten: {1}, Gioi tinh: {2}", maso, hoten, gioitinh);
            }
    }
    
}
