using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using R2S.Training.Connection;
using R2S.Training.Entities;
using R2S.Training.Dao;

namespace R2S.Training.Main
{
    class SaleManagement
    {
        private static void CreateMenu()
        {
            Console.WriteLine("\n\t------------------MENU------------------");
            Console.WriteLine("\t 1. Get all Customer");
            Console.WriteLine("\t 2. Get all Orders");
            Console.WriteLine("\t 3. Get all Items");
            Console.WriteLine("\t 4. Compute Order Total");
            Console.WriteLine("\t 5. Add a customer");
            Console.WriteLine("\t 6. Delete a customer");
            Console.WriteLine("\t 7. Update a customer");
            Console.WriteLine("\t 8. Add a order");
            Console.WriteLine("\t 9. Add a LineItem and Update TotalOrder");
            Console.WriteLine("\t 10.Exit");
        }

        public static void Main(string[] args)
        {
            int choice;
            CustomerDAO customer = new CustomerDAO();
            OrderDAO order = new OrderDAO();
            LineItemDAO ld = new LineItemDAO();

            try
            {
                do
                {
                    CreateMenu();
                    choice = int.Parse(Console.ReadLine());
                    switch (choice)
                    {
                        case 1:
                            {
                                
                                //Customer cus = new Customer();
                                Console.WriteLine("Danh sách Customer: ");
                                //in List
                                List<Customer> listcus = customer.GetAllCustomer();
                                foreach (Customer cm in listcus)
                                {
                                    Console.WriteLine("\tCustomer_id: " + cm.CustomerId);
                                    Console.WriteLine("\tCustomer_name: " + cm.CustomerName);
                                }
                            }
                            break;
                        case 2:
                            {
                                Console.WriteLine("Nhập customer id: ");
                                int id;
                                id = Convert.ToInt32(Console.ReadLine());
                                //Order order = new Order();
                                Console.WriteLine("Danh sách Order: ");
                                id = Convert.ToInt32(Console.ReadLine());
                                List<Order> listOrder = customer.GetAllOrdersByCustomerId(id);
                                foreach (Order o in listOrder)
                                {
                                    Console.WriteLine("\torder_id: " + o.OrderId);
                                    Console.WriteLine("\torder_date: " + o.OrderDate);
                                    Console.WriteLine("\tCustomer_id: " + o.CustomerId);
                                    Console.WriteLine("\temployee_id: " + o.EmployeeId);
                                    Console.WriteLine("\ttotal: " + o.Total);
                                }
                            }
                            break;
                        case 3:
                            {
                                try
                                {
                                    Console.WriteLine("Nhập orderID: ");
                                    int id;
                                    id = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("Danh sách Item: ");
                                    List<LineItem> list = order.GetAllItemsByOrderId(id);
                                    foreach (LineItem lineItem in list)
                                    {

                                        Console.WriteLine("\tOrder id: " + lineItem.OrderId);
                                        Console.WriteLine("\tProduct id: " + lineItem.ProductId);
                                        Console.WriteLine("\tQuantity: " + lineItem.Quantity);
                                        Console.WriteLine("\tPrice: " + lineItem.Price + "\n");
                                    }

                                }
                                catch (Exception ex)
                                {
                                    Console.WriteLine(ex.Message);
                                }
                            }
                            break;
                        case 4:
                            {
                                try
                                {
                                    Console.WriteLine("Nhập orderID: ");
                                    int id;
                                    id = Convert.ToInt32(Console.ReadLine());

                                    Console.WriteLine("Total_price: " + order.ComputeOrderTotal(id) + "\n");
                                }
                                catch (Exception ex)
                                {
                                    Console.WriteLine(ex.Message);
                                }
                            }
                            break;
                        case 5:
                            {
                                Customer cm = new Customer();
                                cm.Input();
                                if (customer.AddCustomer(cm) == true)
                                {
                                    Console.WriteLine("Successfully !!");
                                }
                                Console.WriteLine("Failed !!");
                            }
                            break;
                        case 6:
                            {
                                Console.Write("Moi ban nhap ID cua khach hang: ");
                                int id = Convert.ToInt32(Console.ReadLine());
                                if (customer.DeleteCustomer(id) == true)
                                {
                                    Console.WriteLine("Successfully !!");
                                }
                                Console.WriteLine("Failed !!");
                            }
                            break;
                        case 7:
                            {
                                Customer cm = new Customer();
                                Console.Write("Enter id customer: ");
                                cm.CustomerId = int.Parse(Console.ReadLine());
                                cm.Input();
                                try
                                {
                                    if (customer.UpdateCustomer(cm) == true)
                                    {
                                        Console.WriteLine("Successfully !!");
                                    }
                                    Console.WriteLine("Failed !!");
                                }
                                catch (Exception ex)
                                {
                                    Console.WriteLine(ex.Message);
                                }
                            }
                            break;
                        case 8:
                            {
                                Order od = new Order();
                                od.Input();
                                try
                                {
                                    if (order.AddOrder(od) == true)
                                    {
                                        Console.WriteLine("Successfully !!");
                                    }
                                    Console.WriteLine("Failed !!");
                                }
                                catch (Exception ex)
                                {
                                    Console.WriteLine(ex.Message);
                                }
                            }
                            break;
                        case 9:
                            {
                                LineItem lineItem = new LineItem();
                                Order od = new Order();
                                lineItem.Input();
                                if (ld.AddLineItem(lineItem) == true)
                                {
                                    Console.WriteLine("Successfully !!");
                                }
                                Console.WriteLine("Failed !!");
                                order.UpdateOrderTotal(od.OrderId);
                            }
                            break;
                        case 10:
                            {
                                Order od = new Order();
                                order.UpdateOrderTotal(od.OrderId);
                                if (order.UpdateOrderTotal(od.OrderId) == true)
                                {
                                    Console.WriteLine("Successfully !!");
                                }
                                Console.WriteLine("Failed !!");
                            }
                            break;
                        case 0:
                            break;
                        default:
                            {
                                Console.WriteLine("Your choice is invalid!!");
                            }
                            break;
                    }
                } while (choice != 0);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
