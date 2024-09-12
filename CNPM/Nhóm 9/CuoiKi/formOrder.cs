﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;


using CuoiKi.BLL;

namespace CuoiKi
{
    public partial class formOrder : Form
    {
        private int employee_id;
        List<Item> ListItem;
        private double TongTien = 0;
        private int Order_ID;
        public formOrder(int id)
        {
            InitializeComponent();
            ListItem = ItemBLL.Instance.Get_ListItem();
            this.employee_id = id;
        }

        

        private void Load_ComboBox()
        {
           
            var result = ListItem.Select(s => s.item_name);
            cbx_chon_item.DataSource = result.ToList();
            var item = ListItem.Select(s => s.item_id);
            cbx_id.DataSource = item.ToList();

        }
        private void HoaDon_Load(object sender, EventArgs e)
        {
            Load_ComboBox();
           
        }
       public event EventHandler TroVe;
        public bool isExit = true;
        private void btn_back_Click(object sender, EventArgs e)
        {
            isExit = false;
            TroVe(this, new EventArgs());
            this.Close();   
        }
        public delegate void Exit(bool exit);
        public Exit exit;
        private void HoaDon_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (isExit)
            {                                                   
                 exit(true);
                 Application.Exit();                   
            }    
        }
        private void HoaDon_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(isExit)
            {
                if (MessageBox.Show("Bạn có muốn đóng form", "Thông báo", MessageBoxButtons.YesNo) != DialogResult.Yes)
                {
                    e.Cancel = true;
                }
            }    
        }

        private void cbx_chon_item_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cbx_chon_item.SelectedItem != null)
            {
                var result = from c in ListItem 
                             where c.item_name == cbx_chon_item.SelectedItem.ToString() 
                             select new 
                             { Mã = c.item_id, Tên = c.item_name,Giá=c.item_price_out };
                result.ToList();
                lbl_id.Text = result.First().Mã.ToString();
                lbl_ten_item.Text = result.First().Tên;
                tb_sl.Text = "1";
                tb_dongia.Text = result.First().Giá.ToString();
            }
        }
        void Reset_Infor()
        {
            lbl_id.Text = "";
            lbl_ten_item.Text = "";
            tb_sl.Text = "";
            tb_dongia.Text = "";
        }
        
        private void btn_them_Click(object sender, EventArgs e)
        {
            if (lbl_id.Text == "")
                return;
            foreach (ListViewItem it in lv_item.Items)
            {
                if (it.Text == lbl_id.Text)
                {
                    double sl = Convert.ToDouble(tb_sl.Text);
                    double don_gia = Convert.ToDouble(tb_dongia.Text);

                    double new_sl = sl + Convert.ToDouble(it.SubItems[2].Text);
                    double new_Tong =new_sl * don_gia;
                    it.SubItems[2].Text = new_sl.ToString();//Update lại số lượng
                    it.SubItems[4].Text = new_Tong.ToString();//Update lại Tổng cộng
                    TongTien += sl * don_gia;//Update lại tổng tiền
                    lbl_TongCong.Text = TongTien.ToString();
                    Reset_Infor();
                    return;
                }
            }
            ListViewItem lvi = new ListViewItem(lbl_id.Text);
            lvi.SubItems.Add(lbl_ten_item.Text);
            lvi.SubItems.Add(tb_sl.Text);
            lvi.SubItems.Add(tb_dongia.Text);
            double tong = Convert.ToDouble(tb_sl.Text) * Convert.ToDouble(tb_dongia.Text);
            TongTien += tong;
            lvi.SubItems.Add(tong.ToString());
            lv_item.Items.Add(lvi);
            lbl_TongCong.Text = TongTien.ToString();
            Reset_Infor();
        }

        

        
        
        private void btn_xoa_Click(object sender, EventArgs e)
        {
            if (lv_item.SelectedItems.Count > 0)
            {
                double mon = Convert.ToDouble(lv_item.SelectedItems[0].SubItems[4].Text);
                TongTien -= mon;
                lbl_TongCong.Text = TongTien.ToString();
                lv_item.Items.Remove(lv_item.SelectedItems[0]);
            }
            else
                MessageBox.Show("Chon item de xoa!");
        }

        private void cbx_id_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cbx_id.SelectedItem != null)
            {
                var result = from c in ListItem
                             where c.item_id.ToString() == cbx_id.SelectedItem.ToString()
                             select new
                             { Mã = c.item_id, Tên = c.item_name, Giá = c.item_price_out };
                result.ToList();
                lbl_id.Text = result.First().Mã.ToString();
                lbl_ten_item.Text = result.First().Tên;
                tb_sl.Text = "1";
                tb_dongia.Text = result.First().Giá.ToString();
            }
        }
        private void Update_Quantity()
        {
            foreach (ListViewItem item in lv_item.Items)
            {
                int id = Convert.ToInt32(item.SubItems[0].Text);
                int sl = Convert.ToInt32(item.SubItems[2].Text);
                OrderBLL.Instance.Update_Quantity(id, sl);
            }
        }
        private bool Add_Database()
        {
            // Add_Customer and order           
            if (tb_tenkhach.Text == "" || tbx_diachi.Text == "")
            {
                MessageBox.Show("Vui lòng nhập đầy đủ thông tin khách hàng");
                return false;
            }
            Customer customer = new Customer()
            {
                customer_id = Convert.ToInt32(tbx_ma_kh.Text)
                                             ,
                customer_name = tb_tenkhach.Text
                                             ,
                customer_address = tbx_diachi.Text
                                             ,
                tolal = TongTien
            };
            
            Order order = new Order() { order_date = DateTime.Now
                                        ,customer_id=Convert.ToInt32(tbx_ma_kh.Text)
                                        ,employee_id=employee_id
                                        ,total=TongTien };


            OrderBLL.Instance.Add_Order(order, customer);
            Order_ID = OrderBLL.Instance.Get_Order_ID();
            /// Add LineItem           
            foreach (ListViewItem item in lv_item.Items)
            {
                int item_id = Convert.ToInt32(item.SubItems[0].Text);
                int sl = Convert.ToInt32(item.SubItems[2].Text);
                OrderBLL.Instance.Add_LineItem(item_id, sl);
            }
            OrderBLL.Instance.Save_DB();
            return true;
        }
        
        
        private bool LuuHoaDon()
        {
            try
            {
                if (lv_item.Items.Count > 0)
                {
                    if (tbx_ma_kh.Text == "" || tb_tiennhan.Text == "")
                    {
                        MessageBox.Show("Vui lòng nhập tiền nhận và mã khách hàng");
                        return false;
                    }
                    if (Add_Database() == true)
                    {
                        Update_Quantity();
                        return true;
                    }    
                    else
                        return false;
                }
                else
                {
                    MessageBox.Show("Không có hàng hóa trong danh sách để lưu");
                    return false;
                }               
            }
            catch
            {
                MessageBox.Show("Lưu hóa đơn thất bại");
                return false;
            }
            
        }

        private bool Saved = false;
        private void btn_luu_Click(object sender, EventArgs e)
        {


            if (Saved == false)
            {

                if (MessageBox.Show("Bạn Muốn lưu hóa đơn", "Thông Báo", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                    if (LuuHoaDon() == true)
                    {
                        Saved = true;
                        MessageBox.Show("Đã lưu hóa đơn");
                    }                   
                }
            }
            else
                MessageBox.Show("Hóa đơn đã được lưu");
        }

        private void btn_thanhtoan_Click(object sender, EventArgs e)
        {
            if(tb_tiennhan.Text!="")
            {
                double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - Convert.ToDouble(lbl_thanhtien.Text);
                if(tien_thua < 0)
                {
                    MessageBox.Show("Số tiền không đủ!!");
                    return;
                }
                TongTien = Convert.ToDouble(lbl_thanhtien.Text);
                lbl_tienthua.Text = tien_thua.ToString();
            }
            else
            {
                MessageBox.Show("Bạn chưa nhập tiền nhận!");
            }    
        }

        private void btn_new_hoadon_Click(object sender, EventArgs e)
        {
            lv_item.Items.Clear();
            Saved = false;



        }
        private void Compute_Total(double price)
        {
            TongTien -= price;
            lbl_giam.Text = price.ToString();
            lbl_thanhtien.Text = TongTien.ToString();
            double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - TongTien;
            lbl_tienthua.Text = tien_thua.ToString();
        }
        private void ReLoad()
        {
            TongTien = Convert.ToDouble(lbl_TongCong.Text);
            lbl_thanhtien.Text = TongTien.ToString();
            lbl_giam.Text = "0";
            double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - TongTien;
            lbl_tienthua.Text = tien_thua.ToString();
            tbx_diachi.Text = "";
            tb_tenkhach.Text = "";
        }
        private void tbx_ma_kh_TextChanged(object sender, EventArgs e)
        {
            try
            {              
                ReLoad();                   
                Customer cus = OrderBLL.Instance.Get_Customer_Infor(int.Parse(tbx_ma_kh.Text));
                if (cus != null)
                {
                    tb_tenkhach.Text = cus.customer_name;
                    tbx_diachi.Text = cus.customer_address;
                    double discount;
                    if(cus.tolal >= 100000)
                    {
                        discount = TongTien * 0.05;
                        Compute_Total(discount);
                    }
                    else if(cus.tolal >= 500000)
                    {
                        discount = TongTien * 0.1;
                        Compute_Total(discount);
                    }
                    else if(cus.tolal >= 1000000)
                    {
                        discount = TongTien * 0.15;
                        Compute_Total(discount);
                    }
                    else
                    {
                        Compute_Total(0);
                    }    
                }
                else
                {
                    ReLoad();

                }    
            }
            catch
            {
                return;
            }
        }

        private void tb_tiennhan_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (tb_tiennhan.Text == "")
                    return;
                double tien_thua = Convert.ToDouble(tb_tiennhan.Text) - Convert.ToDouble(lbl_TongCong.Text);
                if(tien_thua > 0 )
                {
                    lbl_thanhtien.Text = TongTien.ToString();
                    lbl_tienthua.Text = tien_thua.ToString();
                }
                
            }
            catch
            {
                MessageBox.Show("Vui lòng nhập số");
            }
        }
        
        public void InHoaDon()
        {
            string filePath = "";
            // tạo SaveFileDialog để lưu file excel
            SaveFileDialog dialog = new SaveFileDialog();
                
            // chỉ lọc ra các file có định dạng Excel
            dialog.Filter = "Excel | *.xlsx | Excel 2003 | *.xls";
            dialog.Title = "Hóa Đơn " + OrderBLL.Instance.Get_Order_ID().ToString();
            //Nếu mở file và chọn nơi lưu file thành công sẽ lưu đường dẫn lại dùng
            if (dialog.ShowDialog() == DialogResult.OK)
            {

                filePath = dialog.FileName;
            }

            // nếu đường dẫn null hoặc rỗng thì báo không hợp lệ và return hàm
            if (string.IsNullOrEmpty(filePath))
            {
                MessageBox.Show("Đường dẫn báo cáo không hợp lệ");
                return;
            }

            Microsoft.Office.Interop.Excel.Application exApp;
            Microsoft.Office.Interop.Excel.Workbook workBook;
            Microsoft.Office.Interop.Excel.Worksheet workSheet;
            try
            {
                //Tạo đối tượng COM.
                exApp = new Microsoft.Office.Interop.Excel.Application();
                exApp.Visible = false;
                exApp.DisplayAlerts = false;
                //workBook = exApp.Workbooks.Add(Microsoft.Office.Interop.Excel.XlWBATemplate.xlWBATWorksheet);

                workBook = exApp.Workbooks.Add(Type.Missing);
                workSheet = (Microsoft.Office.Interop.Excel.Worksheet)workBook.Sheets["Sheet1"];

                workSheet.Name = "Hóa đơn bán hàng";
                workSheet.Cells.Style.Font.Size = 12;
                workSheet.Cells.Style.Font.Name = "Calibri";

                workSheet.Cells[1, 1].Value = "Cửa Hàng Tiện Lợi";
                workSheet.Cells[1, 1].Font.Size = 14;
                workSheet.Cells[1, 1].Font.Bold = true;
                workSheet.Cells[2, 1].Value = "Địa Chỉ: Thủ Đức, Hồ Chí Minh";
                workSheet.Cells[3, 1].Value = "Điện thoại: 1234567";
                workSheet.Cells[4, 1].Value = "HÓA ĐƠN BÁN HÀNG";
                workSheet.Cells[4, 1].Font.Size = 20;
                workSheet.Cells[4, 1].Font.Bold = true;

                workSheet.Cells[5, 1].Value = "Ngày xuất phiếu:";
                workSheet.Cells[5, 1].Font.Bold = true;
                workSheet.Cells[5, 3].Value = DateTime.Now;

                workSheet.Cells[6, 1].Value = "Mã hóa đơn:";
                workSheet.Cells[6, 1].Font.Bold = true;
                workSheet.Cells[6, 3].Value = OrderBLL.Instance.Get_Order_ID().ToString();

                workSheet.Cells[7, 1].Value = "Mã khách hàng:";
                workSheet.Cells[7, 1].Font.Bold = true;
                workSheet.Cells[7, 3].Value = tbx_ma_kh.Text;

                workSheet.Cells[8, 1].Value = "Tên khách hàng:";
                workSheet.Cells[8, 1].Font.Bold = true;
                workSheet.Cells[8, 3].Value = tb_tenkhach.Text;

                workSheet.Cells[9, 1].Value = "Địa chỉ:";
                workSheet.Cells[9, 1].Font.Bold = true;
                workSheet.Cells[9, 3].Value = tbx_diachi.Text;

                workSheet.Cells[10, 1].Value = "Nhân viên:";
                workSheet.Cells[10, 1].Font.Bold = true;
                workSheet.Cells[10, 3].Value = EmployeeBLL.Instance.Get_Employee_Name(employee_id);

                workSheet.Cells[11, 1].Value = "Tổng cộng:";
                workSheet.Cells[11, 1].Font.Bold = true;
                workSheet.Cells[11, 3].Value = lbl_TongCong.Text;

                workSheet.Cells[12, 1].Value = "Giảm:";
                workSheet.Cells[12, 1].Font.Bold = true;
                workSheet.Cells[12, 3].Value = lbl_giam.Text;

                workSheet.Cells[13, 1].Value = "Thành tiền:";
                workSheet.Cells[13, 1].Font.Bold = true;
                workSheet.Cells[13, 3].Value = lbl_thanhtien.Text;

                workSheet.Cells[14, 1].Value = "Tiền nhận:";
                workSheet.Cells[14, 1].Font.Bold = true;
                workSheet.Cells[14, 3].Value = tb_tiennhan.Text;

                workSheet.Cells[15, 1].Value = "Tiền thừa:";
                workSheet.Cells[15, 1].Font.Bold = true;
                workSheet.Cells[15, 3].Value = lbl_tienthua.Text;

                for (int i = 1; i < lv_item.Columns.Count; i++)
                {                    
                    workSheet.Cells[17, i] = lv_item.Columns[i].Text;
                    workSheet.Cells[17, i].Font.Bold = true;
                    workSheet.Cells[17, i].Borders.LineStyle = true;                                     
                    workSheet.Cells[17, i].ColumnWidth = 15;
                  
                }

                int lasti = 0, lastj = 0;
                for (int i = 0; i < lv_item.Items.Count; i++)
                {
                    lasti = i;
                    for (int j = 1; j < lv_item.Columns.Count; j++)
                    {
                        lastj = j;
                        workSheet.Cells[i + 18, j] = lv_item.Items[i].SubItems[j].Text;
                        workSheet.Cells[i + 18, j].Borders.LineStyle = true;
                    }
                }
                workSheet.Cells[lasti + 19, lastj - 1] = "Tổng tiền:";
                workSheet.Cells[lasti + 19, lastj] = lbl_TongCong.Text;

                workBook.Activate();
                workBook.SaveAs(filePath);
                workBook.Save();
                workBook.Close();
                exApp.Quit();
                bool flag = SaveAsPdf(filePath);
                MessageBox.Show("Xuất dữ liệu ra Excel thành công!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                workBook = null;
                workSheet = null;
            }
        }
        private bool SaveAsPdf(string saveAsLocation)
        {
            string saveas = (saveAsLocation.Split('.')[0]) + ".pdf";
            try
            {
                Spire.Xls.Workbook workbook = new Spire.Xls.Workbook();
                workbook.LoadFromFile(saveAsLocation);

                //Save the document in PDF format
                workbook.SaveToFile(saveas, Spire.Xls.FileFormat.PDF);
                System.Diagnostics.Process.Start(saveas);
                Path.GetTempPath();
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }
        
        private void In_hoadon_Click(object sender, EventArgs e)
        {
            if (Saved == true)
                InHoaDon();
            else
                MessageBox.Show("Bạn chưa lưu hóa đơn này");

        }
    }
}
