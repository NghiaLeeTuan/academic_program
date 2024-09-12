using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using R2S.Training.Entities;

namespace R2S.Training.Dao
{
    interface ICustomerDAO
    {
        List<Customer> GetAllCustomer();
        List<Order> GetAllOrdersByCustomerId(int customerId);
        bool DeleteCustomer(int CustomerId);
        bool AddCustomer(Customer Customer);
        bool UpdateCustomer(Customer Customer);

    }
}
