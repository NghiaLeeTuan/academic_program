using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R2S.Training.Entities
{
    class Product
    {
        private int productId;
        private string productName;
        private float productPrice;
        public Product() { }
        public Product(int productId,string productName,float productPrice)
        {
            this.ProductId = productId;
            this.productName = productName;
            this.productPrice = productPrice;
        }

        public int ProductId { get => productId; set => productId = value; }
        public string ProductName { get => productName; set => productName = value; }
        public float ProductPrice { get => productPrice; set => productPrice = value; }
    }
}
