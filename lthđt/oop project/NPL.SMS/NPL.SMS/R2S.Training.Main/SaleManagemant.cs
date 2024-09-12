using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using R2S.Training.Entities;
using System.Data.SqlClient;
using R2S.Training.Dao;

namespace R2S.Training.Main
{
    class SaleManagemant
    {
        private static void Menu()
        {
            Console.WriteLine("\t====================Menu====================");
            Console.WriteLine("\t0. Exit!!");
            Console.WriteLine("\t1. Get All Customer have Order");
            Console.WriteLine("\t2. Get All Orders by CustomerId");
            Console.WriteLine("\t3. Get All LineItem by OrderId");
            Console.WriteLine("\t4. Compute Order Total");
            Console.WriteLine("\t5. Add Customer");
            Console.WriteLine("\t6. Delete Customer");
            Console.WriteLine("\t7. Update Customer");
            Console.WriteLine("\t8. Add Order");
            Console.WriteLine("\t9. Add LineItem");
            Console.WriteLine("\t10. Update total");
            Console.WriteLine("\t============================================");
        }
        static void Main(string[] args)
        {
            OrderDAO order = new OrderDAO();
            CustomerDAO customer = new CustomerDAO();
            LineItemDAO lineItem = new LineItemDAO();
            int Choice;
            try
            {
                do
                {
                    Menu();
                    Console.Write("\tYour Choice: ");
                    Choice = Int32.Parse(Console.ReadLine());
                    if (Choice == 1)
                    {
                        List<Customer> ListCustomer = customer.GetAllCustomer();
                        Console.WriteLine("\tCustomerId\tCustomerName");
                        foreach (Customer cus in ListCustomer)
                        {
                            Console.WriteLine("\t" + cus.CustomerId + "\t\t" + cus.CustomerName);
                        }
                    }
                    else if (Choice == 2)
                    {
                        int CustomerId;
                        Console.Write("\tCustomer_id: ");
                        CustomerId = Convert.ToInt32(Console.ReadLine());
                        List<Order> ListOrder = customer.GetAllOrdersByCustomerId(CustomerId);
                        if (ListOrder.Count == 0)
                            Console.WriteLine("\tList Is Empty!!");
                        else
                        {
                            Console.WriteLine("\tOrderId\t\tOrderDate\t\tCustomerId\tEmployeeId\tTotal");
                            foreach (Order Ord in ListOrder)
                            {
                                Console.WriteLine("\t" + Ord.OrderId + "\t\t" + Ord.OrderDate + "\t" + Ord.CustomerId + "\t\t" + Ord.EmployeeId + "\t\t" + Ord.Total);
                            }
                        }
                    }
                    else if (Choice == 3)
                    {
                        int OrderId;
                        Console.Write("\tOrder_id: ");
                        OrderId = Convert.ToInt32(Console.ReadLine());
                        List<LineItem> ListItem = order.GetAllItemsByOrderId(OrderId);
                        if (ListItem.Count == 0)
                            Console.WriteLine("\tList Is Empty!!");
                        else
                        {
                            Console.WriteLine("\tOrderId\t\tProductId\tQuantity\tPrice");
                            foreach (LineItem Item in ListItem)
                            {
                                Console.WriteLine("\t" + Item.OrderId + "\t\t" + Item.ProductId + "\t\t" + Item.Quantity + "\t\t" + Item.Price);
                            }
                        }
                    }
                    else if (Choice == 4)
                    {
                        int OrderId;
                        Console.Write("\tOrder_id: ");
                        OrderId = Convert.ToInt32(Console.ReadLine());
                        Double Total_price = order.ComputeOrderTotal(OrderId);
                        if (Total_price != 0)
                            Console.WriteLine("\tTotal_price: " + Total_price);
                        else
                            Console.WriteLine("\tCompute Failed!!");
                    }
                    else if(Choice==5)
                    {
                        Customer Customer = new Customer();
                        Console.Write("\tCustomer_name: ");
                        Customer.CustomerName = Convert.ToString(Console.ReadLine());
                        if (customer.AddCustomer(Customer))
                        {
                            Console.WriteLine("\tAdd Successfully !!");
                        }
                        else
                        {
                            Console.WriteLine("\tAdd Failed!!");
                        }
                    }
                    else if (Choice == 6)
                    {
                        int CustomerId;
                        Console.Write("\tCustomer_id: ");
                        CustomerId = Convert.ToInt32(Console.ReadLine());
                        if (customer.DeleteCustomer(CustomerId))
                        {
                            Console.WriteLine("\tDelete Successfully !!");
                        }
                        else
                        {
                            Console.WriteLine("\tDelete Failed!!");
                        }
                    }
                    else if (Choice == 7)
                    {
                        try
                        {
                            Customer Customer = new Customer();
                            Console.Write("\tCustomer_id: ");
                            Customer.CustomerId = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\tCustomer_name: ");
                            Customer.CustomerName = Console.ReadLine();
                            if (customer.UpdateCustomer(Customer))
                            {
                                Console.WriteLine("\tUpdate Successfully !!");
                            }
                            else
                            {
                                Console.WriteLine("\tUpdate Failed!!");
                            }
                        }
                        catch(Exception ex)
                        {
                            Console.WriteLine(ex.Message);
                        }
                    }
                    else if (Choice == 8)
                    {
                        Order Order = new Order();
                        Order.Input();
                        if (order.AddOrder(Order))
                        {
                            Console.WriteLine("\tAdd Successfully !!");
                        }
                        else
                        {
                            Console.WriteLine("\tAdd Failed!!");
                        }
                    }
                    else if (Choice == 9)
                    {
                        LineItem item = new LineItem();
                        Console.Write("\tOrder_id: ");
                        item.OrderId = Convert.ToInt32(Console.ReadLine());
                        Console.Write("\tProduct_id: ");
                        item.ProductId = Convert.ToInt32(Console.ReadLine());
                        Console.Write("\tQuantity: ");
                        item.Quantity = Convert.ToInt32(Console.ReadLine());
                        Console.Write("\tPrice: ");
                        item.Price = Convert.ToSingle(Console.ReadLine());
                        if (lineItem.AddLineItem(item) == true)
                            Console.WriteLine("\tAdd successfully !!");
                        else
                            Console.WriteLine("\tAdd failed !!");
                    }
                    else if (Choice == 10)
                    {
                        try
                        {
                            int orderId;
                            Console.Write("\tOrder_id: ");
                            orderId = Convert.ToInt32(Console.ReadLine());
                            if (order.UpdateOrderTotal(orderId))
                                Console.WriteLine("\tUpdate successfully !!");
                            else
                                Console.WriteLine("\tUpdate failed !!");
                        }
                        catch(Exception ex)
                        {
                            Console.WriteLine(ex.Message);
                        }
                    }
                    else if (Choice == 0)
                    {
                        Console.WriteLine("\tExited !!!");
                        break;
                    }
                } while (Choice != 0);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadKey();
        }
    }
}