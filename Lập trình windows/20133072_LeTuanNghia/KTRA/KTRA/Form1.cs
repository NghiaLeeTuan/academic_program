using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Data.Entity;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KTRA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        KtraContext ab = new KtraContext();

        private void Form1_Load(object sender, EventArgs e)
        {
            /*using (var db = new KtraContext())
            {
                db.NhanViens.Add(new NhanVien() { Id = 1, ten = "Tran Minh Duc", SDT = "097123127", capbac = "truong phong" ,phong = 1});
                db.SaveChanges();
                db.NhanViens.Add(new NhanVien() { Id = 2, ten = "Le Tuan Nghia", SDT = "0121232", capbac = "pho phong" ,phong = 2});
                db.SaveChanges();
                db.NhanViens.Add(new NhanVien() { Id = 4, ten = "Tran Trung", SDT = "08123382", capbac = "nhan vien", phong = 4 });
                db.SaveChanges();
            }*/
                
                
            dtv1.DataSource = ab.NhanViens.Select(a => a).ToList();



        }

        private void CB_cap_SelectedIndexChanged(object sender, EventArgs e)
        {

            string capbac = CB_cap.Text;
            var r = ab.NhanViens.Where(a => a.capbac == capbac).ToList();
            dtv1.DataSource = r.ToList();
        }
    }
}
