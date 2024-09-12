using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using R2S.Training.Connection;
using R2S.Training.Entities;
using R2S.Training.Dao;

namespace R2S.Training.Dao
{
    class LineItemDAO : ILineItemDAO
    {
		const string INSERT = @"Insert into LineItem (order_id, product_id, quantity, price)
					Values (@order_id, @product_id, @quantity, @price)";
		const string UPDATE_QUANTITY = @"Update LineItem
						Set quantity += @quantity
						where order_id = @order_id and product_id = @product_id";
		const string SELECT = "Select * From LineItem";
		//<summary>
		//Add a item to order
		//</summary>
		//<param name = "item"></param>
		//<returns></returns>
		public bool AddLineItem(LineItem item)
		{
			item.Price = ProductDAO.PriceOfProduct(item.ProductId);
			if (OrderDAO.CheckOrderId(item.OrderId) == true && item.Price > 0)
			{
				if (CheckLineItem(item) == true)
				{
					return UpdateLineItem(item);
				}
				else
				{
					using SqlConnection conn = Common.GetSqlConnection();
					//Open the SqlConnection
					conn.Open();
					// The following code uses a SqlCommand based on the SqlConnection
					using SqlCommand cmd = Common.GetSqlCommand(INSERT, conn);
					cmd.Parameters.AddRange(new[]
					{
						new SqlParameter("@order_id", item.OrderId),
						new SqlParameter("@product_id", item.ProductId),
						new SqlParameter("@oquantity_id", item.Quantity),
						new SqlParameter("@price_id", item.Price)
					});
					if (cmd.ExecuteNonQuery() > 0)
						return true;
					else
						return false;
				}
			}
			else
			{
				Console.WriteLine("Product or Order invalid");
				return false;
			}
		}

		public bool UpdateLineItem(LineItem lineItem)
		{
			using SqlConnection conn = Common.GetSqlConnection();
			conn.Open();
			using SqlCommand cmd = Common.GetSqlCommand(UPDATE_QUANTITY, conn);
			cmd.Parameters.AddRange(new[]
			{
				new SqlParameter("@oquantity_id", lineItem.Quantity),
				new SqlParameter("@order_id", lineItem.OrderId),
				new SqlParameter("@product_id", lineItem.ProductId),


			});
			if (cmd.ExecuteNonQuery() > 0)
				return true;
			else
				return false;
		}
		public static bool CheckLineItem(LineItem lineItem)
		{
			bool check = false;
			using SqlConnection conn = Common.GetSqlConnection();
			conn.Open();
			using SqlCommand cmd = Common.GetSqlCommand(SELECT, conn);
			using SqlDataReader dataReader = cmd.ExecuteReader();
			while (dataReader.Read())
			{
				if (lineItem.OrderId == (int)dataReader["order_id"] &&
					lineItem.ProductId == (int)dataReader["product_id"])
				{
					check = true;
				}
			}
			return check;
		}

	}
}

