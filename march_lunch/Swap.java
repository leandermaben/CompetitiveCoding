import java.util.*;
import java.lang.*;
import java.io.*;

public class Swap
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    int i,j,n,m,t,sum,sum1,sum2,a,b,a1,a0,b1,b0;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	sum=0;
	        a=scan.nextInt();
	        b=scan.nextInt();
	        a1=a/10;
	        a0=a%10;
	        b1=b/10;
	        b0=b%10;
	        if(a1==0 && b1==0)
	        	sum=a+b;
	        else if(a1!=0 && b1!=0){
	        		sum1=a0*10+b0+a1*10+b1;
	        		sum2=b0*10+a0+b1*10+a1;
	        		sum=Math.max(sum1,sum2);
	        		sum=Math.max(sum,a+b);
	        }else if(a1!=0 && b1==0){
	        	if(b0>a1){
	        		sum=b0*10+a1+a0;
	        	}else{
	        		sum=a+b;
	        	}
	        }else{
	        	if(a0>b1){
	        		sum=a0*10+b1+b0;
	        	}else{
	        		sum=a+b;
	        	}
	        }
	       System.out.println(sum);
	    }
		// your code goes here
	}
}