using System;
using System.Collections.Generic;
using System.Text;

namespace R2S.Training.Entities
{
    class LineItem
    {
        private int orderId, productId, quantity;
        private double price;

        public LineItem() { }
        public LineItem(int orderld, int productld, int quantity, double price)
        {
            this.orderId = orderId;
            this.productId = productId;
            this.quantity = quantity;
            this.price = price;
        }
        public int OrderId { get => orderId; set => orderId = value; }

        public int ProductId { get => productId; set => productId = value; }

        public int Quantity { get => quantity; set => quantity = value; }

        public double Price { get => price; set => price = value; }

        public void Input()
        {
            Console.Write("Order Id: ");
            orderId = int.Parse(Console.ReadLine());

            Console.Write("Product Id: ");
            productId = int.Parse(Console.ReadLine());

            Console.Write("Quantity Id: ");
            quantity = int.Parse(Console.ReadLine());
        }
        public void Output()
        {
            Console.Write("Order Id: ", +orderId);

            Console.Write("Product Id: ", +productId);

            Console.Write("Quantity Id: ", +quantity);
        }
    }
}
