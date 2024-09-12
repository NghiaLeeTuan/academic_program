
namespace WindowsFormsApp1
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
            this.txtmasv = new System.Windows.Forms.TextBox();
            this.txthoten = new System.Windows.Forms.TextBox();
            this.txthometown = new System.Windows.Forms.TextBox();
            this.txtbirth = new System.Windows.Forms.TextBox();
            this.txtemail = new System.Windows.Forms.TextBox();
            this.btsearch = new System.Windows.Forms.Button();
            this.txtsearch = new System.Windows.Forms.TextBox();
            this.btchon1 = new System.Windows.Forms.Button();
            this.bttrave = new System.Windows.Forms.Button();
            this.btchonlist = new System.Windows.Forms.Button();
            this.bttravelist = new System.Windows.Forms.Button();
            this.btthem = new System.Windows.Forms.Button();
            this.btclear = new System.Windows.Forms.Button();
            this.btclose = new System.Windows.Forms.Button();
            this.STT = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvdanhsachsv = new System.Windows.Forms.ListView();
            this.Email = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.BirthDay = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Hometown = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.name = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.MSSV = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvdanhsachchon = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // txtmasv
            // 
            this.txtmasv.Location = new System.Drawing.Point(12, 33);
            this.txtmasv.Name = "txtmasv";
            this.txtmasv.Size = new System.Drawing.Size(100, 20);
            this.txtmasv.TabIndex = 0;
            this.txtmasv.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // txthoten
            // 
            this.txthoten.Location = new System.Drawing.Point(129, 33);
            this.txthoten.Name = "txthoten";
            this.txthoten.Size = new System.Drawing.Size(162, 20);
            this.txthoten.TabIndex = 1;
            // 
            // txthometown
            // 
            this.txthometown.Location = new System.Drawing.Point(312, 33);
            this.txthometown.Name = "txthometown";
            this.txthometown.Size = new System.Drawing.Size(116, 20);
            this.txthometown.TabIndex = 2;
            // 
            // txtbirth
            // 
            this.txtbirth.Location = new System.Drawing.Point(449, 33);
            this.txtbirth.Name = "txtbirth";
            this.txtbirth.Size = new System.Drawing.Size(116, 20);
            this.txtbirth.TabIndex = 3;
            // 
            // txtemail
            // 
            this.txtemail.Location = new System.Drawing.Point(581, 33);
            this.txtemail.Name = "txtemail";
            this.txtemail.Size = new System.Drawing.Size(116, 20);
            this.txtemail.TabIndex = 4;
            // 
            // btsearch
            // 
            this.btsearch.Location = new System.Drawing.Point(279, 76);
            this.btsearch.Name = "btsearch";
            this.btsearch.Size = new System.Drawing.Size(75, 23);
            this.btsearch.TabIndex = 5;
            this.btsearch.Text = "button1";
            this.btsearch.UseVisualStyleBackColor = true;
            // 
            // txtsearch
            // 
            this.txtsearch.Location = new System.Drawing.Point(375, 79);
            this.txtsearch.Name = "txtsearch";
            this.txtsearch.Size = new System.Drawing.Size(362, 20);
            this.txtsearch.TabIndex = 6;
            // 
            // btchon1
            // 
            this.btchon1.Location = new System.Drawing.Point(515, 148);
            this.btchon1.Name = "btchon1";
            this.btchon1.Size = new System.Drawing.Size(75, 23);
            this.btchon1.TabIndex = 7;
            this.btchon1.Text = "button1";
            this.btchon1.UseVisualStyleBackColor = true;
            // 
            // bttrave
            // 
            this.bttrave.Location = new System.Drawing.Point(515, 206);
            this.bttrave.Name = "bttrave";
            this.bttrave.Size = new System.Drawing.Size(75, 23);
            this.bttrave.TabIndex = 8;
            this.bttrave.Text = "button2";
            this.bttrave.UseVisualStyleBackColor = true;
            // 
            // btchonlist
            // 
            this.btchonlist.Location = new System.Drawing.Point(515, 263);
            this.btchonlist.Name = "btchonlist";
            this.btchonlist.Size = new System.Drawing.Size(75, 23);
            this.btchonlist.TabIndex = 9;
            this.btchonlist.Text = "button3";
            this.btchonlist.UseVisualStyleBackColor = true;
            // 
            // bttravelist
            // 
            this.bttravelist.Location = new System.Drawing.Point(515, 319);
            this.bttravelist.Name = "bttravelist";
            this.bttravelist.Size = new System.Drawing.Size(75, 23);
            this.bttravelist.TabIndex = 10;
            this.bttravelist.Text = "button4";
            this.bttravelist.UseVisualStyleBackColor = true;
            // 
            // btthem
            // 
            this.btthem.Location = new System.Drawing.Point(751, 46);
            this.btthem.Name = "btthem";
            this.btthem.Size = new System.Drawing.Size(75, 23);
            this.btthem.TabIndex = 13;
            this.btthem.Text = "btthem";
            this.btthem.UseVisualStyleBackColor = true;
            this.btthem.Click += new System.EventHandler(this.btthem_Click);
            // 
            // btclear
            // 
            this.btclear.Location = new System.Drawing.Point(850, 46);
            this.btclear.Name = "btclear";
            this.btclear.Size = new System.Drawing.Size(75, 23);
            this.btclear.TabIndex = 14;
            this.btclear.Text = "button1";
            this.btclear.UseVisualStyleBackColor = true;
            // 
            // btclose
            // 
            this.btclose.Location = new System.Drawing.Point(958, 46);
            this.btclose.Name = "btclose";
            this.btclose.Size = new System.Drawing.Size(75, 23);
            this.btclose.TabIndex = 17;
            this.btclose.Text = "button1";
            this.btclose.UseVisualStyleBackColor = true;
            // 
            // STT
            // 
            this.STT.Text = "STT";
            this.STT.Width = 56;
            // 
            // lvdanhsachsv
            // 
            this.lvdanhsachsv.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.STT,
            this.MSSV,
            this.name,
            this.Hometown,
            this.BirthDay,
            this.Email});
            this.lvdanhsachsv.HideSelection = false;
            this.lvdanhsachsv.Location = new System.Drawing.Point(-2, 134);
            this.lvdanhsachsv.Name = "lvdanhsachsv";
            this.lvdanhsachsv.Size = new System.Drawing.Size(511, 238);
            this.lvdanhsachsv.TabIndex = 19;
            this.lvdanhsachsv.UseCompatibleStateImageBehavior = false;
            this.lvdanhsachsv.View = System.Windows.Forms.View.Details;
            // 
            // Email
            // 
            this.Email.Text = "Email";
            this.Email.Width = 80;
            // 
            // BirthDay
            // 
            this.BirthDay.Text = "BirthDay";
            this.BirthDay.Width = 80;
            // 
            // Hometown
            // 
            this.Hometown.Text = "Hometown";
            // 
            // name
            // 
            this.name.Text = "Name";
            this.name.Width = 80;
            // 
            // MSSV
            // 
            this.MSSV.Text = "MSSV";
            this.MSSV.Width = 150;
            // 
            // lvdanhsachchon
            // 
            this.lvdanhsachchon.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            this.lvdanhsachchon.HideSelection = false;
            this.lvdanhsachchon.Location = new System.Drawing.Point(596, 134);
            this.lvdanhsachchon.Name = "lvdanhsachchon";
            this.lvdanhsachchon.Size = new System.Drawing.Size(511, 238);
            this.lvdanhsachchon.TabIndex = 20;
            this.lvdanhsachchon.UseCompatibleStateImageBehavior = false;
            this.lvdanhsachchon.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "STT";
            this.columnHeader1.Width = 56;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "MSSV";
            this.columnHeader2.Width = 150;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Name";
            this.columnHeader3.Width = 80;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Hometown";
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "BirthDay";
            this.columnHeader5.Width = 80;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Email";
            this.columnHeader6.Width = 80;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1106, 384);
            this.Controls.Add(this.lvdanhsachchon);
            this.Controls.Add(this.lvdanhsachsv);
            this.Controls.Add(this.btclose);
            this.Controls.Add(this.btclear);
            this.Controls.Add(this.btthem);
            this.Controls.Add(this.bttravelist);
            this.Controls.Add(this.btchonlist);
            this.Controls.Add(this.bttrave);
            this.Controls.Add(this.btchon1);
            this.Controls.Add(this.txtsearch);
            this.Controls.Add(this.btsearch);
            this.Controls.Add(this.txtemail);
            this.Controls.Add(this.txtbirth);
            this.Controls.Add(this.txthometown);
            this.Controls.Add(this.txthoten);
            this.Controls.Add(this.txtmasv);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtmasv;
        private System.Windows.Forms.TextBox txthoten;
        private System.Windows.Forms.TextBox txthometown;
        private System.Windows.Forms.TextBox txtbirth;
        private System.Windows.Forms.TextBox txtemail;
        private System.Windows.Forms.Button btsearch;
        private System.Windows.Forms.TextBox txtsearch;
        private System.Windows.Forms.Button btchon1;
        private System.Windows.Forms.Button bttrave;
        private System.Windows.Forms.Button btchonlist;
        private System.Windows.Forms.Button bttravelist;
        private System.Windows.Forms.Button btthem;
        private System.Windows.Forms.Button btclear;
        private System.Windows.Forms.Button btclose;
        private System.Windows.Forms.ColumnHeader STT;
        private System.Windows.Forms.ListView lvdanhsachsv;
        private System.Windows.Forms.ColumnHeader MSSV;
        private System.Windows.Forms.ColumnHeader name;
        private System.Windows.Forms.ColumnHeader Hometown;
        private System.Windows.Forms.ColumnHeader BirthDay;
        private System.Windows.Forms.ColumnHeader Email;
        private System.Windows.Forms.ListView lvdanhsachchon;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
    }
}

