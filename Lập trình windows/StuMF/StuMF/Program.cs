using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StuMF
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var db= new StuMFContainer())
            {
                var dept = new Department
                {
                    Id = 2,
                    Name = "aaaaa",
                    StuId = 2
                };
                db.DepartmentSet.Add(dept);
                db.SaveChanges();

                var acc = new Stu
                {
                    Id = 2,
                    Name = "Nghia"
                };
                db.StuSet.Add(acc);
                db.SaveChanges();

                var query = from a in db.StuSet select a;

                foreach (var item in query)
                {
                    Console.WriteLine(item.Name);
                }
            }
        }
    }
}
