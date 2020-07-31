import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Seq
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    long x,y,res;
	    int i,j,t,flag=-1,n;
	    String inst;
	    char c;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	res=1;
	    	n=scan.nextInt();
	    	long[] b=new long[n];
	    	for(j=0;j<n;j++){
	    		b[j]=scan.nextLong();
	    	}
	    	for(j=0;j<n-1;j++){
	    		x=b[j];
	    		y=b[j+1];
	    		while(x!=0||y!=0){
	    			if((x&1)==1&&(y&1)==0){
	    				res=0;
	    				break;
	    			}else if((x&1)==1){
	    				res*=2;
	    				res=res%1000000007;
	    			}
	    			x>>=1;
	    			y>>=1;
	    		}
	    		if(res==0)
	    			break;
	    	}
	        System.out.println(res);
	    }
		// your code goes here
	}
}