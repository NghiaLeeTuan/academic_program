using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace R2S.Training.Connection
{
    class Comman
    {
        private const string CONN_STRING = @"Data Source=DESKTOP-3A3OGAO;Initial Catalog=SMS;Integrated Security=True";

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
