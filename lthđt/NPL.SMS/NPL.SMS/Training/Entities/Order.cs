using System;
using System.Collections.Generic;
using System.Text;

namespace R2S.Training.Entities
{
    class Order
    {
        private int orderId, customerId, employeeId;
        private DateTime orderDate;
        private double total;

        public Order() { }

        public Order(int orderId, DateTime orderDate, int customerId, int employeeId, double total)
        {
            this.orderId = orderId;
            this.orderDate = orderDate;
            this.customerId = customerId;
            this.employeeId = employeeId;
            this.total = total;
        }

        public int OrderId { get => orderId; set => orderId = value; }

        public DateTime OrderDate { get => orderDate; set => orderDate = value; }

        public int CustomerId { get => customerId; set => customerId = value; }

        public int EmployeeId { get => employeeId; set => employeeId = value; }

        public double Total { get => total; set => total = value; }

        public void Input()
        {
            OrderDate = DateTime.Now;

            Console.Write("Enter customer id: ");
            CustomerId = int.Parse(Console.ReadLine());

            Console.Write("Enter employee id: ");
            EmployeeId = int.Parse(Console.ReadLine());
            Total = 0;
        }

        public void Output()
        {
            Console.WriteLine("\tOrder id: {0}, Order_date: {1}, Customer id: {2}, Employee id: {3}", OrderId, OrderDate, CustomerId, EmployeeId);
        }
    }
}
