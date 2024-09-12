using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using R2S.Training.Connection;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    class EmployeeDAO
    {
        private const string SELECT = "SELECT * FROM Employee";

        public static bool CheckEmployeeId(int employeeId)
        {
            bool check = false;

            using SqlConnection conn = Common.GetSqlConnection();

            conn.Open();

            using SqlCommand cmd = Common.GetSqlCommand(SELECT, conn);

            using SqlDataReader dataReader = cmd.ExecuteReader();

            while (dataReader.Read())
            {
                if (employeeId == (int)dataReader["employee_id"])
                {
                    check = true;
                }
            }
            return check;
        }
    }
}
