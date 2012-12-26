
/*
 * 说明：
 *  	1.te代表周转时间,tc代表到达时间,w代表带权周转时间,tre代表响应时间,ts代表进程服务时间。
 * 		2响应时间是：用户发出请求到系统做出相应的时间段，周转时间是从提交到结束的时间段，带权周转时间是周转时间/进程服务时间。
 * */

class fcfs1{
	private static int temp,temp3,te1;//定义一个局部static变量，在没有显示赋值之前采用默认赋值0,显示复制后就代表上个进程的结束时间。
	private static int count;
	private static double temp2;
	public void f(int tc,int ts,String p){
	  int te=0,tre=0;double w=0.0;
	  tre=temp-tc;
	  if(tre<0)tre=0; 
	  te=temp+ts-tc;
	  w=(double)te/ts;
	  count++;		//计数器
	  temp3+=te;
	  temp=ts+temp;
	  temp2=temp2+w;
	  System.out.printf("进程"+p+":\n从"+(temp-ts)+"时间开始进行调度\n"+"响应时间tre=："+tre+";\n"+"周转时间te="+te+";\n"+"带权周转时间w="+w+";\n");
	}
	public void aver_zz(){
		for(int i=0;i<10;i++)System.out.print("* ");System.out.println();
		System.out.printf("平均周转时间是"+(temp3/count)+";\n平均带权周转时间是"+(temp2/count)+";\n");
	}
}

public class Fcf {

	
	public static void main(String[] args) {
		fcfs1 t=new fcfs1();//类组合
		/*t.f(0, 1, "A");
		t.f(1, 100, "B"); 
		t.f(2, 1, "C");*/
		t.f(0, 4, "A");
		t.f(1, 3, "B");
		t.f(2, 5, "C");
		t.f(3, 2, "D");
		t.f(4, 4, "E");
		t.aver_zz();
	}

}
