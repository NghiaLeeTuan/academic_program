using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

namespace StuDF
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var db = new StudentDFEntities())
            {
                var std = new Student
                {
                    Id = 1,
                    Name = "Nghia",
                    Birth = DateTime.Now,
                    Hometown="Vinh Long",
                    Email = "letuannghia22@gmail.com"
                };
                db.Students.Add(std);
                db.SaveChanges();

                var query = from q in db.Students select q;

                foreach (var s in query)
                {
                    Console.WriteLine(s.Name);
                    Console.WriteLine(s.Name);
                    Console.WriteLine(s.Name);
                    Console.WriteLine(s.Name);

                }
            }
        }
    }
}
