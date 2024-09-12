using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        bool kiemtraMaSV(string ma) 
        { 
            for(int i=0; i<lvdanhsachsv.Items.Count;i++)
            {
                if(lvdanhsachsv.Items[i].SubItems[1].Text == ma)
                    return false;       
            }
            for(int i=0;i<lvdanhsachchon.Items.Count;i++)
            {
                if (lvdanhsachchon.Items[i].SubItems[1].Text == ma)
                    return false;
            }
            return true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btthem_Click(object sender, EventArgs e)
        {
            if (txtmasv.Text.Trim() == "" || txthoten.Text.Trim() == "" || txthometown.Text.Trim() == "" || txtbirth.Text.Trim() ==""||txtemail.Text.Trim()=="")
            {
                MessageBox.Show("Bạn chưa nhập đủ thông tin!!");
            }
            else if(kiemtraMaSV(txtmasv.Text.Trim())==false)
            {
                MessageBox.Show("Mã só đã tồn tại!! Vui lòng nhập lại!!");
                txtmasv.SelectAll();
                txtmasv.Focus();
            }
            else
            {
                ListViewItem li = new ListViewItem((lvdanhsachsv.Items.Count + 1).ToString());
                li.SubItems.Add(txtmasv.Text);
                li.SubItems.Add(txthoten.Text);
                li.SubItems.Add(txthometown.Text);
                li.SubItems.Add(txtbirth.Text);
                li.SubItems.Add(txtemail.Text);
                lvdanhsachsv.Items.Add(li);
                txtmasv.Text = txthoten.Text=txthometown.Text=txtemail.Text=txtbirth.Text="";
                txtmasv.Focus();
            }
        }
    }       
}
           