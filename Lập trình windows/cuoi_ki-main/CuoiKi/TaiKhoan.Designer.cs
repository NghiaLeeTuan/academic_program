namespace CuoiKi
{
    partial class TaiKhoan
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
            this.cbx_cv = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.btn_back = new System.Windows.Forms.Button();
            this.btn_sua = new System.Windows.Forms.Button();
            this.btn_xoa = new System.Windows.Forms.Button();
            this.btn_thm = new System.Windows.Forms.Button();
            this.tbx_mk = new System.Windows.Forms.TextBox();
            this.tbx_tk = new System.Windows.Forms.TextBox();
            this.tbx_ten = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.dgv_account = new System.Windows.Forms.DataGridView();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv_account)).BeginInit();
            this.SuspendLayout();
            // 
            // cbx_cv
            // 
            this.cbx_cv.FormattingEnabled = true;
            this.cbx_cv.Items.AddRange(new object[] {
            "Admin",
            "Employee"});
            this.cbx_cv.Location = new System.Drawing.Point(130, 117);
            this.cbx_cv.Name = "cbx_cv";
            this.cbx_cv.Size = new System.Drawing.Size(210, 21);
            this.cbx_cv.TabIndex = 62;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(20, 109);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 13);
            this.label5.TabIndex = 61;
            this.label5.Text = "Chức vụ";
            // 
            // btn_back
            // 
            this.btn_back.Location = new System.Drawing.Point(346, 149);
            this.btn_back.Name = "btn_back";
            this.btn_back.Size = new System.Drawing.Size(89, 37);
            this.btn_back.TabIndex = 60;
            this.btn_back.Text = "Trở về";
            this.btn_back.UseVisualStyleBackColor = true;
            this.btn_back.Click += new System.EventHandler(this.btn_back_Click);
            // 
            // btn_sua
            // 
            this.btn_sua.Location = new System.Drawing.Point(346, 103);
            this.btn_sua.Name = "btn_sua";
            this.btn_sua.Size = new System.Drawing.Size(89, 46);
            this.btn_sua.TabIndex = 59;
            this.btn_sua.Text = "Sửa Tài Khoản";
            this.btn_sua.UseVisualStyleBackColor = true;
            this.btn_sua.Click += new System.EventHandler(this.btn_sua_Click);
            // 
            // btn_xoa
            // 
            this.btn_xoa.Location = new System.Drawing.Point(346, 56);
            this.btn_xoa.Name = "btn_xoa";
            this.btn_xoa.Size = new System.Drawing.Size(89, 43);
            this.btn_xoa.TabIndex = 58;
            this.btn_xoa.Text = "Xóa Tài Khoản";
            this.btn_xoa.UseVisualStyleBackColor = true;
            this.btn_xoa.Click += new System.EventHandler(this.btn_xoa_Click);
            // 
            // btn_thm
            // 
            this.btn_thm.Location = new System.Drawing.Point(346, 11);
            this.btn_thm.Name = "btn_thm";
            this.btn_thm.Size = new System.Drawing.Size(89, 46);
            this.btn_thm.TabIndex = 57;
            this.btn_thm.Text = "Thêm Tài Khoản";
            this.btn_thm.UseVisualStyleBackColor = true;
            this.btn_thm.Click += new System.EventHandler(this.btn_thm_Click);
            // 
            // tbx_mk
            // 
            this.tbx_mk.Location = new System.Drawing.Point(130, 76);
            this.tbx_mk.Multiline = true;
            this.tbx_mk.Name = "tbx_mk";
            this.tbx_mk.Size = new System.Drawing.Size(210, 24);
            this.tbx_mk.TabIndex = 56;
            // 
            // tbx_tk
            // 
            this.tbx_tk.Location = new System.Drawing.Point(130, 45);
            this.tbx_tk.Multiline = true;
            this.tbx_tk.Name = "tbx_tk";
            this.tbx_tk.Size = new System.Drawing.Size(210, 24);
            this.tbx_tk.TabIndex = 55;
            // 
            // tbx_ten
            // 
            this.tbx_ten.Location = new System.Drawing.Point(130, 15);
            this.tbx_ten.Multiline = true;
            this.tbx_ten.Name = "tbx_ten";
            this.tbx_ten.Size = new System.Drawing.Size(210, 24);
            this.tbx_ten.TabIndex = 54;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(20, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 53;
            this.label2.Text = "Tài khoản";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(20, 77);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 52;
            this.label4.Text = "Mật khẩu";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 18);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 51;
            this.label3.Text = "Tên ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label1.Location = new System.Drawing.Point(20, 149);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(138, 17);
            this.label1.TabIndex = 50;
            this.label1.Text = "Danh sách tài khoản";
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.dgv_account);
            this.panel1.Location = new System.Drawing.Point(22, 186);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(451, 251);
            this.panel1.TabIndex = 49;
            // 
            // dgv_account
            // 
            this.dgv_account.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv_account.Location = new System.Drawing.Point(2, 3);
            this.dgv_account.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.dgv_account.Name = "dgv_account";
            this.dgv_account.RowHeadersWidth = 51;
            this.dgv_account.RowTemplate.Height = 24;
            this.dgv_account.Size = new System.Drawing.Size(445, 250);
            this.dgv_account.TabIndex = 0;
            this.dgv_account.SelectionChanged += new System.EventHandler(this.dgv_account_SelectionChanged);
            // 
            // TaiKhoan
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(507, 448);
            this.Controls.Add(this.cbx_cv);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.btn_back);
            this.Controls.Add(this.btn_sua);
            this.Controls.Add(this.btn_xoa);
            this.Controls.Add(this.btn_thm);
            this.Controls.Add(this.tbx_mk);
            this.Controls.Add(this.tbx_tk);
            this.Controls.Add(this.tbx_ten);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "TaiKhoan";
            this.Text = "TaiKhoan";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.TaiKhoan_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Account_FormClosed);
            this.Load += new System.EventHandler(this.TaiKhoan_Load);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgv_account)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cbx_cv;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btn_back;
        private System.Windows.Forms.Button btn_sua;
        private System.Windows.Forms.Button btn_xoa;
        private System.Windows.Forms.Button btn_thm;
        private System.Windows.Forms.TextBox tbx_mk;
        private System.Windows.Forms.TextBox tbx_tk;
        private System.Windows.Forms.TextBox tbx_ten;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.DataGridView dgv_account;
    }
}