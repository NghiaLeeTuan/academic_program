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
    public partial class NhanVien : Form
    {
        public bool isExit = true;
        public event EventHandler TroVe;
        ManagementDFContext db = new ManagementDFContext();
        public NhanVien()
        {
            InitializeComponent();
        }
       
        private void btn_back_Click(object sender, EventArgs e)
        {
            TroVe(this, new EventArgs());
            this.Close();
        }

        public delegate void Exit(bool exit);
        public Exit exit;
        private void NhanVien_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (isExit)
            {
                exit(true);
                Application.Exit();
            }
        }

        private void Reset_form()
        {
            txt_name.Text = "";
            txt_sdt.Text = "";
            txt_address.Text = "";
            txt_Job.Text = "";
        }

        private bool check()
        {
            if (txt_name.Text.Trim() == "" || txt_Job.Text.Trim() == "" || txt_address.Text.Trim() == "" || txt_sdt.Text.Trim() == "")
                return false;
            return true;
        }

        private void NhanVien_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (isExit)
            {
                if (MessageBox.Show("Bạn có muốn đóng form", "Thông báo", MessageBoxButtons.YesNo) != DialogResult.Yes)
                {
                    e.Cancel = true;
                }
            }
        }


        private void LoadData()
        {
            lv_nhanvien.Items.Clear();
            foreach (var row in db.Employees)
            {
                ListViewItem lvi = new ListViewItem(row.employee_id.ToString());
                lvi.SubItems.Add(row.employee_name);
                lvi.SubItems.Add(row.phone);
                lvi.SubItems.Add(row.address);
                lvi.SubItems.Add(row.birth.ToString());
                lvi.SubItems.Add(row.shift);
                lvi.SubItems.Add(row.salary.ToString());
                lv_nhanvien.Items.Add(lvi);
            }
        }


        private void NhanVien_Load(object sender, EventArgs e)
        {
            //Đưa vào ListView  
            LoadData();
        }

        private void lv_nhanvien_SelectedIndexChanged(object sender, EventArgs e)
        {
            int i = lv_nhanvien.SelectedItems.Count;
            if (i > 0)
            {
                foreach (ListViewItem lvi in lv_nhanvien.SelectedItems)
                {
                    txt_name.Text = lvi.SubItems[1].Text;
                    txt_sdt.Text = lvi.SubItems[2].Text;
                    txt_address.Text = lvi.SubItems[3].Text;
                    dt_birth.Text = lvi.SubItems[4].Text;
                    txt_Job.Text = lvi.SubItems[5].Text;
                }
            }
            if (txt_Job.Text.Trim() == "")
            {
                txt_Job.Enabled = false;
            }
            else
                txt_Job.Enabled = true;
        }

        private void btn_them_Click(object sender, EventArgs e)
        {
            try
            {
                if (check())
                {
                    DialogResult f = MessageBox.Show("Ban co chac muon them nhan vien nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                    if (f == DialogResult.Yes)
                    {
                        Account acc = new Account()
                        {
                            Name = txt_name.Text,
                            Account1 = txt_name.Text,
                            Password = 1.ToString(),
                            Position = "Employee",

                        };
                        db.Accounts.Add(acc);
                        Employee employee = new Employee()
                        {
                            employee_account = txt_name.Text,
                            employee_name = txt_name.Text,
                            phone = txt_sdt.Text,
                            birth = dt_birth.Value.Date,
                            address = txt_address.Text,
                            shift = txt_Job.Text,
                            salary = 30000
                        };
                        db.Employees.Add(employee);
                        db.SaveChanges();
                    }
                    Reset_form();
                    LoadData();
                }
                else
                    MessageBox.Show("Vui long nhap day du thong tin!!");
            }
            catch
            {
                MessageBox.Show("Thong tin khong hop le!!");
            }
        }

        private void btn_xoa_Click(object sender, EventArgs e)
        {

            try
            {
                if (check())
                {
                    if (lv_nhanvien.SelectedItems.Count > 0)
                    {
                        DialogResult f = MessageBox.Show("Ban co chac muon xoa nhan vien nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                        if (f == DialogResult.Yes)
                        {
                            foreach (ListViewItem lvi in lv_nhanvien.SelectedItems)
                            {
                                int id = int.Parse(lvi.SubItems[0].Text.ToString());

                                var employee = from u in db.Employees where u.employee_id == id select u;
                                string account = employee.FirstOrDefault().employee_account;
                                employee.FirstOrDefault().employee_account = null;
                                employee.FirstOrDefault().shift = null;
                                employee.FirstOrDefault().salary = null;

                                var acc = db.Accounts.Find(account);
                                db.Accounts.Remove(acc);
                                db.SaveChanges();
                            }
                            LoadData();
                        }
                    }
                    else
                        MessageBox.Show("Vui long chon hang can xoa!!");
                    lv_nhanvien.SelectedItems.Clear();
                    Reset_form();
                }
                else
                    MessageBox.Show("Vui long nhap day du thong tin!!");
            }
            catch
            {
                MessageBox.Show("Thong tin khong hop le!!");
            }
        }

        private void btn_sua_Click(object sender, EventArgs e)
        {
            try
            {
                if (check())
                {
                    if (lv_nhanvien.SelectedItems.Count > 0)
                    {
                        DialogResult f = MessageBox.Show("Ban co chac muon sua nhan vien nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                        if (f == DialogResult.Yes)
                        {
                            foreach (ListViewItem lvi in lv_nhanvien.SelectedItems)
                            {
                                int id = int.Parse(lvi.SubItems[0].Text.ToString());
                                string name = Convert.ToString(lvi.SubItems[1].Text.ToString());
                                var employee = from u in db.Employees where u.employee_id == id select u;
                                employee.FirstOrDefault().employee_name = txt_name.Text;
                                employee.FirstOrDefault().phone = txt_sdt.Text;
                                employee.FirstOrDefault().address = txt_address.Text;
                                employee.FirstOrDefault().birth = dt_birth.Value.Date;
                                employee.FirstOrDefault().shift = txt_Job.Text;

                                var acc = from a in db.Accounts where a.Name == name select a;
                                acc.FirstOrDefault().Name = txt_name.Text;

                                db.SaveChanges();
                            }
                            LoadData();
                        }
                    }
                    else
                        MessageBox.Show("Vui long chon hang can chinh sua!!");
                    lv_nhanvien.SelectedItems.Clear();
                    Reset_form();
                }
                else
                    MessageBox.Show("Vui long nhap day du thong tin!!");
            }
            catch
            {
                MessageBox.Show("Thong tin khong hop le!!");
            }
        }
    }
}
