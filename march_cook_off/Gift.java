import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Gift
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   Scanner scan=new Scanner(System.in);
	    long x,y;
	    int i,j,t,flag=-1,n;
	    String inst;
	    char c;
	    t=scan.nextInt();
	    for(i=0;i<t;i++){
	    	x=0;
	    	y=0;
	    	flag=-1;
	    	n=scan.nextInt();
	    	inst=scan.next();
	    	for(j=0;j<inst.length();j++){
	    		c=inst.charAt(j);
	    		if(c=='L'){
	    			if(flag==0){
	    				continue;
	    			}else{
	    				x-=1;
	    				flag=0;
	    			}
	    			
	    		}else if(c=='R'){
	    			if(flag==0){
	    				continue;
	    			}else{
	    				x+=1;
	    				flag=0;
	    			}
	    		}else if(c=='U'){
	    			if(flag==1){
	    				continue;
	    			}else{
	    				y+=1;
	    				flag=1;
	    			}
	    		}else if(c=='D'){
	    			if(flag==1){
	    				continue;
	    			}else{
	    				y-=1;
	    				flag=1;
	    			}
	    		}
	    	}
	        System.out.println(x+" "+y);
	    }
		// your code goes here
	}
}