import java.util.*;
import java.lang.*;
import java.io.*;

public class RegPoly
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    int i,j,n,m,t,sum;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	        n=scan.nextInt();
	        m=scan.nextInt();
	        if(n%m==0){
	        	System.out.println("YES");
	        }else{
	        	System.out.println("NO");
	        }
	    }
		// your code goes here
	}
}