namespace Student_GirdView
{
    partial class Form1
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
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.dgv = new System.Windows.Forms.DataGridView();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btn_Sua = new System.Windows.Forms.Button();
            this.btn_Xoa = new System.Windows.Forms.Button();
            this.btn_Them = new System.Windows.Forms.Button();
            this.text_email = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.date_Birthday = new System.Windows.Forms.DateTimePicker();
            this.text_hometown = new System.Windows.Forms.TextBox();
            this.text_name = new System.Windows.Forms.TextBox();
            this.label_hometown = new System.Windows.Forms.Label();
            this.label_name = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.dgv);
            this.groupBox1.Location = new System.Drawing.Point(9, 241);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox1.Size = new System.Drawing.Size(580, 243);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Thông tin";
            // 
            // dgv
            // 
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.Location = new System.Drawing.Point(17, 17);
            this.dgv.Margin = new System.Windows.Forms.Padding(2);
            this.dgv.Name = "dgv";
            this.dgv.RowHeadersWidth = 51;
            this.dgv.RowTemplate.Height = 24;
            this.dgv.Size = new System.Drawing.Size(544, 218);
            this.dgv.TabIndex = 0;
            this.dgv.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgv_CellContentClick);
            // 
            // groupBox2
            // 
            this.groupBox2.BackgroundImage = global::Student_GirdView.Properties.Resources.download__4_;
            this.groupBox2.Controls.Add(this.btn_Sua);
            this.groupBox2.Controls.Add(this.btn_Xoa);
            this.groupBox2.Controls.Add(this.btn_Them);
            this.groupBox2.Controls.Add(this.text_email);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.date_Birthday);
            this.groupBox2.Controls.Add(this.text_hometown);
            this.groupBox2.Controls.Add(this.text_name);
            this.groupBox2.Controls.Add(this.label_hometown);
            this.groupBox2.Controls.Add(this.label_name);
            this.groupBox2.Location = new System.Drawing.Point(9, 10);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox2.Size = new System.Drawing.Size(580, 231);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Điền thông tin";
            // 
            // btn_Sua
            // 
            this.btn_Sua.Location = new System.Drawing.Point(416, 156);
            this.btn_Sua.Margin = new System.Windows.Forms.Padding(2);
            this.btn_Sua.Name = "btn_Sua";
            this.btn_Sua.Size = new System.Drawing.Size(88, 46);
            this.btn_Sua.TabIndex = 18;
            this.btn_Sua.Text = "Sửa";
            this.btn_Sua.UseVisualStyleBackColor = true;
            this.btn_Sua.Click += new System.EventHandler(this.btn_Sua_Click);
            // 
            // btn_Xoa
            // 
            this.btn_Xoa.Location = new System.Drawing.Point(416, 88);
            this.btn_Xoa.Margin = new System.Windows.Forms.Padding(2);
            this.btn_Xoa.Name = "btn_Xoa";
            this.btn_Xoa.Size = new System.Drawing.Size(88, 46);
            this.btn_Xoa.TabIndex = 17;
            this.btn_Xoa.Text = "Xóa";
            this.btn_Xoa.UseVisualStyleBackColor = true;
            this.btn_Xoa.Click += new System.EventHandler(this.btn_Xoa_Click);
            // 
            // btn_Them
            // 
            this.btn_Them.Location = new System.Drawing.Point(416, 21);
            this.btn_Them.Margin = new System.Windows.Forms.Padding(2);
            this.btn_Them.Name = "btn_Them";
            this.btn_Them.Size = new System.Drawing.Size(88, 46);
            this.btn_Them.TabIndex = 16;
            this.btn_Them.Text = "Thêm";
            this.btn_Them.UseVisualStyleBackColor = true;
            this.btn_Them.Click += new System.EventHandler(this.btn_Them_Click);
            // 
            // text_email
            // 
            this.text_email.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.text_email.Location = new System.Drawing.Point(106, 155);
            this.text_email.Margin = new System.Windows.Forms.Padding(2);
            this.text_email.Multiline = true;
            this.text_email.Name = "text_email";
            this.text_email.Size = new System.Drawing.Size(220, 31);
            this.text_email.TabIndex = 15;
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label2.Location = new System.Drawing.Point(14, 167);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 19);
            this.label2.TabIndex = 14;
            this.label2.Text = "Email";
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(14, 120);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 19);
            this.label1.TabIndex = 13;
            this.label1.Text = "Birthday";
            // 
            // date_Birthday
            // 
            this.date_Birthday.CalendarMonthBackground = System.Drawing.SystemColors.ScrollBar;
            this.date_Birthday.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.date_Birthday.Location = new System.Drawing.Point(106, 114);
            this.date_Birthday.Margin = new System.Windows.Forms.Padding(2);
            this.date_Birthday.Name = "date_Birthday";
            this.date_Birthday.Size = new System.Drawing.Size(220, 20);
            this.date_Birthday.TabIndex = 12;
            // 
            // text_hometown
            // 
            this.text_hometown.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.text_hometown.Location = new System.Drawing.Point(106, 70);
            this.text_hometown.Margin = new System.Windows.Forms.Padding(2);
            this.text_hometown.Multiline = true;
            this.text_hometown.Name = "text_hometown";
            this.text_hometown.Size = new System.Drawing.Size(220, 29);
            this.text_hometown.TabIndex = 11;
            // 
            // text_name
            // 
            this.text_name.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.text_name.Location = new System.Drawing.Point(106, 21);
            this.text_name.Margin = new System.Windows.Forms.Padding(2);
            this.text_name.Multiline = true;
            this.text_name.Name = "text_name";
            this.text_name.Size = new System.Drawing.Size(220, 31);
            this.text_name.TabIndex = 10;
            // 
            // label_hometown
            // 
            this.label_hometown.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label_hometown.Location = new System.Drawing.Point(14, 73);
            this.label_hometown.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label_hometown.Name = "label_hometown";
            this.label_hometown.Size = new System.Drawing.Size(75, 19);
            this.label_hometown.TabIndex = 9;
            this.label_hometown.Text = "Hometown";
            // 
            // label_name
            // 
            this.label_name.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label_name.Location = new System.Drawing.Point(14, 33);
            this.label_name.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label_name.Name = "label_name";
            this.label_name.Size = new System.Drawing.Size(75, 19);
            this.label_name.TabIndex = 8;
            this.label_name.Text = "Name";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(600, 484);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridView dgv;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btn_Sua;
        private System.Windows.Forms.Button btn_Xoa;
        private System.Windows.Forms.Button btn_Them;
        private System.Windows.Forms.TextBox text_email;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker date_Birthday;
        private System.Windows.Forms.TextBox text_hometown;
        private System.Windows.Forms.TextBox text_name;
        private System.Windows.Forms.Label label_hometown;
        private System.Windows.Forms.Label label_name;
    }
}

