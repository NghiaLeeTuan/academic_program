using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    interface IOrderDAO
    {
        List<LineItem> GetAllItemsByOrderId(int orderId);
        Double ComputeOrderTotal(int orderId);
        bool UpdateOrderTotal(int orderId);
        bool AddOrder(Order order);
    }
}
