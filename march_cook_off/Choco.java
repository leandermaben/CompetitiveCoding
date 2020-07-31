import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Choco
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    long max,k,shift;
	    int i,j,t,n;
	    String inst;
	    char c;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	max=-1;
	    	n=scan.nextInt();
	    	long[] ind =new long[n];
	    	long[] w=new long[n];
	    	long[] diff=new long[n];
	    	int l=0;
	    	for(j=0;j<n;j++){
	    		w[j]=scan.nextLong();
	    		if(max<w[j]){
	    			max=w[j];
	    		}
	    	}
	    	for(j=0;j<n;j++){
	    		if(max==w[j]){
	    			ind[l++]=j+1;
	    		}
	    	}
	    	if(l==1){
	    		k=n/2;
	    	}else{
	    		k=0;
	    		for(j=0;j<l-1;j++){
	    			diff[j]=ind[j+1]-ind[j]-1;
	    		}
	    		diff[j]=n-ind[l-1]+ind[0]-1;
	    			for(j=0;j<l;j++){
	    				k+=Math.max(diff[j]-n/2+1,0);
	    			}
	    		
	    	}
	        System.out.println(k);
	    }
		// your code goes here
	}
}