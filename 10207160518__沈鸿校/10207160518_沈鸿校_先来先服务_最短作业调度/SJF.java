
class sjf_time{
	private static int Tlastend,Wdqzz_avg,Tzz_avg,count=0;
	public void sfj(int tc,int tr,int p){
		int Tzz=0;
		double Wdqzz=0.0;
		Tzz=Tlastend+tr-tc;
		Wdqzz=(double)Tzz/tr;
		Tlastend+=tr;
		count++;
		Wdqzz_avg+=Wdqzz;
		Tzz_avg+=Tzz;
		System.out.print("进程"+p+":\n"+"周转时间T="+Tzz+"；\n带权周转时间T="+Wdqzz+";\n");
	}
	public void fc_avg(){
		for(int i=0;i<10;i++)System.out.print("* ");
		System.out.print("\n平均周转时间T="+(Tzz_avg/count)+";\n平均带权周转时间T="+(Wdqzz_avg/count)+";\n");
	}
}
public class SJF {

	
	public static void main(String[] args) {
		sjf_time t=new sjf_time();		//创建sjf_time的引用t
		int[] tc={0,1,2,3,4};
		int[] tr={4,3,5,2,4};
		for(int i=1;i<tr.length;i++){
			int temp1=tr[i];
			for(int j=i+1;j<tr.length;j++){
				int temp2;
				if(temp1>tr[j]){temp1=tr[j];tr[j]=tr[i];tr[i]=temp1;temp2=tc[j];tc[j]=tc[i];tc[i]=temp2;}
			}
		}
		for(int t1=0,p=0;p<tr.length;p++,t1++)new sjf_time().sfj(tc[p], tr[p], tc[t1]+1);
		t.fc_avg();
	}

}
