using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace os_diaodu
{
    public partial class btn_color : Form
    {
        public btn_color()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
           
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            Graphics t = e.Graphics;

        }


        private void openToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            input_data inputdata1 = new input_data();
            inputdata1.Show();
        }

        private void exitToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            about about_us = new about();
            about_us.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics t;
            t = this.CreateGraphics();
            ColorDialog cd = new ColorDialog(); //新建一个颜色选择窗口
            cd.ShowDialog(); //让用户选择颜色
            Pen p = new Pen(cd.Color);  //定义一个Pen，使用这种颜色
            Font main_font = new System.Drawing.Font("宋体", 14);
            t.DrawLine(p,40,300,400,300);
            t.DrawLine(p, 40, 40, 40, 300);
            t.DrawString("由于要考试了，好多还不会做，先放下先，考完试在做了",main_font,System.Drawing.Brushes.Blue,42,200);
           
        }
        
       
    }
}
