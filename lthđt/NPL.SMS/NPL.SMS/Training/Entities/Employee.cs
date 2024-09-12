using System;
using System.Collections.Generic;
using System.Text;

namespace R2S.Training.Entities
{
    class Employee
    {
        private int employeeId, spvrId;
        private string employeeName;
        private double salary;

        public Employee() { }

        public Employee(int employeeId, string employeeName, double salary, int spvrId)
        {
            this.employeeId = employeeId;
            this.employeeName = employeeName;
            this.salary = salary;
            this.spvrId = spvrId;
        }

        public int EmployeeId { get => employeeId; set => employeeId = value; }

        public string EmployeeName { get => employeeName; set => employeeName = value; }

        public double Salary { get => salary; set => salary = value; }

        public int SpvId { get => spvrId; set => spvrId = value; }
    }
}
