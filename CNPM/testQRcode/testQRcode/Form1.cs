using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace testQRcode
{
    public partial class Form1 : Form
    {
        public Form1() 
        {
            InitializeComponent();
        }

        private void btn_test_Click(object sender, EventArgs e)
        {
            QRCoder.QRCodeGenerator test = new QRCoder.QRCodeGenerator();
            var check = test.CreateQrCode(txb_test.Text, QRCoder.QRCodeGenerator.ECCLevel.H);
            var code = new QRCoder.QRCode(check);
            pictureBox1.Image = code.GetGraphic(50);  
        }
    }
}
