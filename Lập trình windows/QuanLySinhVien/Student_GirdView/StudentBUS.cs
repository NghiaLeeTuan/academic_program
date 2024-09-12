using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Student_GirdView
{
    internal class StudentBUS
    {
        private StudentDAO stdDAO;
        public StudentBUS()
        {
            stdDAO = new StudentDAO();
        }
        public void ThemSinhVien(string name, string home, string birthday, string email)
        {
            stdDAO.ThemSinhVien(name, home,birthday,email);
        }
        public void XoaSinhVien(string id)
        {
            stdDAO.XoaSinhVien(id);
        }
        public void SuaSinhVien(string id, string name, string home, string birthday, string email)
        {
            stdDAO.SuaSinhVien(id,name,home,birthday,email);
        }
    }
}
