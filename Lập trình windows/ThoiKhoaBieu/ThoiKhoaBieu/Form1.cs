using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThoiKhoaBieu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Loaddata();
        }

        private void Loaddata()
        {
            DBConnections Connection = new DBConnections();
            const string query = @"Select Id,TenMH,GV,TGhoc,TGnghi,Phong from TKB where Date = 'Thu 7' and HK='HK1' and Year = '2020-2021'";
            DataTable dt = Connection.ExecuteQuery(query);
            dgv.DataSource = dt;
        }
    }
}
