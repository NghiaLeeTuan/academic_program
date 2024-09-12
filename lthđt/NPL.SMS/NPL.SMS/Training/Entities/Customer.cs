using System;
using System.Collections.Generic;
using System.Text;

namespace R2S.Training.Entities
{
    class Customer
    {
        private int customerId;
        private string customerName;

        public Customer() { }
        public Customer(int customerId, string customerName)
        {
            this.customerId = customerId;
            this.customerName = customerName;
        }

        public int CustomerId { get => customerId; set => customerId = value; }

        public string CustomerName { get => customerName; set => customerName = value; }

        public void Input()
        {
            Console.Write("Enter customer name: ");
            CustomerName = Console.ReadLine();
        }

        public void Output()
        {
            Console.WriteLine("\tCustomer id: {0}, Customer name: {1} ", CustomerId, CustomerName);
        }
    }
}
