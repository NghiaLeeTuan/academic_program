using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Student_GirdView
{
    internal class StudentDAO
    {
        private DBConnection conn;          
        public StudentDAO()
        {
            conn = new DBConnection();
        }
        public void ThemSinhVien(string name, string home, string birthday, string email)
        {
            String Add_Student = "insert into Student values(N'" + name + "',N'" + home + "','" + birthday + "','" + email + "')";

            conn.ExecuteNonQuery(Add_Student);
            
        }
        public void XoaSinhVien(string id)
        {
            string Delete_Student = "delete from Student where id='" + id +"'";
            conn.ExecuteNonQuery(Delete_Student);
        }
        public void SuaSinhVien(string id, string name, string home, string birthday, string email)
        {
            string Update_Student = "update Student set name = '"+name+"',hometown = '"+home+"',birthday = '"+birthday+"',email = '"+email+"' where id =" +id;
            conn.ExecuteNonQuery(Update_Student);
        }
    }
}
