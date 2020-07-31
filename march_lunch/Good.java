import java.util.*;
import java.lang.*;
import java.io.*;

class Good
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    int i,j,n,k,x,m,t,count,a,b,a1,a0,b1,b0;
	    String s;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	count=0;
	    	s=scan.next();
	        k=scan.nextInt();
	        x=scan.nextInt();
	        HashMap<Character,Integer> hash=new HashMap();
	        for(j=0;j<s.length();j++){
	        	char c=s.charAt(j);
	        	if(hash.containsKey(c)){
	        		m=hash.get(c);
	        		if(m+1>x)
	        			k--;
	        		else{
	        			hash.put(c,m+1);
	        			count++;
	        		}
	        	}else{
	        		hash.put(c,1);
	        			count++;
	        	}
	        	if(k==-1)
	        		break;
	        }
	       System.out.println(count);
	    }
		// your code goes here
	}
}