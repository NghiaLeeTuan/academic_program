namespace CuoiKi
{
    partial class HoaDon
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
            this.panel2 = new System.Windows.Forms.Panel();
            this.btn_xoa = new System.Windows.Forms.Button();
            this.cbx_id = new System.Windows.Forms.ComboBox();
            this.lbl_id = new System.Windows.Forms.Label();
            this.tb_dongia = new System.Windows.Forms.TextBox();
            this.tb_sl = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.lbl_ten_item = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.btn_them = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.label7 = new System.Windows.Forms.Label();
            this.cbx_chon_item = new System.Windows.Forms.ComboBox();
            this.lv_item = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btn_new_hoadon = new System.Windows.Forms.Button();
            this.btn_back = new System.Windows.Forms.Button();
            this.btn_luu = new System.Windows.Forms.Button();
            this.panel2.SuspendLayout();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.btn_back);
            this.panel2.Controls.Add(this.btn_new_hoadon);
            this.panel2.Controls.Add(this.btn_luu);
            this.panel2.Controls.Add(this.btn_xoa);
            this.panel2.Controls.Add(this.cbx_id);
            this.panel2.Controls.Add(this.lbl_id);
            this.panel2.Controls.Add(this.tb_dongia);
            this.panel2.Controls.Add(this.tb_sl);
            this.panel2.Controls.Add(this.label9);
            this.panel2.Controls.Add(this.label8);
            this.panel2.Controls.Add(this.lbl_ten_item);
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.btn_them);
            this.panel2.Controls.Add(this.label5);
            this.panel2.Location = new System.Drawing.Point(530, 286);
            this.panel2.Margin = new System.Windows.Forms.Padding(2);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(247, 308);
            this.panel2.TabIndex = 7;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // btn_xoa
            // 
            this.btn_xoa.Location = new System.Drawing.Point(129, 191);
            this.btn_xoa.Margin = new System.Windows.Forms.Padding(2);
            this.btn_xoa.Name = "btn_xoa";
            this.btn_xoa.Size = new System.Drawing.Size(104, 20);
            this.btn_xoa.TabIndex = 14;
            this.btn_xoa.Text = "Xóa khỏi hóa đơn";
            this.btn_xoa.UseVisualStyleBackColor = true;
            this.btn_xoa.Click += new System.EventHandler(this.btn_xoa_Click);
            // 
            // cbx_id
            // 
            this.cbx_id.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.cbx_id.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.cbx_id.FormattingEnabled = true;
            this.cbx_id.Location = new System.Drawing.Point(160, 11);
            this.cbx_id.Margin = new System.Windows.Forms.Padding(2);
            this.cbx_id.Name = "cbx_id";
            this.cbx_id.Size = new System.Drawing.Size(60, 21);
            this.cbx_id.TabIndex = 13;
            this.cbx_id.SelectedIndexChanged += new System.EventHandler(this.cbx_id_SelectedIndexChanged);
            // 
            // lbl_id
            // 
            this.lbl_id.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_id.Location = new System.Drawing.Point(86, 11);
            this.lbl_id.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbl_id.Name = "lbl_id";
            this.lbl_id.Size = new System.Drawing.Size(62, 21);
            this.lbl_id.TabIndex = 10;
            // 
            // tb_dongia
            // 
            this.tb_dongia.Location = new System.Drawing.Point(86, 142);
            this.tb_dongia.Margin = new System.Windows.Forms.Padding(2);
            this.tb_dongia.Multiline = true;
            this.tb_dongia.Name = "tb_dongia";
            this.tb_dongia.Size = new System.Drawing.Size(135, 21);
            this.tb_dongia.TabIndex = 9;
            // 
            // tb_sl
            // 
            this.tb_sl.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tb_sl.Location = new System.Drawing.Point(86, 103);
            this.tb_sl.Margin = new System.Windows.Forms.Padding(2);
            this.tb_sl.Multiline = true;
            this.tb_sl.Name = "tb_sl";
            this.tb_sl.Size = new System.Drawing.Size(135, 21);
            this.tb_sl.TabIndex = 8;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(7, 145);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(44, 13);
            this.label9.TabIndex = 7;
            this.label9.Text = "Đơn giá";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(7, 103);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(56, 13);
            this.label8.TabIndex = 6;
            this.label8.Text = "Số Lượng ";
            // 
            // lbl_ten_item
            // 
            this.lbl_ten_item.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_ten_item.Location = new System.Drawing.Point(86, 57);
            this.lbl_ten_item.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbl_ten_item.Name = "lbl_ten_item";
            this.lbl_ten_item.Size = new System.Drawing.Size(135, 21);
            this.lbl_ten_item.TabIndex = 5;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 57);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(76, 13);
            this.label6.TabIndex = 4;
            this.label6.Text = "Tên món hàng";
            // 
            // btn_them
            // 
            this.btn_them.Location = new System.Drawing.Point(4, 191);
            this.btn_them.Margin = new System.Windows.Forms.Padding(2);
            this.btn_them.Name = "btn_them";
            this.btn_them.Size = new System.Drawing.Size(118, 20);
            this.btn_them.TabIndex = 2;
            this.btn_them.Text = "Thêm vào hóa đơn";
            this.btn_them.UseVisualStyleBackColor = true;
            this.btn_them.Click += new System.EventHandler(this.btn_them_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(7, 17);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(15, 13);
            this.label5.TabIndex = 0;
            this.label5.Text = "id";
            // 
            // panel4
            // 
            this.panel4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel4.Controls.Add(this.label7);
            this.panel4.Controls.Add(this.panel2);
            this.panel4.Controls.Add(this.cbx_chon_item);
            this.panel4.Controls.Add(this.lv_item);
            this.panel4.Location = new System.Drawing.Point(8, 10);
            this.panel4.Margin = new System.Windows.Forms.Padding(2);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(784, 603);
            this.panel4.TabIndex = 9;
            this.panel4.Paint += new System.Windows.Forms.PaintEventHandler(this.panel4_Paint);
            // 
            // label7
            // 
            this.label7.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label7.Location = new System.Drawing.Point(530, 2);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(247, 18);
            this.label7.TabIndex = 9;
            this.label7.Text = "Tìm sản phẩm";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // cbx_chon_item
            // 
            this.cbx_chon_item.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.cbx_chon_item.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.cbx_chon_item.DropDownStyle = System.Windows.Forms.ComboBoxStyle.Simple;
            this.cbx_chon_item.FormattingEnabled = true;
            this.cbx_chon_item.Location = new System.Drawing.Point(530, 23);
            this.cbx_chon_item.Margin = new System.Windows.Forms.Padding(2);
            this.cbx_chon_item.Name = "cbx_chon_item";
            this.cbx_chon_item.Size = new System.Drawing.Size(247, 268);
            this.cbx_chon_item.TabIndex = 8;
            this.cbx_chon_item.SelectedIndexChanged += new System.EventHandler(this.cbx_chon_item_SelectedIndexChanged);
            // 
            // lv_item
            // 
            this.lv_item.BackColor = System.Drawing.SystemColors.HighlightText;
            this.lv_item.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5});
            this.lv_item.FullRowSelect = true;
            this.lv_item.GridLines = true;
            this.lv_item.HideSelection = false;
            this.lv_item.Location = new System.Drawing.Point(2, 2);
            this.lv_item.Margin = new System.Windows.Forms.Padding(2);
            this.lv_item.Name = "lv_item";
            this.lv_item.Size = new System.Drawing.Size(524, 600);
            this.lv_item.TabIndex = 2;
            this.lv_item.UseCompatibleStateImageBehavior = false;
            this.lv_item.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Mã Hàng";
            this.columnHeader1.Width = 84;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Tên Hàng";
            this.columnHeader2.Width = 194;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Số Lượng";
            this.columnHeader3.Width = 74;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Đơn Giá";
            this.columnHeader4.Width = 85;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Thành Tiền";
            this.columnHeader5.Width = 146;
            // 
            // btn_new_hoadon
            // 
            this.btn_new_hoadon.Location = new System.Drawing.Point(129, 228);
            this.btn_new_hoadon.Margin = new System.Windows.Forms.Padding(2);
            this.btn_new_hoadon.Name = "btn_new_hoadon";
            this.btn_new_hoadon.Size = new System.Drawing.Size(104, 25);
            this.btn_new_hoadon.TabIndex = 18;
            this.btn_new_hoadon.Text = "Hóa đơn mới";
            this.btn_new_hoadon.UseVisualStyleBackColor = true;
            // 
            // btn_back
            // 
            this.btn_back.Location = new System.Drawing.Point(75, 258);
            this.btn_back.Margin = new System.Windows.Forms.Padding(2);
            this.btn_back.Name = "btn_back";
            this.btn_back.Size = new System.Drawing.Size(104, 26);
            this.btn_back.TabIndex = 17;
            this.btn_back.Text = "Trở về";
            this.btn_back.UseVisualStyleBackColor = true;
            // 
            // btn_luu
            // 
            this.btn_luu.Location = new System.Drawing.Point(4, 228);
            this.btn_luu.Margin = new System.Windows.Forms.Padding(2);
            this.btn_luu.Name = "btn_luu";
            this.btn_luu.Size = new System.Drawing.Size(118, 26);
            this.btn_luu.TabIndex = 16;
            this.btn_luu.Text = "Lưu Hóa Đơn";
            this.btn_luu.UseVisualStyleBackColor = true;
            // 
            // HoaDon
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(797, 616);
            this.Controls.Add(this.panel4);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "HoaDon";
            this.Text = "Hóa đơn mới";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.HoaDon_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.HoaDon_FormClosed);
            this.Load += new System.EventHandler(this.HoaDon_Load);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btn_them;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lbl_ten_item;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox tb_dongia;
        private System.Windows.Forms.TextBox tb_sl;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.ListView lv_item;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.Label lbl_id;
        private System.Windows.Forms.ComboBox cbx_chon_item;
        private System.Windows.Forms.ComboBox cbx_id;
        private System.Windows.Forms.Button btn_xoa;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button btn_back;
        private System.Windows.Forms.Button btn_new_hoadon;
        private System.Windows.Forms.Button btn_luu;
    }
}

