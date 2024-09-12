using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using R2S.Training.Connection;
using R2S.Training.Entities;
using System.Data;

namespace R2S.Training.Dao
{
    class CustomerDAO : ICustomerDAO
    {
        private const string SELECT_ALLCUSTOMER = "SELECT * FROM Customer";
        private const string UPDATE = "sp_update_customer @customer_id, @customer_name";
        private const string INSERT = "InsertCustomer @name";
        private const string DELETE = "DeleteCustomer @customerId";
        //private const string SELECT_CUSTOMER = "select * from Customer";
        public static bool CheckCustomerId(int customerId)
        {
            bool check = false;
            //mo ket noi
            SqlConnection conn = Common.GetSqlConnection();
            conn.Open();
            //truy van
            SqlCommand cmd = Common.GetSqlCommand(SELECT_ALLCUSTOMER, conn);
            SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (customerId == (int)dataReader["customer_id"])
                {
                    check = true;
                    break;
                }
            }
            return check;
        }

        public  List<Order> GetAllOrdersByCustomerId(int CustomerId)
        {
            SqlConnection conn = Common.GetSqlConnection();
            conn.Open();

            SqlCommand cmd = Common.GetSqlCommand("select * from Orders where customer_id = @customerID", conn);

            cmd.Parameters.Add("@customerID", SqlDbType.Int);
            cmd.Parameters["@customerID"].Value = CustomerId;
            SqlDataReader dataReader = cmd.ExecuteReader();

            List<Order> list = new List<Order>();
            while (dataReader.Read())
            {
                Order lineItem = new Order(
                    dataReader.GetInt32("order_id"),
                    dataReader.GetDateTime("order_date"),
                    dataReader.GetInt32("customer_id"),
                    dataReader.GetInt32("employee_id"),
                    dataReader.GetDouble("total"));
                list.Add(lineItem);
            }
            return list;
        }

        public List<Customer> GetAllCustomer()
        {
            SqlConnection conn = Common.GetSqlConnection();
            conn.Open();

            SqlCommand cmd = Common.GetSqlCommand(SELECT_ALLCUSTOMER, conn);

            SqlDataReader dataReader = cmd.ExecuteReader();

            List<Customer> list = new List<Customer>();
            while (dataReader.Read())
            {
                Customer lineItem = new Customer(dataReader.GetInt32("customer_id"),
                dataReader.GetString("customer_name"));
                list.Add(lineItem);
            }
            return list;
        }


        public bool AddCustomer(Customer customer)
        {
            SqlConnection conn = Common.GetSqlConnection();
            //mở kết nối
            conn.Open();
            //khai báo câu lệnh truy vấn 
            SqlCommand cmd = Common.GetSqlCommand(INSERT, conn);
            // su dung sql paramater
            SqlParameter parameter = new SqlParameter
            {
                ParameterName = "@name",
                Value = customer.CustomerName
            };
            // Thêm parameter vào SqlCommand
            cmd.Parameters.Add(parameter);

            if (cmd.ExecuteNonQuery() > 0) // câu lệnh ExecuteNonQuery trả về số dòng dữ liệu bị thay doi, != 0
                return true;
            return false;
        }

        public bool DeleteCustomer(int customerId)
        {
            if (CheckCustomerId(customerId) == true)
            {
                SqlConnection conn = Common.GetSqlConnection();
                conn.Open();

                SqlCommand cmd = Common.GetSqlCommand(DELETE, conn);

                SqlParameter parameter = new SqlParameter
                {
                    ParameterName = "@customerId",
                    Value = customerId
                };
                cmd.Parameters.Add(parameter);

                if (cmd.ExecuteNonQuery() > 0)
                    return true;
                return false;
            }
            else
            {
                Console.WriteLine("Khong ton tai CustomerId");
                return false;
            }
        }

        public bool UpdateCustomer (Customer customer)
        {
            if (CheckCustomerId(customer.CustomerId) == true)
            {
                using SqlConnection conn = Common.GetSqlConnection();
                //mo ket noi
                conn.Open();

                //SqlCommand tạo ra đối tượng mà từ đó có thể thi hành các lệnh
                using SqlCommand cmd = Common.GetSqlCommand(UPDATE, conn);

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@customer_id",customer.CustomerId),
                    new SqlParameter("@customer_name",customer.CustomerName)
                });

                //thuc thi cau lenh
                if (cmd.ExecuteNonQuery() > 0)
                {
                    return true;
                }    
                return false;
            }
            else
            {
                Console.WriteLine("Id Customer is not exist!!");
                return false;
            }
        }

    }
}
