using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Caro
{
    public partial class Form1 : Form
    {
        Button Button_temp;
        private int currentPlayer;
        Player ply1 = new Player("Player 1", Image.FromFile(Application.StartupPath + "\\Resources\\O.png"));
        Player ply2 = new Player("Player 2", Image.FromFile(Application.StartupPath + "\\Resources\\X.png"));

        public int CurrentPlayer { get => currentPlayer; set => currentPlayer = value; }

        private List<List<Button>> matrix;
        public List<List<Button>> Matrix { get => matrix; set => matrix = value; }
        /// <summary>
        /// Tao event timer
        /// </summary>
        private event EventHandler playerMark;
        public event EventHandler PlayerMark
        {
            add
            {
                playerMark += value;
            }
            remove
            {
                playerMark -= value;
            }
        }
        /// <summary>
        /// Event End Game
        /// </summary>
        private event EventHandler end_Game;
        public event EventHandler End_Game
        {
            add
            {
                end_Game += value;
            }
            remove
            {
                end_Game -= value;
            }
        }

        public Form1()
        {
            InitializeComponent();
            Draw();
            pcbCoolDown.Step = Const.COOLDOWN_STEP;
            pcbCoolDown.Maximum = Const.COOLDOWN_TIME;
            pcbCoolDown.Value = 0;
            tmCoolDown.Interval = Const.COOLDOWN_INTERVAL;
            CurrentPlayer = 1;
            End_Game += ChessBoard_EndGame;
            PlayerMark += ChessBoard_PlayerMark;
        }

        void StopScreen()
        {
            tmCoolDown.Stop();
            pcbCoolDown.Value = 0;
            Panel_ChessBoard.Enabled = false;
            button1.Enabled = false;
        }
        void ExitGame()
        {
            StopScreen();
            MessageBox.Show("Ket thuc!");
        }
        private void ChessBoard_PlayerMark(object sender, EventArgs e)
        {
            tmCoolDown.Start();
            pcbCoolDown.Value = 0;
        }
        
        private void ChessBoard_EndGame(object sender, EventArgs e)
        {          
            ExitGame();
        }

        void Draw()
        {
            Enabled = true; 
            //tao mang 
            Matrix = new List<List<Button>>();
            Button oldbtn = new Button() { Width=0,Location = new Point(0,0)};
            for (int i = 0; i < Const.Size+1; i++)
            {
                Matrix.Add(new List<Button>());//add 1 hang ngang vao matrix
                for (int j = 0; j < Const.Size+1; j++)
                {
                    Button btn = new Button()
                    {
                        Width = Const.Width,
                        Height = Const.Height,
                        Location = new Point(oldbtn.Location.X + oldbtn.Width, oldbtn.Location.Y),
                        BackgroundImageLayout = ImageLayout.Stretch,
                        Tag = i.ToString()
                    };
                    btn.Click += btn_Click;

                    Panel_ChessBoard.Controls.Add(btn);
                    Matrix[i].Add(btn);
                    oldbtn = btn;
                }
                oldbtn.Location = new Point(0, oldbtn.Location.Y + Const.Height);
                oldbtn.Width = 0;
                Player_Name.BackColor = Color.LightGreen;
                //oldbtn.Height = 0;
            }
        }

        public void EndGame()
        {
            StopScreen();
            string Winner;
            if (currentPlayer == 1)
                Winner = ply2.Name + " Win!";
            else
                Winner = ply1.Name + " Win!";
            MessageBox.Show(Winner);
        }

        private void tmCoolDown_Tick(object sender, EventArgs e)
        {
            pcbCoolDown.PerformStep();
            if(pcbCoolDown.Value >= pcbCoolDown.Maximum)
            {               
                ExitGame();               
            }
        }
        
        private bool IsEnd(Button btn)
        {
            return end_Ngang(btn) || end_Doc(btn) || end_CheoHuyen(btn) || end_CheoSac(btn);
        }
        private Point GetPoint(Button btn)
        {         
            int ToaDoY = Convert.ToInt32(btn.Tag);
            int ToaDoX = Matrix[ToaDoY].IndexOf(btn);
            Point point = new Point(ToaDoX,ToaDoY);
            return point;
        }
        private bool end_Ngang(Button btn)
        {
            Point point = GetPoint(btn);

            int count = 0;
            for (int i = point.X+1; i < Const.Size; i++)
            {
                if (Matrix[point.Y][i].BackgroundImage == btn.BackgroundImage)
                    count++;
                else
                    break;
            }
            for (int i = point.X; i>=0; i--)
            {
                if (Matrix[point.Y][i].BackgroundImage == btn.BackgroundImage)
                    count++;
                else
                    break;
            }
            return count>=5;
        }
        private bool end_Doc(Button btn)
        {
            Point point = GetPoint(btn);

            int count = 0;
            for (int i = point.Y + 1; i < Const.Size; i++)
            {
                if (Matrix[i][point.X].BackgroundImage == btn.BackgroundImage)
                    count++;
                else
                    break;
            }
            for (int i = point.Y; i >= 0; i--)
            {
                if (Matrix[i][point.X].BackgroundImage == btn.BackgroundImage)
                    count++;
                else
                    break;
            }
            return count >= 5;
        }
        private bool end_CheoSac(Button btn)
        {
            Point point = GetPoint(btn);
            int count = 0;
            int i = point.Y-1, j = point.X+1;
            while(i>=0 && j <Const.Size)
            {
                if (Matrix[i][j].BackgroundImage == btn.BackgroundImage)
                {
                    count++;
                    i--;
                    j++;
                }
                else
                    break;
            }
            i = point.Y; j = point.X;
            while (i < Const.Size && j >=0)
            {
                if (Matrix[i][j].BackgroundImage == btn.BackgroundImage)
                {
                    count++;
                    i++;
                    j--;
                }
                else
                    break;
            }
            return count >= 5;
        }
        private bool end_CheoHuyen(Button btn)
        {
            Point point = GetPoint(btn);
            int count = 0;
            int i = point.Y + 1, j = point.X + 1;
            while (i <=Const.Size  && j < Const.Size)
            {
                if (Matrix[i][j].BackgroundImage == btn.BackgroundImage)
                {
                    count++;
                    i++;
                    j++;
                }
                else
                    break;
            }
            i = point.Y; j = point.X;
            while (i >=0 && j >= 0)
            {
                if (Matrix[i][j].BackgroundImage == btn.BackgroundImage)
                {
                    count++;
                    i--;
                    j--;
                }
                else
                    break;
            }
            return count >= 5;           
        }

        private void btn_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (btn.BackgroundImage != null)
                return;
            Button_temp = btn;
            if (currentPlayer == 1)
            {
                btn.BackgroundImage = ply1.Mark;
                currentPlayer = 2;
                Player_Name .Text= ply2.Name;
                Player_Mark .Image= ply2.Mark;
                Player_Name.BackColor = Color.OrangeRed;
            }
            else
            {
                btn.BackgroundImage = ply2.Mark;
                currentPlayer = 1;
                Player_Name.Text = ply1.Name;
                Player_Mark.Image = ply1.Mark;
                Player_Name.BackColor = Color.LightGreen;
            }
            if (playerMark != null)
                playerMark(this, new EventArgs());
            if(IsEnd(btn))
            {              
                EndGame();
            }
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Player_Name.Text = ply1.Name;
            Player_Mark.Image = ply1.Mark;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(Button_temp.BackgroundImage!=null)
            {
                Button_temp.BackgroundImage = null;
                if (playerMark != null)
                    playerMark(this, new EventArgs());
                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                    Player_Name.Text = ply2.Name;
                    Player_Mark.Image = ply2.Mark;
                }
                else
                {
                    currentPlayer = 1;
                    Player_Name.Text = ply1.Name;
                    Player_Mark.Image = ply1.Mark;
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < Const.Size; i++)
            {
                for (int j = 0; j < Const.Size; j++)
                {
                    Matrix[j][i].BackgroundImage = null;
                }
            }
            tmCoolDown.Stop();
            pcbCoolDown.Value = 0;
            Panel_ChessBoard.Enabled = true;
            button1.Enabled = true;
            Player_Mark.Image = null;
            Player_Name.Text = null;
        }
        void QuitGame()
        {
            
            Application.Exit();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            QuitGame();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("Bạn có muốn thoát game", "Thông báo", MessageBoxButtons.OKCancel) != System.Windows.Forms.DialogResult.OK)           
                 e.Cancel = true;
        }

        private void Panel_ChessBoard_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
