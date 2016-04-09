using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace _2048Game
{
    public partial class Form1 : Form
    {
        //可生成分数列表
        int[] score_list = new int[] { 2, 4 };
        //当前得分
        int total = 0;
        //存储分数的文件名
        string filename = "score.txt";
      
        //行数
        const int row = 4;
        //列数
        const int col = 4;
        //显示分数的数组
        Label[,] Label_set = new Label[row, col];
        //当前分数按钮
        Label Label_score = new Label();
        //最高分按钮
        Label Label_heighest = new Label();
        public Form1()
        {
            InitializeComponent();
        }

        //初始化，产生4 * 4的方格并选择两个方格随机填写score
        //Game load
        private void Form1_Load(object sender, EventArgs e)
        {
            //开始的位置是10， 10， 每个标签的大小是50*50
            int x = 10, y = 10, size = 50;
            for (int i = 0; i < col; ++i)
            {
                for (int j = 0; j < row; ++j)
                {
                    Random rn = new Random();
                    Label B = new Label();
                    B.Text = "";
                    B.Location = new System.Drawing.Point(y + size * j, x + size * i);
                    B.Visible = true;
                    B.Size = new System.Drawing.Size(size, size);
                    B.Enabled = true;
                    B.BackColor = Color.YellowGreen;
                    //B.TabIndex = 12122121;
                    Label_set[i, j] = B;
                    this.Controls.Add(B);
                }
            }
           
            //当前分数和最高分
            Label_score.Text = "Your scores:\n" + total.ToString();
            Label_score.Location = new System.Drawing.Point(10, 220);
            Label_score.Visible = true;
            Label_score.Size = new System.Drawing.Size(120, 45);
            Label_score.Enabled = true;
            this.Controls.Add(Label_score);


            //FileStream fp = new FileStream(filename, FileMode.Open);
            Label_heighest.Text = "heighest scores：\n";
            //FileStream fs = new FileStream(filename, Encoding.Default);
            Label_heighest.Location = new System.Drawing.Point(130, 220);
            Label_heighest.Visible = true;
            Label_heighest.Size = new System.Drawing.Size(120, 45);
            Label_heighest.Enabled = true;
            this.Controls.Add(Label_heighest);
            
            //选择两个格子产生score
            Random rnd = new Random();
            int times = 2;
            while (times > 0)
            {
                int i = rnd.Next(row), j = rnd.Next(col);
                if(Label_set[i, j].Text == "")
                {
                    times--;
                    int score = score_list[rnd.Next(2)];
                    Label_set[i, j].Text = score.ToString();
                }
            }
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {

            //MessageBox.Show("in Form1_KeyDown");
            //if(e.KeyCode)
        }

        //捕获键盘按下的方向键
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            //MessageBox.Show("in Form1_KeyDown");
            if (e.KeyCode == Keys.Up)
            { 
                merge("UP");
            }
            else if (e.KeyCode == Keys.Down)
            {
                merge("DOWN");
            }
            else if (e.KeyCode == Keys.Left)
            {
                merge("LEFT");
            }
            else if (e.KeyCode == Keys.Right)
            {
                merge("RIGHT");
            }
        }
        private void merge(string key)
        {
            //MessageBox.Show(key);
            if (key == "UP")
            {
                for (int i = 0; i < col; ++i)
                {
                    int pos = 0;
                    for (int j = 0; j < row; ++j)
                    {
                        if (Label_set[j, i].Text != "")
                        {
                            Label_set[pos, i].Text = Label_set[j, i].Text;
                            pos++;
                        }
                    }
                    while (pos < row)
                    {
                        Label_set[pos, i].Text = "";
                        pos++;
                    }
                }
                for (int i = 0; i < col; ++i)
                {
                    for (int j = 0; j < row - 1; ++j)
                    {
                        string st1 = Label_set[j, i].Text, st2 = Label_set[j + 1, i].Text;
                        if (st1 != "" && st2 != "" && st1 == st2)
                        {
                            int val = Convert.ToInt16(st1);
                            val *= 2;
                            total += val;
                            Label_set[j, i].Text = val.ToString();
                            for (int k = j + 1; k < row - 1; ++k)
                            {
                                Label_set[k, i].Text = Label_set[k + 1, i].Text;
                            }
                            Label_set[row - 1, i].Text = "";
                            j = -1;
                        }
                    }  
                }
            } 
            else if(key == "DOWN")
            {
                for (int i = 0; i < col; ++i)
                {
                    int pos = row - 1;
                    for (int j = row - 1; j >= 0; --j)
                    {
                        if (Label_set[j, i].Text != "")
                        {
                            Label_set[pos, i].Text = Label_set[j, i].Text;
                            pos--;
                        }
                    }
                    while (pos >= 0)
                    {
                        Label_set[pos, i].Text = "";
                        pos--;
                    }
                }
                for (int i = 0; i < col; ++i)
                {
                    for (int j = row - 1; j > 0; --j)
                    {
                        string st1 = Label_set[j, i].Text, st2 = Label_set[j - 1, i].Text;
                        if (st1 != "" && st1 != "" && st1 == st2)
                        {
                            int val = Convert.ToInt16(st1);
                            val *= 2;
                            total += val;
                            Label_set[j, i].Text = val.ToString();
                            for (int k = j - 1; k > 0; --k)
                            {
                                Label_set[k, i].Text = Label_set[k - 1, i].Text;
                            }
                            Label_set[0, i].Text = "";
                        }
                    }
                }
            }
            else if (key == "LEFT")
            {
                for (int i = 0; i < row; ++i )
                {
                    int pos = 0;
                    for (int j = 0; j < col; ++j)
                    {
                        if (Label_set[i, j].Text != "")
                        {
                            Label_set[i, pos].Text = Label_set[i, j].Text;
                            pos++;
                        }
                        
                    }
                    while (pos < col)
                    {
                        Label_set[i, pos].Text = "";
                        pos++;
                    }
                }
                
                for (int i = 0; i < row; ++i)
                {
                    for (int j = 0; j < col - 1; ++j)
                    {
                        string st1 = Label_set[i, j].Text, st2 = Label_set[i, j + 1].Text;
                        if (st1 != "" && st2 != "" && st1 == st2)
                        {
                            int val = Convert.ToInt16(st1);
                            val += val;
                            total += val;
                            Label_set[i, j].Text = val.ToString();
                            for (int k = j + 1; k < col - 1; ++k)
                            {
                                Label_set[i, k].Text = Label_set[i, k + 1].Text;
                            }
                            Label_set[i, col - 1].Text = "";
                        }
                    }
                }
                
            }
            else if (key == "RIGHT")
            {
                for (int i = 0; i < row; ++i )
                {
                    int pos = col - 1;
                    for (int j = col - 1; j >= 0; --j)
                    {
                        if (Label_set[i, j].Text != "")
                        {
                            Label_set[i, pos].Text = Label_set[i, j].Text;
                            pos--;
                        }
                        
                    }
                    while (pos >= 0)
                    {
                        Label_set[i, pos].Text = "";
                        pos--;
                    }
                }
                for (int i = 0; i < row; ++i)
                {
                    for (int j = col - 1; j > 0; --j)
                    {
                        string st1 = Label_set[i, j].Text, st2 = Label_set[i, j - 1].Text;
                        if (st1 != "" && st2 != "" && st1 == st2)
                        {
                            int val = Convert.ToInt16(st1);
                            val += val;
                            total += val;
                            Label_set[i, j].Text = val.ToString();
                            for (int k = j - 1; k > 0; --k)
                            {
                                Label_set[i, k].Text = Label_set[i, k - 1].Text;
                            }
                            Label_set[i, 0].Text = "";
                        }
                    }
                }
            }
            Label_score.Text = total.ToString();
            
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            //MessageBox.Show("Form1_KeyUp in");
            if (e.KeyCode == Keys.Up)
            {
                merge("UP");
            }
            else if (e.KeyCode == Keys.Down)
            {
                merge("DOWN");
            }
            else if (e.KeyCode == Keys.Left)
            {
                merge("LEFT");
            }
            else if (e.KeyCode == Keys.Right)
            {
                merge("RIGHT");
            }
            random();
            Reload();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            
        }
        private void Reload()
        {
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    Label_set[i, j].Update();
                }
            }
            Label_score.Text = "Your scores:\n" + total.ToString();
            Label_heighest.Text = "Heighest scores:\n" + total.ToString();
        }
        private void random()
        {
            Random rnd = new Random();
            while (true)
            {
                int x = rnd.Next(row), y = rnd.Next(col);
                if (Label_set[x, y].Text == "")
                {
                    int pos = rnd.Next(1);
                    Label_set[x, y].Text = score_list[pos].ToString();
                    break;
                }
            }
        }
        /*public void press_left();
        public void press_rigth();
        public void press_up();
        public void press_down();
        public void merge();
        public void choic_score();
        public void count();
        public void death();
        */
    }
}
