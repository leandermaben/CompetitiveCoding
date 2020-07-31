import java.util.*;
import java.lang.*;
import java.io.*;

public class Bogo
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    int i,j,n,m,t,sum;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	        n=scan.nextInt();
	        Integer[] a=new Integer[n];
	        for(j=0;j<n;j++){
	        	a[j]=scan.nextInt();
	        }
	       Arrays.sort(a,Collections.reverseOrder());
	       for(j=0;j<n;j++){
	       		System.out.print(a[j]+" ");
	       }
	       System.out.println();
	    }
		// your code goes here
	}
}