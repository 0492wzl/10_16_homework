
/*
 * ˵����
 *  	1.te������תʱ��,tc������ʱ��,w�����Ȩ��תʱ��,tre������Ӧʱ��,ts������̷���ʱ�䡣
 * 		2��Ӧʱ���ǣ��û���������ϵͳ������Ӧ��ʱ��Σ���תʱ���Ǵ��ύ��������ʱ��Σ���Ȩ��תʱ������תʱ��/���̷���ʱ�䡣
 * */

class fcfs1{
	private static int temp,temp3,te1;//����һ���ֲ�static��������û����ʾ��ֵ֮ǰ����Ĭ�ϸ�ֵ0,��ʾ���ƺ�ʹ����ϸ����̵Ľ���ʱ�䡣
	private static int count;
	private static double temp2;
	public void f(int tc,int ts,String p){
	  int te=0,tre=0;double w=0.0;
	  tre=temp-tc;
	  if(tre<0)tre=0; 
	  te=temp+ts-tc;
	  w=(double)te/ts;
	  count++;		//������
	  temp3+=te;
	  temp=ts+temp;
	  temp2=temp2+w;
	  System.out.printf("����"+p+":\n��"+(temp-ts)+"ʱ�俪ʼ���е���\n"+"��Ӧʱ��tre=��"+tre+";\n"+"��תʱ��te="+te+";\n"+"��Ȩ��תʱ��w="+w+";\n");
	}
	public void aver_zz(){
		for(int i=0;i<10;i++)System.out.print("* ");System.out.println();
		System.out.printf("ƽ����תʱ����"+(temp3/count)+";\nƽ����Ȩ��תʱ����"+(temp2/count)+";\n");
	}
}

public class Fcf {

	
	public static void main(String[] args) {
		fcfs1 t=new fcfs1();//�����
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
