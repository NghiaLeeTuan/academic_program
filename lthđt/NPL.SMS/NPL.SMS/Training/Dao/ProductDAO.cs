using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;
using R2S.Training.Connection;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
	class ProductDAO
	{
		const string SELECT = "Select * From Product";
		//<summary>
		//check if a product exist in database
		//<param name = "productId"><param>
		//<returns> return price = 0 if doesn't exist <returns>

		public static double PriceOfProduct(int productId)
		{
			double price = 0;
			using SqlConnection conn = Common.GetSqlConnection();
			//Open the SqlConnection
			conn.Open();
			// The following code uses a SqlCommand based on the SqlConnection
			using SqlCommand cmd = Common.GetSqlCommand(SELECT, conn);
			using SqlDataReader dataReader = cmd.ExecuteReader();
			while (dataReader.Read())
			{
				if (productId == (int)dataReader["product_id"])
				{
					price = (double)dataReader["product_price"];
				}
			}
			return price;
		}
	}
}
