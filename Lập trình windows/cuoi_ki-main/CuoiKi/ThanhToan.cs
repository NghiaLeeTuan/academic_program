using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CuoiKi
{
    public partial class ThanhToan : Form
    {
        ManagementDFContext db = new ManagementDFContext();
        private double TongTien = 0;
        private int employee_id;

        public ThanhToan()
        {
            InitializeComponent();
        }

        public ThanhToan(int id)
        {
            InitializeComponent();
            this.employee_id = id;
        }

        public bool check()
        {
            if (tbx_ma_kh.Text == "" || tb_tiennhan.Text == "")
                return false;
            return true;
        }

        private void ReLoad()
        {
            txt_Tongcong.Text = TongTien.ToString();
            double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - TongTien;
            lbl_tienthua.Text = tien_thua.ToString();
            tbx_diachi.Text = "";
            tb_tenkhach.Text = "";
        }


        internal void Updatetotal(double v)
        {
            TongTien += v;//Update lại tổng tiền
            ReLoad();
        }
        private void ThanhToan_Load(object sender, EventArgs e)
        {
            ReLoad();
        }

        private void pt_QR_Click(object sender, EventArgs e)
        {
            QRCoder.QRCodeGenerator test = new QRCoder.QRCodeGenerator();
            var check = test.CreateQrCode(txt_Tongcong.Text, QRCoder.QRCodeGenerator.ECCLevel.H);
            var code = new QRCoder.QRCode(check);
            pt_QR.Image = code.GetGraphic(50);
        }

        private void btn_thanhtoan_Click(object sender, EventArgs e)
        {
            if (tb_tiennhan.Text != "")
            {
                double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - Convert.ToDouble(txt_Tongcong.Text);
                if (tien_thua < 0)
                {
                    MessageBox.Show("Số tiền không đủ!!");
                    return;
                }
                TongTien = Convert.ToDouble(txt_Tongcong.Text);
                lbl_tienthua.Text = tien_thua.ToString();
            }
            else
            {
                MessageBox.Show("Bạn chưa nhập tiền nhận!");
            }
        }

        internal bool Add_Database(ListView lv_item)
        {
            // Add_Customer
            int cus_id = int.Parse(tbx_ma_kh.Text);
            var customer_id = from c in db.Customers
                              where c.customer_id == cus_id
                              select c;

            if (customer_id.Count() > 0)
            {
                customer_id.First().tolal += TongTien;
            }
            else
            {
                if (tb_tenkhach.Text == "" || tbx_diachi.Text == "")
                {
                    MessageBox.Show("Vui lòng nhập đầy đủ thông tin khách hàng");
                    return false;
                }
                db.Customers.Add(new Customer()
                {
                    customer_id = Convert.ToInt32(tbx_ma_kh.Text)
                                                 ,
                    customer_name = tb_tenkhach.Text
                                                 ,
                    customer_address = tbx_diachi.Text
                                                 ,
                    tolal = TongTien
                });
            }
            DateTime t = new DateTime(2022, 6, 20);
            /// Add_order
            Order order = new Order()
            {
                order_date = t
                                        ,
                customer_id = Convert.ToInt32(tbx_ma_kh.Text)
                                        ,
                employee_id = employee_id
                                        ,
                total = TongTien
            };


            db.Orders.Add(order);
            db.SaveChanges();
            /// Add LineItem
            var id = db.Orders.Select(c => c.order_id);
            foreach (ListViewItem item in lv_item.Items)
            {
                int item_id = Convert.ToInt32(item.SubItems[0].Text);
                int sl = Convert.ToInt32(item.SubItems[2].Text);
                db.Lineitems.Add(new Lineitem()
                {
                    order_id = id.ToList().Last()
                                                 ,
                    item_id = item_id
                                                 ,
                    quantity = sl
                });
            }
            db.SaveChanges();
            return true;
        }
    }
}
