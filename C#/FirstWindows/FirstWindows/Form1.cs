using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FirstWindows
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int ans = Convert.ToInt16(this.textBox1.Text) + Convert.ToInt16(this.textBox2.Text);
            this.textBox3.Text = ans.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (this.checkBox1.Checked && this.checkBox3.Checked)
            {
                if (!this.checkBox2.Checked && !this.checkBox4.Checked)
                    MessageBox.Show("你居然答对了。", "输出", MessageBoxButtons.OK);
                else
                    MessageBox.Show("对不起，你选多了。", "输出", MessageBoxButtons.OKCancel);
            }
            else
                MessageBox.Show("你选错了，太LOW了。");
        }
    }
}
