using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using R2S.Training.Connection;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    class OrderDAO : IOrderDAO
        
    {
        private const string SELECT_ITEM_BY_ORDER = "Select * From LineItem Where order_id = @orderId";

        private const string COMPUTE_TOTAL = "select dbo.fn_sum_OrderTotal(@orderId) as total";

        private const string UPDATE = "Update Order set total = @total where order_id = @order_id";

        private const string INSERT = @"INSERT INTO Orders (order_date, customer_id, employee_id, total)
                                        VALUES (@order_date, @customer_id, @ employee_id, @total)";

        private const string SELECT_ALL_ORDER = "SELECT * FROM ORDERS";

        public List<LineItem> GetAllItemsByOrderId(int orderId)
        {
            using SqlConnection conn = Common.GetSqlConnection();
            conn.Open();
            using SqlCommand cmd = Common.GetSqlCommand(SELECT_ITEM_BY_ORDER, conn);
            cmd.Parameters.AddRange(new[]
            {
                new SqlParameter("@orderId", orderId),
            });
            using SqlDataReader dataReader = cmd.ExecuteReader();
            List<LineItem> list = new List<LineItem>();
            while (dataReader.Read())
            {
                LineItem line = new LineItem
                {
                    OrderId = (int)dataReader["order_id"],
                    Quantity = (int)dataReader["quantity"],
                    ProductId = (int)dataReader["product_id"],
                    Price = (double)dataReader["price"]
                };

                list.Add(line);
            }
            return list;
        }
        // 
        
              public double ComputeOrderTotal(int orderId)
            {
                using SqlConnection conn = Common.GetSqlConnection();

                conn.Open();
                using SqlCommand cmd = Common.GetSqlCommand(SELECT_ALL_ORDER, conn);
                using SqlDataReader dataReader = cmd.ExecuteReader();

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@orderId", orderId)
            });

                while (dataReader.Read())
                {
                    return (double)dataReader["total"];
                }
                return 0;
            }
        

        public bool UpdateOrderTotal(int orderId)
        {
            if (CheckOrderId(orderId) == true)
            {
                using SqlConnection conn = Common.GetSqlConnection();

                conn.Open();

                using SqlCommand cmd = Common.GetSqlCommand(UPDATE, conn);

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@order_id", orderId),
                    new SqlParameter("@total", ComputeOrderTotal(orderId))
                });

                if (cmd.ExecuteNonQuery() > 0)
                    return true;
                else
                    return false;
            }
            else
            {
                Console.WriteLine("This is order does't exist in database");
                return false;
            }
        }

        public static bool CheckOrderId(int orderId)
        {
            bool check = false;
            using SqlConnection conn = Common.GetSqlConnection();

            conn.Open();

            using SqlCommand cmd = Common.GetSqlCommand(SELECT_ALL_ORDER, conn);

            using SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (orderId == (int)dataReader["order_id"])
                {
                    check = true;
                }
            }
            return check;

        }

        public bool AddOrder (Order order)
        {
            if (CustomerDAO.CheckCustomerId(order.CustomerId) && EmployeeDAO.CheckEmployeeId(order.EmployeeId) == true)
            {
                using SqlConnection conn = Common.GetSqlConnection();

                conn.Open();

                using SqlCommand cmd = Common.GetSqlCommand(INSERT, conn);

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@order_date", order.OrderDate),
                    new SqlParameter("@customer_id", order.CustomerId),
                    new SqlParameter("@employee_id", order.EmployeeId),
                    new SqlParameter("@total", order.Total),
                });

                if (cmd.ExecuteNonQuery() > 0)
                {
                    return true;
                }
                return false;
            }
            else
            {
                Console.WriteLine("Customer_Id or Employee_Id invalid !!");
                return false;
            }
        }
        
    }
}
