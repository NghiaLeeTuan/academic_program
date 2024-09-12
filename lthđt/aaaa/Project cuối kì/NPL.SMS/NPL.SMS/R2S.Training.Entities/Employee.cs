using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R2S.Training.Entities
{
    class Employee
    {
        private int employeeId;
        private string employeeName;
        private float salary;
        private int spvrld;

        public Employee() { }

        public Employee(int employeeId, string employeeName, float salary, int spvrld)
        {
            this.EmployeeId = employeeId;
            this.EmployeeName = employeeName;
            this.Salary = salary;
            this.Spvrld = spvrld;
        }

        public int EmployeeId { get => employeeId; set => employeeId = value; }
        public string EmployeeName { get => employeeName; set => employeeName = value; }
        public float Salary { get => salary; set => salary = value; }
        public int Spvrld { get => spvrld; set => spvrld = value; }
    }
}
