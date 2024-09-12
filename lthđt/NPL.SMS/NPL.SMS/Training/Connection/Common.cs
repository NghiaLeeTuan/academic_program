using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;

namespace R2S.Training.Connection
{
    class Common
    {
        private const string CONN_STRING = @"Data Source=DESKTOP-8EP0TLB\HOANG;Initial Catalog=SMS;Integrated Security=True";

        public static SqlConnection GetSqlConnection()
        {
            SqlConnection conn = new SqlConnection(CONN_STRING);
            return conn;
        }

        public static SqlCommand GetSqlCommand(string query, SqlConnection conn)
        {
            SqlCommand cmd = new SqlCommand(query, conn);
            return cmd;
        }
    }
}
