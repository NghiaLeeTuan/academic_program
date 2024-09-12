using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CuoiKi.Class;

namespace CuoiKi
{
    public partial class HoaDon : Form
    {
        private int employee_id;
        public HoaDon(int id)
        {
            InitializeComponent();
            DowListItem();
            this.employee_id = id;
        }



        ThanhToan tt = new ThanhToan();
        ManagementDFContext db = new ManagementDFContext();
        List<C_Item> ListItem = new List<C_Item>();
        private void DowListItem()
        {
            ListItem = new List<C_Item>();
            foreach (var item in db.Items)
            {
                C_Item it = new C_Item(item.item_id, item.item_name,
                                       Convert.ToInt32(item.quantity_in_stock),
                                        Convert.ToDouble(item.item_price_in),
                                        Convert.ToDouble(item.item_price_out),
                                        item.expiry.ToString());
                ListItem.Add(it);
            }
        }
        private void HoaDon_Load(object sender, EventArgs e)
        {
            var result = ListItem.Select(s => s.Name);
            cbx_chon_item.DataSource = result.ToList();
            var item = ListItem.Select(s => s.Id);
            cbx_id.DataSource = item.ToList();
        }
       

        private void cbx_chon_item_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cbx_chon_item.SelectedItem != null)
            {
                var result = from c in ListItem 
                             where c.Name == cbx_chon_item.SelectedItem.ToString() 
                             select new 
                             { Mã = c.Id, Tên = c.Name,Giá=c.Price_out };
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
                    double Tongtien = sl * don_gia;
                    tt.Updatetotal(Tongtien);
                    Reset_Infor();
                    return;
                }
            }
            ListViewItem lvi = new ListViewItem(lbl_id.Text);
            lvi.SubItems.Add(lbl_ten_item.Text);
            lvi.SubItems.Add(tb_sl.Text);
            lvi.SubItems.Add(tb_dongia.Text);
            double tong = Convert.ToDouble(tb_sl.Text) * Convert.ToDouble(tb_dongia.Text);
            lvi.SubItems.Add(tong.ToString());
            lv_item.Items.Add(lvi);
            tt.Updatetotal(tong);
            Reset_Infor();
        }

        

        public event EventHandler TroVe;
        public bool isExit = true;
        private void btn_back_Click(object sender, EventArgs e)
        {
            isExit = false;
            TroVe(this, new EventArgs());
            this.Close();
            tt.Close();
        }
        public delegate void Exit(bool exit);
        public Exit exit;
        private void HoaDon_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (isExit)
            {                                                   
                 exit(true);
                 Application.Exit();
                tt.Close();
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

        private void btn_xoa_Click(object sender, EventArgs e)
        {
            if (lv_item.SelectedItems.Count > 0)
            {
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
                             where c.Id.ToString() == cbx_id.SelectedItem.ToString()
                             select new
                             { Mã = c.Id, Tên = c.Name, Giá = c.Price_out };
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
                var result = from it in db.Items
                             where it.item_id == id
                             select it;
                if (result != null)
                {
                    result.FirstOrDefault().quantity_in_stock -= sl;                 
                }
            }
        }
            
        private bool LuuHoaDon()
        {
            try
            {
                if (lv_item.Items.Count > 0)
                {
                    Update_Quantity();
                }
                else
                {
                    MessageBox.Show("Không có hàng hóa trong danh sách để lưu");
                    return false;
                }

                

                if (tt.check())
                {
                    MessageBox.Show("Vui lòng nhập tiền nhận và mã khách hàng");
                    return false;
                }
                
                return tt.Add_Database(lv_item) ;
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


        private void btn_new_hoadon_Click(object sender, EventArgs e)
        {
            lv_item.Items.Clear();
            Saved = false;
            
        }

        private void panel4_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }
    }
}
