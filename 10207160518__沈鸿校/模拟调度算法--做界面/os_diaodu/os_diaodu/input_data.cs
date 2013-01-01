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
    public partial class input_data : Form
    {
        public input_data()
        {
            InitializeComponent();
        }
        /****************************************************************************/
        /*声明一个类，包含进程名P_name，进程到达时间T_arrived，执行时间T_run，*/
        /****************************************************************************/
        class P_diaodu
        {
           public string P_name;
            public int T_arrived;
            public int T_run;
        }
        //声明一个排序的方法
        public int sort_Array(int []t)
        {
            int temp = 0;
            for (int i = 0; i < 3; i++)
            {
                temp = t[i];
                for (int j = i + 1; j < 3; j++) { if (t[i] > t[j]) { t[i] = t[j]; t[j] = temp; } }
            }
            return 0;
        }
        class fcfs1
        {
            private static int temp, temp3;//定义一个局部static变量，在没有显示赋值之前采用默认赋值0,显示复制后就代表上个进程的结束时间。
            private static int count;
            private static double temp2;
            public void f(int tc, int ts, String p){
	  int te=0,tre=0;double w=0.0;
	  tre=temp-tc;
	  if(tre<0)tre=0; 
	  te=temp+ts-tc;
	  w=(double)te/ts;
	  count++;		//计数器
	  temp3+=te;
	  temp=ts+temp;
	  temp2=temp2+w;
	  /*System.out.printf("进程"+p+":\n从"+(temp-ts)+"时间开始进行调度\n"+"响应时间tre=："+tre+";\n"+"周转时间te="+te+";\n"+"带权周转时间w="+w+";\n");*/
	}
            public void aver_zz(){
		//for(int i=0;i<10;i++)System.out.print("* ");//System.out.println();
		/*System.out.printf("平均周转时间是"+(temp3/count)+";\n平均带权周转时间是"+(temp2/count)+";\n");*/
	}
        }
        P_diaodu[] a = { new P_diaodu(), new P_diaodu(), new P_diaodu() };
        public void receive_form() 
        {
          
            try
            {
                a[1].P_name = "A";
                a[1].T_arrived = Convert.ToInt32(a_c.Text);
                 a[1].T_run =Convert.ToInt32(a_s.Text);
                 a[2].P_name = "B";
                 a[2].T_arrived = Convert.ToInt32(b_c.Text);
                 a[2].T_run = Convert.ToInt32(b_s.Text);
                 a[3].P_name = "C";
                a[3].T_arrived = Convert.ToInt32(c_c.Text);
                 a[3].T_run = Convert.ToInt32(c_s.Text);
                
            }
            catch (Exception e) { MessageBox.Show("你还没填写完整"); e.GetBaseException(); }
   
        }

        private void SUMMIT_Click(object sender, EventArgs e)
        {
            int[]p={a[0].T_arrived,a[1].T_arrived,a[3].T_arrived};
            receive_form();
            if (FCFS.Checked) 
            {
                sort_Array(p);
            }
            if (SPF.Checked) MessageBox.Show("nihaoa");
            this.Dispose();
        }

        private void RESET_Click(object sender, EventArgs e)
        {
            a_c.Text = "";
            a_s.Text = "";
            b_c.Text = "";
            b_s.Text = "";
            c_c.Text = "";
            c_s.Text = "";
        }

        private void input_data_Load(object sender, EventArgs e)
        {

        }

       
    }
}
