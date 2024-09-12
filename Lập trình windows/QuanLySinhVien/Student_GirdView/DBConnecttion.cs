using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Student_GirdView
{
    class DBConnection
    {
        private SqlConnection  connection;
        public DBConnection()
        {
            connection = new SqlConnection(Properties.Settings.Default.conn);
        }
        public SqlConnection openConnection()
        {
            if (connection.State == ConnectionState.Closed || connection.State == ConnectionState.Broken)
            {
                connection.Open();
            }
            return connection;
        }
        public void ExecuteNonQuery(String query, SqlParameter[] sqlParameter=null)
        {
            using (SqlCommand sqlCommand = new SqlCommand(query, openConnection()))
            {

                if(sqlParameter != null)
                {
                    sqlCommand.CommandType = CommandType.Text;
                    sqlCommand.Parameters.AddRange(sqlParameter);
                }
                try
                {
                    sqlCommand.ExecuteNonQuery();
                }
                catch
                {
                    MessageBox.Show("Khong thuc hien duoc!!!");
                }
                finally
                {
                    connection.Close();
                }
            }
        }
        public DataTable ExecuteQuery(string query, object[] parameter = null)
        {
             DataTable data = new DataTable();
            using(SqlCommand command = new SqlCommand(query, openConnection()))
            {
                try
                {
                    if (parameter != null)
                    {
                        string[] listPara = query.Split(' ');
                        int i = 0;
                        foreach (string item in listPara)
                        {
                            if (item.Contains('@'))
                            {
                                command.Parameters.AddWithValue(item, parameter[i]);
                                i++;
                            }
                        }
                    }
                    SqlDataAdapter adapter = new SqlDataAdapter(command);
                    adapter.Fill(data);
                    return data;
                }
                catch
                {
                    MessageBox.Show("Khong the thuc hien duoc");
                }
                finally
                {
                    connection.Close();
                }
            }
            return data;
        }
    }
}
