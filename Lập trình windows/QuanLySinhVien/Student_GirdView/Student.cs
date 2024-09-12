using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Student_GirdView
{
    class Student
    {
        private string name;

        private string hometown;

        private string birthday;

        private string email;
        Student(string name,string hometown,string birthday,string email)
        {
            this.name = name;
            this.birthday = birthday;
            this.hometown = hometown;
            this.email = email;
        }

      
    }
}
