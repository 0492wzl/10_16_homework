using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace os_diaodu
{
    public partial class about : Form
    {
        public about()
        {
            InitializeComponent();
        }

        private void about_Load(object sender, EventArgs e)
        {
            

        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            Graphics g = e.Graphics;
            
           
        }

        private void about_close_Click(object sender, EventArgs e)
        {
            Graphics g;
            g = this.CreateGraphics();
            Font objfont;
            objfont = new System.Drawing.Font("宋体",14);
            g.DrawString("这是第一次在c#中显示文字,但是还不是很会", this.Font, System.Drawing.Brushes.Blue, 24, 32);
            g.DrawString("由于要期末考试了，暂时先不做了", this.Font, System.Drawing.Brushes.Blue, 24, 50);
        }
       
    }
}
