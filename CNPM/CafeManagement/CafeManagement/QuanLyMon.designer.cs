
namespace CafeManagement
{
    partial class QuanLyMon
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(QuanLyMon));
            this.lvMon = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnThem = new System.Windows.Forms.Button();
            this.txtTimKiem = new System.Windows.Forms.TextBox();
            this.cbDanhMuc = new System.Windows.Forms.ComboBox();
            this.txtDonGia = new System.Windows.Forms.TextBox();
            this.lbDonGia = new System.Windows.Forms.Label();
            this.txtTenMon = new System.Windows.Forms.TextBox();
            this.lbTenMon = new System.Windows.Forms.Label();
            this.lbDanhMuc = new System.Windows.Forms.Label();
            this.txtMaMon = new System.Windows.Forms.TextBox();
            this.lbMaMon = new System.Windows.Forms.Label();
            this.btnXoa = new System.Windows.Forms.Button();
            this.btnSua = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.txtSoLuong = new System.Windows.Forms.TextBox();
            this.lbSoLuong = new System.Windows.Forms.Label();
            this.rdoTrangThai = new System.Windows.Forms.RadioButton();
            this.pictureBox6 = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.ctMenuStripQLMon = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.btnHienThi = new System.Windows.Forms.Button();
            this.btnTimKiem = new System.Windows.Forms.Button();
            this.btnTimTheoMa = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lvMon
            // 
            this.lvMon.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            this.lvMon.Font = new System.Drawing.Font("Times New Roman", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lvMon.HideSelection = false;
            this.lvMon.Location = new System.Drawing.Point(0, 194);
            this.lvMon.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lvMon.Name = "lvMon";
            this.lvMon.Size = new System.Drawing.Size(712, 769);
            this.lvMon.TabIndex = 4;
            this.lvMon.UseCompatibleStateImageBehavior = false;
            this.lvMon.View = System.Windows.Forms.View.Details;
            this.lvMon.SelectedIndexChanged += new System.EventHandler(this.lvMon_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Mã thức uống";
            this.columnHeader1.Width = 150;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Tên thức uống";
            this.columnHeader2.Width = 200;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Danh mục";
            this.columnHeader3.Width = 150;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Đơn giá";
            this.columnHeader4.Width = 150;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Số lượng";
            this.columnHeader5.Width = 100;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Trạng thái";
            this.columnHeader6.Width = 100;
            // 
            // btnThem
            // 
            this.btnThem.BackColor = System.Drawing.Color.SandyBrown;
            this.btnThem.FlatAppearance.BorderSize = 0;
            this.btnThem.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnThem.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnThem.Location = new System.Drawing.Point(761, 824);
            this.btnThem.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnThem.Name = "btnThem";
            this.btnThem.Size = new System.Drawing.Size(125, 66);
            this.btnThem.TabIndex = 0;
            this.btnThem.Text = "Thêm";
            this.btnThem.UseVisualStyleBackColor = false;
            this.btnThem.Click += new System.EventHandler(this.btnThem_Click);
            // 
            // txtTimKiem
            // 
            this.txtTimKiem.Location = new System.Drawing.Point(720, 207);
            this.txtTimKiem.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtTimKiem.Name = "txtTimKiem";
            this.txtTimKiem.Size = new System.Drawing.Size(289, 31);
            this.txtTimKiem.TabIndex = 10;
            // 
            // cbDanhMuc
            // 
            this.cbDanhMuc.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbDanhMuc.FormattingEnabled = true;
            this.cbDanhMuc.Location = new System.Drawing.Point(892, 536);
            this.cbDanhMuc.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cbDanhMuc.Name = "cbDanhMuc";
            this.cbDanhMuc.Size = new System.Drawing.Size(316, 33);
            this.cbDanhMuc.TabIndex = 9;
            // 
            // txtDonGia
            // 
            this.txtDonGia.Location = new System.Drawing.Point(892, 621);
            this.txtDonGia.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtDonGia.Name = "txtDonGia";
            this.txtDonGia.Size = new System.Drawing.Size(316, 31);
            this.txtDonGia.TabIndex = 8;
            // 
            // lbDonGia
            // 
            this.lbDonGia.AutoSize = true;
            this.lbDonGia.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbDonGia.Location = new System.Drawing.Point(728, 624);
            this.lbDonGia.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbDonGia.Name = "lbDonGia";
            this.lbDonGia.Size = new System.Drawing.Size(107, 31);
            this.lbDonGia.TabIndex = 7;
            this.lbDonGia.Text = "Đơn Giá";
            // 
            // txtTenMon
            // 
            this.txtTenMon.Location = new System.Drawing.Point(892, 452);
            this.txtTenMon.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtTenMon.Name = "txtTenMon";
            this.txtTenMon.Size = new System.Drawing.Size(316, 31);
            this.txtTenMon.TabIndex = 8;
            // 
            // lbTenMon
            // 
            this.lbTenMon.AutoSize = true;
            this.lbTenMon.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbTenMon.Location = new System.Drawing.Point(728, 455);
            this.lbTenMon.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbTenMon.Name = "lbTenMon";
            this.lbTenMon.Size = new System.Drawing.Size(115, 31);
            this.lbTenMon.TabIndex = 7;
            this.lbTenMon.Text = "Tên Món";
            // 
            // lbDanhMuc
            // 
            this.lbDanhMuc.AutoSize = true;
            this.lbDanhMuc.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbDanhMuc.Location = new System.Drawing.Point(728, 539);
            this.lbDanhMuc.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbDanhMuc.Name = "lbDanhMuc";
            this.lbDanhMuc.Size = new System.Drawing.Size(130, 31);
            this.lbDanhMuc.TabIndex = 5;
            this.lbDanhMuc.Text = "Danh Mục";
            // 
            // txtMaMon
            // 
            this.txtMaMon.Location = new System.Drawing.Point(892, 368);
            this.txtMaMon.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMaMon.Name = "txtMaMon";
            this.txtMaMon.Size = new System.Drawing.Size(316, 31);
            this.txtMaMon.TabIndex = 6;
            // 
            // lbMaMon
            // 
            this.lbMaMon.AutoSize = true;
            this.lbMaMon.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbMaMon.Location = new System.Drawing.Point(728, 370);
            this.lbMaMon.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbMaMon.Name = "lbMaMon";
            this.lbMaMon.Size = new System.Drawing.Size(109, 31);
            this.lbMaMon.TabIndex = 5;
            this.lbMaMon.Text = "Mã Món";
            // 
            // btnXoa
            // 
            this.btnXoa.BackColor = System.Drawing.Color.SandyBrown;
            this.btnXoa.FlatAppearance.BorderSize = 0;
            this.btnXoa.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnXoa.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnXoa.Location = new System.Drawing.Point(925, 824);
            this.btnXoa.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnXoa.Name = "btnXoa";
            this.btnXoa.Size = new System.Drawing.Size(125, 66);
            this.btnXoa.TabIndex = 11;
            this.btnXoa.Text = "Xóa ";
            this.btnXoa.UseVisualStyleBackColor = false;
            this.btnXoa.Click += new System.EventHandler(this.btnXoa_Click);
            // 
            // btnSua
            // 
            this.btnSua.BackColor = System.Drawing.Color.SandyBrown;
            this.btnSua.FlatAppearance.BorderSize = 0;
            this.btnSua.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSua.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSua.Location = new System.Drawing.Point(1083, 824);
            this.btnSua.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnSua.Name = "btnSua";
            this.btnSua.Size = new System.Drawing.Size(125, 66);
            this.btnSua.TabIndex = 12;
            this.btnSua.Text = "Sửa";
            this.btnSua.UseVisualStyleBackColor = false;
            this.btnSua.Click += new System.EventHandler(this.btnSua_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(728, 772);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(124, 31);
            this.label2.TabIndex = 21;
            this.label2.Text = "Trạng thái";
            // 
            // txtSoLuong
            // 
            this.txtSoLuong.Location = new System.Drawing.Point(892, 695);
            this.txtSoLuong.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtSoLuong.Name = "txtSoLuong";
            this.txtSoLuong.Size = new System.Drawing.Size(316, 31);
            this.txtSoLuong.TabIndex = 20;
            // 
            // lbSoLuong
            // 
            this.lbSoLuong.AutoSize = true;
            this.lbSoLuong.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbSoLuong.Location = new System.Drawing.Point(728, 698);
            this.lbSoLuong.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbSoLuong.Name = "lbSoLuong";
            this.lbSoLuong.Size = new System.Drawing.Size(113, 31);
            this.lbSoLuong.TabIndex = 19;
            this.lbSoLuong.Text = "Số lượng";
            // 
            // rdoTrangThai
            // 
            this.rdoTrangThai.AutoSize = true;
            this.rdoTrangThai.Font = new System.Drawing.Font("Times New Roman", 10.125F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdoTrangThai.Location = new System.Drawing.Point(892, 770);
            this.rdoTrangThai.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.rdoTrangThai.Name = "rdoTrangThai";
            this.rdoTrangThai.Size = new System.Drawing.Size(185, 35);
            this.rdoTrangThai.TabIndex = 22;
            this.rdoTrangThai.TabStop = true;
            this.rdoTrangThai.Text = "Còn phục vụ";
            this.rdoTrangThai.UseVisualStyleBackColor = true;
            // 
            // pictureBox6
            // 
            this.pictureBox6.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox6.Image")));
            this.pictureBox6.Location = new System.Drawing.Point(715, 2);
            this.pictureBox6.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox6.Name = "pictureBox6";
            this.pictureBox6.Size = new System.Drawing.Size(533, 181);
            this.pictureBox6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox6.TabIndex = 23;
            this.pictureBox6.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.PeachPuff;
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.pictureBox6);
            this.panel1.Location = new System.Drawing.Point(0, 2);
            this.panel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1252, 184);
            this.panel1.TabIndex = 24;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 19.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Chocolate;
            this.label1.Location = new System.Drawing.Point(28, 80);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(680, 61);
            this.label1.TabIndex = 24;
            this.label1.Text = "DANH SÁCH THỨC UỐNG";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // ctMenuStripQLMon
            // 
            this.ctMenuStripQLMon.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.ctMenuStripQLMon.Name = "ctMenuStripQLMon";
            this.ctMenuStripQLMon.Size = new System.Drawing.Size(61, 4);
            // 
            // btnHienThi
            // 
            this.btnHienThi.Location = new System.Drawing.Point(788, 277);
            this.btnHienThi.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnHienThi.Name = "btnHienThi";
            this.btnHienThi.Size = new System.Drawing.Size(176, 40);
            this.btnHienThi.TabIndex = 26;
            this.btnHienThi.Text = "Hiển thị Menu";
            this.btnHienThi.UseVisualStyleBackColor = true;
            this.btnHienThi.Click += new System.EventHandler(this.btnHienThi_Click);
            // 
            // btnTimKiem
            // 
            this.btnTimKiem.BackColor = System.Drawing.Color.SandyBrown;
            this.btnTimKiem.FlatAppearance.BorderSize = 0;
            this.btnTimKiem.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnTimKiem.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnTimKiem.Location = new System.Drawing.Point(1034, 194);
            this.btnTimKiem.Margin = new System.Windows.Forms.Padding(4);
            this.btnTimKiem.Name = "btnTimKiem";
            this.btnTimKiem.Size = new System.Drawing.Size(214, 44);
            this.btnTimKiem.TabIndex = 27;
            this.btnTimKiem.Text = "Tìm theo tên món";
            this.btnTimKiem.UseVisualStyleBackColor = false;
            this.btnTimKiem.Click += new System.EventHandler(this.btnTimKiem_Click_1);
            // 
            // btnTimTheoMa
            // 
            this.btnTimTheoMa.BackColor = System.Drawing.Color.SandyBrown;
            this.btnTimTheoMa.FlatAppearance.BorderSize = 0;
            this.btnTimTheoMa.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnTimTheoMa.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnTimTheoMa.Location = new System.Drawing.Point(1034, 273);
            this.btnTimTheoMa.Margin = new System.Windows.Forms.Padding(4);
            this.btnTimTheoMa.Name = "btnTimTheoMa";
            this.btnTimTheoMa.Size = new System.Drawing.Size(214, 44);
            this.btnTimTheoMa.TabIndex = 28;
            this.btnTimTheoMa.Text = "Tìm theo mã";
            this.btnTimTheoMa.UseVisualStyleBackColor = false;
            this.btnTimTheoMa.Click += new System.EventHandler(this.btnTimTheoMa_Click);
            // 
            // QuanLyMon
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Linen;
            this.ClientSize = new System.Drawing.Size(1264, 969);
            this.Controls.Add(this.btnTimTheoMa);
            this.Controls.Add(this.btnTimKiem);
            this.Controls.Add(this.btnHienThi);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.rdoTrangThai);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtSoLuong);
            this.Controls.Add(this.lbSoLuong);
            this.Controls.Add(this.btnSua);
            this.Controls.Add(this.btnXoa);
            this.Controls.Add(this.lvMon);
            this.Controls.Add(this.txtTimKiem);
            this.Controls.Add(this.cbDanhMuc);
            this.Controls.Add(this.txtDonGia);
            this.Controls.Add(this.lbDonGia);
            this.Controls.Add(this.txtTenMon);
            this.Controls.Add(this.btnThem);
            this.Controls.Add(this.lbTenMon);
            this.Controls.Add(this.lbDanhMuc);
            this.Controls.Add(this.txtMaMon);
            this.Controls.Add(this.lbMaMon);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "QuanLyMon";
            this.Text = "QUAN LY MON";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.QuanLyMon_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnThem;
        private System.Windows.Forms.TextBox txtDonGia;
        private System.Windows.Forms.Label lbDonGia;
        private System.Windows.Forms.TextBox txtTenMon;
        private System.Windows.Forms.Label lbTenMon;
        private System.Windows.Forms.Label lbDanhMuc;
        private System.Windows.Forms.TextBox txtMaMon;
        private System.Windows.Forms.Label lbMaMon;
        private System.Windows.Forms.ListView lvMon;
        private System.Windows.Forms.TextBox txtTimKiem;
        private System.Windows.Forms.ComboBox cbDanhMuc;
        private System.Windows.Forms.Button btnXoa;
        private System.Windows.Forms.Button btnSua;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtSoLuong;
        private System.Windows.Forms.Label lbSoLuong;
        private System.Windows.Forms.RadioButton rdoTrangThai;
        private System.Windows.Forms.PictureBox pictureBox6;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ContextMenuStrip ctMenuStripQLMon;
        private System.Windows.Forms.Button btnHienThi;
        private System.Windows.Forms.Button btnTimKiem;
        private System.Windows.Forms.Button btnTimTheoMa;
    }
}

