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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.comboBox1.Items.Add(this.textBox1.Text);
            for (int i = 0; i < this.comboBox1.Items.Count; ++i) 
            {
                for (int j = i + 1; j < this.comboBox1.Items.Count; ++j)
                {
                    if (this.comboBox1.Items[i] == this.comboBox1.Items[j])
                        this.comboBox1.Items.Remove(this.comboBox1.Items[j]);
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.label2.Text = DateTime.Now.ToString();
        }
    }
}
