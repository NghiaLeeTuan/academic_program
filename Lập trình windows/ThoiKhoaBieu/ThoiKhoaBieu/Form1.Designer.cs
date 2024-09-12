
namespace ThoiKhoaBieu
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
            this.CB_Hocki = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.CB_Namhoc = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.CB_Thu = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.dgv = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            this.SuspendLayout();
            // 
            // CB_Hocki
            // 
            this.CB_Hocki.FormattingEnabled = true;
            this.CB_Hocki.Items.AddRange(new object[] {
            "HK1",
            "HK2"});
            this.CB_Hocki.Location = new System.Drawing.Point(192, 42);
            this.CB_Hocki.Name = "CB_Hocki";
            this.CB_Hocki.Size = new System.Drawing.Size(81, 21);
            this.CB_Hocki.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(188, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Học kì:";
            // 
            // CB_Namhoc
            // 
            this.CB_Namhoc.FormattingEnabled = true;
            this.CB_Namhoc.Items.AddRange(new object[] {
            "2020-2021",
            "2021-2022",
            "2022-2023",
            "2023-2024"});
            this.CB_Namhoc.Location = new System.Drawing.Point(25, 42);
            this.CB_Namhoc.Name = "CB_Namhoc";
            this.CB_Namhoc.Size = new System.Drawing.Size(121, 21);
            this.CB_Namhoc.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(21, 19);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Năm học:";
            // 
            // CB_Thu
            // 
            this.CB_Thu.FormattingEnabled = true;
            this.CB_Thu.Items.AddRange(new object[] {
            "Thu 2",
            "Thu 3",
            "Thu 4",
            "Thu 5",
            "Thu 6",
            "Thu 7",
            "Chủ nhật"});
            this.CB_Thu.Location = new System.Drawing.Point(326, 42);
            this.CB_Thu.Name = "CB_Thu";
            this.CB_Thu.Size = new System.Drawing.Size(121, 21);
            this.CB_Thu.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label3.Location = new System.Drawing.Point(332, 19);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "Thứ:";
            // 
            // dgv
            // 
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.Location = new System.Drawing.Point(25, 89);
            this.dgv.Name = "dgv";
            this.dgv.Size = new System.Drawing.Size(763, 300);
            this.dgv.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 426);
            this.Controls.Add(this.dgv);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.CB_Thu);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.CB_Namhoc);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CB_Hocki);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox CB_Hocki;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox CB_Namhoc;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox CB_Thu;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DataGridView dgv;
    }
}

