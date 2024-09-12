using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R2S.Training.Entities
{
    class LineItem
    {
        private int orderId;
        private int productId;
        private int quantity;
        private float price;

        public LineItem() { }
        public LineItem(int orderId,int productId,int quantity,float price) {
            this.OrderId = orderId;
            this.ProductId = productId;
            this.Quantity = quantity;
            this.Price = price;
        }

        public int OrderId { get => orderId; set => orderId = value; }
        public int ProductId { get => productId; set => productId = value; }
        public int Quantity { get => quantity; set => quantity = value; }
        public float Price { get => price; set => price = value; }
    }
}
