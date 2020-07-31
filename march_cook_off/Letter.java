import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Letter
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    long res,left,right,leftm,rightm;
	    int i,j,t,flag=-1,n,q,x,y,k;
	    String inst;
	    char c;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	res=1;
	    	n=scan.nextInt();
	    	q=scan.nextInt();
	    	long[] b=new long[n];
	    	long[] sum=new long[n];
	    	long[] l=new long[n];
	    	long[] r=new long[n];
	    	b[0]=scan.nextLong();
	    	sum[0]=b[0];
	    	r[0]=Math.max(b[0],0);
	    	for(j=1;j<n;j++){
	    		b[j]=scan.nextLong();
	    		sum[j]=b[j]+b[j-1];
	    		r[j]=Math.max(sum[j],r[j-1]);
	    	}
	    	left=b[n-1];
	    	l[n-1]=Math.max(0,b[n-1]);
	    	for(j=n-2;j>=0;j--){
	    		left+=b[j];
	    		l[j]=Math.max(left,l[j+1]);
	    		
	    	}
	    	for(j=0;j<q;j++){
	    		inst=scan.next();
	    		if(inst.equals("U")){
	    			x=scan.nextInt();
	    			y=scan.nextInt();
	    			b[x-1]=y;
	    		}else{
	    			res=0;
	    			left=0;
	    			leftm=0;
	    			rightm=0;
	    			right=0;
	    			x=scan.nextInt()-1;
	    			y=scan.nextInt()-1;
	    			for(k=x-1;k>=0;k--){
	    				left+=b[k];
	    				leftm=Math.max(left,leftm);
	    			}
	    			for(k=y+1;k<n;k++){
	    				right+=b[k];
	    				rightm=Math.max(right,rightm);
	    			}
	    			for(k=x;k<=y;k++){
	    				res+=b[k];
	    			}
	    			res=res+leftm+rightm;
	    			System.out.println(res);
	    		}
	    	}
	        
	    }
		// your code goes here
	}
}