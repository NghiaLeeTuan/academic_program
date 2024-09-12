using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private double result;
        double data1, data2;
        string pheptinh;
        private bool flag;
        public Form1()
        {
            InitializeComponent();
            flag = true;
            result= 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button18_Click(object sender, EventArgs e)
        {
            data1 = float.Parse(ketqua.Text) /100;
            ketqua.Text = data1.ToString();
        }



        private void button1_Click_2(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "1";
            }
            else
                this.ketqua.Text = "1";
            this.flag = true;
 
        }

        private void bt0_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "0";
            }
            else
                this.ketqua.Text = "0";
            this.flag = true;
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "2";
            }
            else
                this.ketqua.Text = "2";
            this.flag = true;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "3";
            }
            else
                this.ketqua.Text = "3";
            this.flag = true;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "4";
            }
            else
                this.ketqua.Text = "4";
            this.flag = true;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "5";
            }
            else
                this.ketqua.Text = "5";
            this.flag = true;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "6";
            }
            else
                this.ketqua.Text = "6";
            this.flag = true;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "7";
            }
            else
                this.ketqua.Text = "7";
            this.flag = true;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "8";
            }
            else
                this.ketqua.Text = "8";
            this.flag = true;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "9";
            }
            else
                this.ketqua.Text = "9";
            this.flag = true;
        }

        private void button14_Click(object sender, EventArgs e)
        {

            pheptinh = "+";
            data1 = float.Parse(ketqua.Text);
            ketqua.Clear();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            pheptinh = "-";
            data1 = float.Parse(ketqua.Text);
            ketqua.Clear();
        }

        private void button16_Click(object sender, EventArgs e)
        {
            pheptinh = "*";
            data1 = float.Parse(ketqua.Text);
            ketqua.Clear();
        }

        private void button21_Click(object sender, EventArgs e)
        {
            ketqua.Clear();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            if (pheptinh == "+")
            {
                data2 = data1 + float.Parse(ketqua.Text);
                ketqua.Text = data2.ToString();
            }
            else if (pheptinh == "-")
            {
                data2 = data1 - float.Parse(ketqua.Text);
                ketqua.Text = data2.ToString();
            }
            else if (pheptinh=="*")
            {
                data2 = data1 * float.Parse(ketqua.Text);
                ketqua.Text = data2.ToString();
            }
            else if (pheptinh == "/")
            {
                if (float.Parse(ketqua.Text) == 0)
                {
                    ketqua.Text = "Error";
                }
                else
                {
                    data2 = data1 / float.Parse(ketqua.Text);
                    ketqua.Text = data2.ToString();
                }
            }
        }

        private void button25_Click(object sender, EventArgs e)
        {
            data1 = float.Parse(ketqua.Text) * float.Parse(ketqua.Text);
            ketqua.Text = data1.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ketqua.Text=ketqua.Text.Remove(ketqua.Text.Length-1);
        }

        private void button20_Click(object sender, EventArgs e)
        {
            data1 = Math.Sqrt(double.Parse(ketqua.Text));
            ketqua.Text = data1.ToString();
        }

        private void button19_Click(object sender, EventArgs e)
        {
            if (this.ketqua.Text == "0")
            {
                this.ketqua.Text = "";
            }
            if (flag == true)
            {
                this.ketqua.Text += "3.14159";
            }
            else
                this.ketqua.Text = "3.14159";
            this.flag = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.ketqua.Text += ".";
        }

        private void button22_Click(object sender, EventArgs e)
        {
            data1 = Math.Sin(float.Parse(ketqua.Text));
            ketqua.Text = data1.ToString();
        }

        private void button23_Click(object sender, EventArgs e)
        {
            data1 = Math.Cos(float.Parse(ketqua.Text));
            ketqua.Text = data1.ToString();
        }

        private void button24_Click(object sender, EventArgs e)
        {
            data1 = Math.Tan(float.Parse(ketqua.Text));
            ketqua.Text = data1.ToString();
        }

        private void button17_Click(object sender, EventArgs e)
        {
            pheptinh = "/";
            data1 = float.Parse(ketqua.Text);
            ketqua.Clear();
        }
    }
}

