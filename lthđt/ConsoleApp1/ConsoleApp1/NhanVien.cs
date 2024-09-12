using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class NhanVien : Nguoi
    {
        private string bangcap;
        public NhanVien(string maso, string hoten, string gioitinh, string bangcap)
         : base(maso, hoten, gioitinh)
        {
            this.bangcap = bangcap;
        }
        public override void Nhap()
        {
            base.Nhap(); // Gọi phương thức của lớp Nguoi
                         // Thêm xử lý cho thuộc tính bằng cấp
            Console.Write("Nhap thong tin bang cap: ");
            bangcap = Console.ReadLine();
        }
        public override void HienThi()
        {
            base.HienThi();
            Console.WriteLine("Bang cap: {0}", bangcap);
        }
    }
}
