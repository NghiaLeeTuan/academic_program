using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using R2S.Training.Connection;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    class LineItemDAO : ILineItemDAO
    {
        private const string ADD_LINEITEM = "insert into dbo.LineItem values (@OrderId,@ProductId,@Quantity,@Price)";
        private const string SELECT_LINEITEM = "select * from LineItem";
        private static bool ExistLineItem(LineItem item)
        {
            bool check = false;
            //mo ket noi
            SqlConnection conn = Comman.GetSqlConnection();
            conn.Open();
            //truy van
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_LINEITEM, conn);
            SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (item.OrderId == Convert.ToInt32(dataReader["order_id"]) && item.ProductId == Convert.ToInt32(dataReader["product_id"]))
                {
                    check = true;
                    break;
                }
            }
            return check;
        }
        public bool AddLineItem(LineItem item)
        {
            if (!ExistLineItem(item))
            {
                SqlConnection conn = Comman.GetSqlConnection();
                //mo ket noi den SQL
                conn.Open();
                //Cau lenh thuc thi
                SqlCommand cmd = Comman.GetSqlCommand(ADD_LINEITEM, conn);
                cmd.Parameters.Add("@OrderId", SqlDbType.Int);
                cmd.Parameters.Add("@ProductId", SqlDbType.Int);
                cmd.Parameters.Add("@Quantity", SqlDbType.Int);
                cmd.Parameters.Add("@Price", SqlDbType.Float);

                cmd.Parameters["@OrderId"].Value = item.OrderId;
                cmd.Parameters["@ProductId"].Value = item.ProductId;
                cmd.Parameters["@Quantity"].Value = item.Quantity;
                cmd.Parameters["@Price"].Value = item.Price;

                if (cmd.ExecuteNonQuery() > 0)
                    return true;
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
}
