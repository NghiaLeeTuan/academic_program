using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using R2S.Training.Entities;
using System.Data;
using System.Data.SqlClient;
using R2S.Training.Connection;

namespace R2S.Training.Dao
{
    class CustomerDAO : ICustomerDAO
    {
        private const string SELECT_ALLCUSTOMER = "SELECT * FROM Customer WHERE customer_id IN (SELECT  customer_id FROM Orders)";
        private const string SELECT_CUSTOMER = "SELECT * FROM Customer";
        private const string SELECT_ALLORDERSBYCUSTOMER = "SELECT * FROM Orders WHERE customer_id = @CustomerId";
        private const string DELETE_CUSTOMER = "Delete_Customer @CustomerId";
        private const string ADD_CUSTOMER = "Add_Customer @CustomerName";
        private const string UPDATE_CUSTOMER = "Update_Customer @cus_id, @cus_name";

        //private bool e
        public List<Order> GetAllOrdersByCustomerId(int CustomerId)
        {
            SqlConnection conn = Comman.GetSqlConnection();
            //mo ket noi den SQL
            conn.Open();
            //Cau lenh thuc thi
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_ALLORDERSBYCUSTOMER, conn);

            cmd.Parameters.Add("@CustomerId", SqlDbType.Int);
            cmd.Parameters["@CustomerId"].Value = CustomerId;
            SqlDataReader dataReader = cmd.ExecuteReader();

            List<Order> list = new List<Order>();

            while (dataReader.Read())
            {
                Order lineItem = new Order {
                    OrderId = Convert.ToInt32(dataReader["order_id"]),
                    OrderDate = Convert.ToDateTime(dataReader["order_date"]),
                    CustomerId = Convert.ToInt32(dataReader["customer_id"]),
                    EmployeeId = Convert.ToInt32(dataReader["employee_id"]),
                    Total = Convert.ToSingle(dataReader["total"])
                };
                list.Add(lineItem);
            }
            return list;
        }
        public List<Customer> GetAllCustomer()
        {
            SqlConnection conn = Comman.GetSqlConnection();
            //mo ket noi den SQL
            conn.Open();
            //Cau lenh thuc thi
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_ALLCUSTOMER, conn);

            SqlDataReader dataReader = cmd.ExecuteReader();

            List<Customer> list = new List<Customer>();

            while (dataReader.Read())
            {
                Customer cus = new Customer(
                    (int)dataReader["customer_id"],
                    (string)dataReader["customer_name"]);
                list.Add(cus);
            }
            return list;
        }
        private static bool ExistCustomerId(int customerId)
        {
            bool check = false;
            //mo ket noi
            SqlConnection conn = Comman.GetSqlConnection();
            conn.Open();
            //truy van
            SqlCommand cmd = Comman.GetSqlCommand(SELECT_CUSTOMER, conn);
            SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (customerId == Convert.ToInt32(dataReader["customer_id"]))
                {
                    check = true;
                    break;
                }
            }
            return check;
        }

        public bool DeleteCustomer(int CustomerId)
        {
            if (ExistCustomerId(CustomerId))
            {
                SqlConnection conn = Comman.GetSqlConnection();
                //mo ket noi den SQL
                conn.Open();
                //Cau lenh thuc thi
                SqlCommand cmd = Comman.GetSqlCommand(DELETE_CUSTOMER, conn);
                SqlParameter parameter = new SqlParameter
                {
                    ParameterName = "@CustomerId",
                    Value = CustomerId
                };
                cmd.Parameters.Add(parameter);

                if (cmd.ExecuteNonQuery() > 0)
                    return true;
                else
                    return false;
            }
            else
            {
                Console.WriteLine("\tCustomer_id does not exist!!");
                return false;
            }
        }
        public bool AddCustomer(Customer Customer)
        {
            SqlConnection conn = Comman.GetSqlConnection();
            //mo ket noi den SQL
            conn.Open();
            //Cau lenh thuc thi
            SqlCommand cmd = Comman.GetSqlCommand(ADD_CUSTOMER, conn);
            SqlParameter parameter = new SqlParameter
            {
                ParameterName = "@CustomerName",
                Value = Customer.CustomerName
            };
            cmd.Parameters.Add(parameter);

            if (cmd.ExecuteNonQuery() > 0)
                return true;
            else
                return false;
        }
        public bool UpdateCustomer(Customer Customer)
        {
            if(ExistCustomerId(Customer.CustomerId))
            {
                SqlConnection conn = Comman.GetSqlConnection();
                //mo ket noi den SQL
                conn.Open();
                //Cau lenh thuc thi
                SqlCommand cmd = Comman.GetSqlCommand(UPDATE_CUSTOMER, conn);

                cmd.Parameters.AddRange(new[]
                {
                    new SqlParameter("@cus_id", Customer.CustomerId),
                    new SqlParameter("@cus_name", Customer.CustomerName)
                });

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
