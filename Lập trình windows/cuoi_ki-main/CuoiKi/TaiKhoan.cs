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
    public partial class TaiKhoan : Form
    {
        public TaiKhoan()
        {
            InitializeComponent();
        }
        ManagementDFContext db = new ManagementDFContext();
        public bool isExit = true;
        public event EventHandler TroVe;
        private void btn_back_Click(object sender, EventArgs e)
        {
            TroVe(this, new EventArgs());
            this.Close();
        }
        public delegate void Exit(bool exit);
        public Exit exit;
        private void Account_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (isExit)
            {
                exit(true);
                Application.Exit();
            }
        }

        private void TaiKhoan_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (isExit)
            {
                if (MessageBox.Show("Bạn có muốn đóng form", "Thông báo", MessageBoxButtons.YesNo) != DialogResult.Yes)
                {
                    e.Cancel = true;
                }
            }
        }

        private bool check()
        {
            if (tbx_mk.Text.Trim() == "" || tbx_ten.Text.Trim() == "" || tbx_tk.Text.Trim() == "" || cbx_cv.Text.Trim() == "")
                return false;
            return true;
        }

        private void Reset_form()
        {
            tbx_ten.Text = "";
            tbx_tk.Text = "";
            cbx_cv.Text = "Admin";
            tbx_mk.Text = "";
        }


        private void Load_data()
        {
            var result = from acc in db.Accounts
                         select new
                         {
                             Tên = acc.Name
                                     ,
                             Account = acc.Account1
                                     ,
                             Password = acc.Password
                                     ,
                             Chức_vụ = acc.Position
                         };

            dgv_account.DataSource = result.ToList();
            cbx_cv.Text = "Admin";
            cbx_cv.Enabled = false;
        }

        private void TaiKhoan_Load(object sender, EventArgs e)
        {
            Load_data();
        }
        private void Load_infor(int i)
        {
            tbx_ten.Text = dgv_account.Rows[i].Cells[0].Value.ToString();
            tbx_tk.Text = dgv_account.Rows[i].Cells[1].Value.ToString();
            tbx_mk.Text = dgv_account.Rows[i].Cells[2].Value.ToString();
            cbx_cv.Text = dgv_account.Rows[i].Cells[3].Value.ToString();
        }
        

        private void dgv_account_SelectionChanged(object sender, EventArgs e)
        {
            if (dgv_account.SelectedRows.Count > 0)
            {
                int i = dgv_account.CurrentCell.RowIndex;
                tbx_ten.Text = dgv_account.Rows[i].Cells[0].Value.ToString();
                tbx_tk.Text = dgv_account.Rows[i].Cells[1].Value.ToString();
                tbx_mk.Text = dgv_account.Rows[i].Cells[2].Value.ToString();
                cbx_cv.Text = dgv_account.Rows[i].Cells[3].Value.ToString();
            }
            if (cbx_cv.Text == "Employee")
            {
                tbx_ten.Enabled = false;
            }
            else
            {
                tbx_ten.Enabled = true;
            }
        }

        private void btn_thm_Click(object sender, EventArgs e)
        {
            try
            {
                if (check())
                {
                    DialogResult f = MessageBox.Show("Ban co chac muon them tai khoan nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                    if (f == DialogResult.Yes)
                    {
                        if (cbx_cv.Text == "Admin")
                        {
                            Account acc = new Account()
                            {
                                Name = tbx_ten.Text,
                                Account1 = tbx_tk.Text,
                                Password = tbx_mk.Text,
                                Position = "Admin",

                            };
                            db.Accounts.Add(acc);
                            db.SaveChanges();
                        }
                        else
                            MessageBox.Show("Vui long them thong tin cho nhan vien!!");
                    }
                    Reset_form();
                    Load_data();
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
                    if (dgv_account.SelectedRows.Count > 0)
                    {
                        DialogResult f = MessageBox.Show("Ban co chac muon xoa tai khoan nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                        if (f == DialogResult.Yes)
                        {
                            if (cbx_cv.Text == "Admin")
                            {
                                int i = dgv_account.CurrentCell.RowIndex;
                                string account = dgv_account.Rows[i].Cells[1].Value.ToString();
                                var acc = db.Accounts.Find(account);
                                db.Accounts.Remove(acc);
                                db.SaveChanges();
                            }
                            else
                                MessageBox.Show("Vui long xoa thong tin nhan vien");
                        }
                        Reset_form();
                        Load_data();
                    }
                    else
                        MessageBox.Show("Vui long chon hang muon xoa!!");
                }
                else
                    MessageBox.Show("Vui long nhap day du thong tin");
            }
            catch
            {
                MessageBox.Show("Thong tin khong hop le!!");
            }
        }

        private void update_employee(string name, string tmp)
        {
            var employee = from u in db.Employees where u.employee_name == name select u;
            employee.FirstOrDefault().employee_account = tmp;
            db.SaveChanges();

        }

        private void btn_sua_Click(object sender, EventArgs e)
        {
            try
            {
                if (check())
                {
                    if (dgv_account.SelectedRows.Count > 0)
                    {
                        DialogResult f = MessageBox.Show("Ban co chac muon sua tai khoan nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                        if (f == DialogResult.Yes)
                        {
                            int i = dgv_account.CurrentCell.RowIndex;
                            string acc = dgv_account.Rows[i].Cells[1].Value.ToString();
                            string name = dgv_account.Rows[i].Cells[0].Value.ToString();

                            if (cbx_cv.Text == "Employee")
                            {
                                var employee = from u in db.Employees where u.employee_name == name select u;
                                employee.FirstOrDefault().employee_account = null;

                                var acc1 = db.Accounts.Find(acc);
                                db.Accounts.Remove(acc1);
                                Account account = new Account()
                                {
                                    Name = tbx_ten.Text,
                                    Account1 = tbx_tk.Text.Trim(),
                                    Password = tbx_mk.Text,
                                    Position = "Employee",
                                };
                                db.Accounts.Add(account);
                                db.SaveChanges();
                                string tmp = tbx_tk.Text.Trim();
                                update_employee(name, tmp);
                            }
                            else if (cbx_cv.Text == "Admin")
                            {
                                var acc1 = db.Accounts.Find(acc);
                                db.Accounts.Remove(acc1);
                                Account account = new Account()
                                {
                                    Name = tbx_ten.Text,
                                    Account1 = tbx_tk.Text.Trim(),
                                    Password = tbx_mk.Text,
                                    Position = "Admin",
                                };
                                db.Accounts.Add(account);
                                db.SaveChanges();
                            }
                        }
                        Reset_form();
                        Load_data();
                    }
                    else
                        MessageBox.Show("Vui long chon hang muon chinh sua!!");
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
