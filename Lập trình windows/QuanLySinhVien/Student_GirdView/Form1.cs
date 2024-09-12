using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Student_GirdView
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            LoadData();
            btn_Them.BackColor = btn_Sua.BackColor = btn_Xoa.BackColor = Color.LightBlue;
        }
        void LoadData()
        {
            DBConnection Connection = new DBConnection();
            const string query = @"Select * from Student";
            DataTable dt = Connection.ExecuteQuery(query);
            dgv.DataSource = dt;
        }

        private void dgv_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            int i;
            i = dgv.CurrentRow.Index;
            text_name.Text = dgv.Rows[i].Cells[1].Value.ToString();
            text_hometown.Text = dgv.Rows[i].Cells[2].Value.ToString();
            date_Birthday.Text= dgv.Rows[i].Cells[3].Value.ToString();
            text_email.Text= dgv.Rows[i].Cells[4].Value.ToString();

        }

        private void btn_Them_Click(object sender, EventArgs e)
        {
            StudentBUS stBus = new StudentBUS();
            stBus.ThemSinhVien(text_name.Text, text_hometown.Text, date_Birthday.Text, text_email.Text);
            LoadData();
            text_name.Text = text_hometown.Text= text_email.Text = "";
        }

        private void btn_Xoa_Click(object sender, EventArgs e)
        {
            StudentBUS stBus = new StudentBUS();
            int i;
            i = dgv.CurrentRow.Index;
            string id = dgv.Rows[i].Cells[0].Value.ToString();
            DialogResult f = MessageBox.Show("Ban co chac muon xoa sinh vien nay khong", "Thong bao",MessageBoxButtons.YesNo,MessageBoxIcon.Warning);
            if (f == DialogResult.Yes)
            {
                stBus.XoaSinhVien(id);
                LoadData();
            }
        }

        private void btn_Sua_Click(object sender, EventArgs e)
        {
            StudentBUS stBus = new StudentBUS();
            int i;
            i = dgv.CurrentRow.Index;
            string id = dgv.Rows[i].Cells[0].Value.ToString();
            DialogResult f = MessageBox.Show("Ban co chac muon sua sinh vien nay khong", "Thong bao", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (f == DialogResult.Yes)
            {
                stBus.SuaSinhVien(id, text_name.Text, text_hometown.Text, date_Birthday.Text, text_email.Text) ;
                LoadData();
            }
        }
    }
}
