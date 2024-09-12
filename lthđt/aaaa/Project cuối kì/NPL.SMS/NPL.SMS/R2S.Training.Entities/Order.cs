using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R2S.Training.Entities
{
    class Order
    {
        private int orderId;
        private DateTime orderDate;
        private int customerId;
        private int employeeId;
        private float total;
        public Order() { }

        public Order(int orderId, DateTime orderDate, int customerId, int employeeId, float total)
        {
            this.orderId=orderId;
            this.orderDate=orderDate;
            this.customerId = customerId;
            this.employeeId = employeeId;
            this.total = total;
        }
        public int OrderId { get => orderId; set => orderId = value; }
        public DateTime OrderDate { get => orderDate; set => orderDate = value; }
        public int CustomerId { get => customerId; set => customerId = value; }
        public int EmployeeId { get => employeeId; set => employeeId = value; }
        public float Total { get => total; set => total = value; }

        public void Input()
        {
            OrderDate = DateTime.Now;
            Console.Write("\tCustomer_id: ");
            CustomerId = Convert.ToInt32(Console.ReadLine());
            Console.Write("\tEmployee_id: ");
            EmployeeId = Convert.ToInt32(Console.ReadLine());
        }
    }
}
