using System;
using System.Collections.Generic;
using System.Text;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    interface IOrderDAO
    {
        List<LineItem> GetAllItemsByOrderId(int orderId); //3
        double ComputeOrderTotal(int orderId); //4
        bool AddOrder(Order order); //8
        bool UpdateOrderTotal(int orderId); //10
    }
}
