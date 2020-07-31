import java.util.*;
import java.lang.*;
import java.io.*;

public class Crypt
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    int i,j,n,m,t,sum,x,k=0;
	    long y;
	    int res,temp;
	    t=scan.nextInt();
	    boolean flag;
	    boolean[] sieve=new boolean[10000];
	    for(i=2;i<10000;i++){
	    	sieve[i]=true;
	    }
	    for(i=2;i<100;i++){
	    	if(sieve[i]==true){

	    		for(j=i*i;j<10000;j+=i){
	    			sieve[j]=false;
	    		}
	    	}
	    }
	    for(i=0;i<t;i++){
	    	k=0;
	    	res=1;
	    	temp=1;
	        n=scan.nextInt();
	        m=scan.nextInt();
	        ArrayList<Integer> primes=new ArrayList<>();
	        for(j=2;j<=m;j++){
	        	if(sieve[j]==true){
	        		primes.add(j);
	        	}
	        }
	        int[] a=new int[n];
	    	for(j=0;j<n;j++){
	       		a[j]=scan.nextInt();
	    	}
	        x=primes.size();
	        /*System.out.println();
	        for(int z:primes){
	        	System.out.print(z+" ");
	        }*/
	        //System.out.println();
	        while(res<=m && x>0){
	        	flag=true;
	        	temp=res;
	        	y=primes.get(x-1);
	        	for(j=0;j<n;j++){
	        		if(a[j]%y==0){
	        			flag=false;
	        			break;
	        		}
	        	}
	        	if(flag)
	        		res*=y;
	        	x--;
	        }
	       	System.out.println(temp);
	    }
		// your code goes here
	}
}
