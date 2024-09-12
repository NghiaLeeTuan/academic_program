using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using R2S.Training.Entities;
using R2S.Training.Connection;
using System.Data;

namespace R2S.Training.Dao
{
    class OrderDAO:IOrderDAO
    {
        private const string SELECT_ALL_ITEMS_BY_ORDERID = "Select * from LineItem where order_id = @OrderId";
        private const string COMPUTE_TOTAL = "SELECT dbo.Total_price(@OrderId)";
        private const string UPDATE_TOTAL = "Update Orders set total = @total where order_id = @OrderId";
        private const string SELECT_ORDER = "select * from Orders";
        private const string CREATE_ORDER = "Insert into Orders values (@datetime,@customerId,@employeeId,'0')";

        private static bool ExistOrderId(int orderId)
        {
            bool check = false;
            //mo ket noi
            SqlConnection conn = Comman.GetSqlConnection();
            conn.Open();
            //truy van
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_ORDER, conn);
            SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (orderId == Convert.ToInt32(dataReader["order_id"]))
                {
                    check = true;
                    break;
                }
            }
            return check;
        }
        public List<LineItem> GetAllItemsByOrderId(int orderId)
        {
            SqlConnection conn = Comman.GetSqlConnection();
            //mo ket noi den SQL
            conn.Open();
            //Cau lenh thuc thi
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_ALL_ITEMS_BY_ORDERID, conn);

            cmd.Parameters.Add("@OrderId", SqlDbType.Int);
            cmd.Parameters["@OrderId"].Value = orderId;
            SqlDataReader dataReader = cmd.ExecuteReader();

            List<LineItem> list = new List<LineItem>();

            while (dataReader.Read())
            {
                LineItem lineItem = new LineItem
                {
                    OrderId = Convert.ToInt32(dataReader["order_id"]),
                    ProductId = Convert.ToInt32(dataReader["product_id"]),
                    Quantity = Convert.ToInt32(dataReader["quantity"]),
                    Price = Convert.ToSingle(dataReader["price"])
                };
                list.Add(lineItem);
            }
            return list;
        }
        public Double ComputeOrderTotal(int orderId)
        {
            if (ExistOrderId(orderId))
            {
                SqlConnection conn = Comman.GetSqlConnection();
                //mo ket noi den SQL
                conn.Open();
                //Cau lenh thuc thi
                SqlCommand cmd = Comman.GetSqlCommand(COMPUTE_TOTAL, conn);

                cmd.Parameters.Add("@OrderId", SqlDbType.Int);
                cmd.Parameters["@OrderId"].Value = orderId;
                double Total_price = double.Parse(cmd.ExecuteScalar().ToString());
                return Total_price;
            }
            else
            {
                Console.WriteLine("\tNo Exist Order_id: " + orderId);
                return 0;
            }
        }

        public bool UpdateOrderTotal (int orderId)
        {
            if (ExistOrderId(orderId))
            {
                SqlConnection conn = Comman.GetSqlConnection();
                //mo ket noi den SQL
                conn.Open();
                //Cau lenh thuc thi
                SqlCommand cmd = Comman.GetSqlCommand(UPDATE_TOTAL, conn);
                double total = ComputeOrderTotal(orderId);

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@orderId", orderId),
                    new SqlParameter("@total", total)
                });

                if (cmd.ExecuteNonQuery() > 0)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        public bool AddOrder(Order order)
        {
            SqlConnection conn = Comman.GetSqlConnection();
            //mo ket noi den SQL
            conn.Open();
            //Cau lenh thuc thi
            SqlCommand cmd = Comman.GetSqlCommand(CREATE_ORDER, conn);

            cmd.Parameters.AddRange(new[]
            {
                    new SqlParameter("@datetime", order.OrderDate),
                    new SqlParameter("@customerId", order.CustomerId),
                    new SqlParameter("@employeeId", order.EmployeeId)
            });

            if (cmd.ExecuteNonQuery() > 0)
                return true;
            else
                return false;
        }
    }
}
