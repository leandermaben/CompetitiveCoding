#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli power(lli a,lli b){
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
		return a*a*power(a,b-2);
}

int main(){
	int t;
	lli p,q,i,j,x,y,xt,yt,k,count,ind;
	char d;
	bool flag,xp,yp;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>x>>y;
		string res;
		count=0;
		ind=true;
		flag=true;
		xp=true;
		yp=true;
		xt=0;
		yt=0;
		if(x<0){
			xp=false;
			x=x*-1;
		}
		if(y<0){
			yp=false;
			y=y*-1;
		}
		if(x%2==y%2){
			cout<<"Case #"<<k<<": "<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if(x%2==1){
			if((y&x)==0){

				while(x||y){
					if(x&1){
						if(xp)
							res+='E';
						else
							res+='W';	
					}else{
						if(y<pow(2,count)){
							flag=false;
							break;
						}else{
							y-=pow(2,count);
							if(yp)
								res+='N';
							else
								res+='S';
						}
					}
					x>>=1;
				count++;
				}
			}else{
				while(y){
					if(y&1){
						if(yp)
							res+='N';
						else
							res+='S';	
					}else{
						if(count!=0&&(x&1)==1){
							flag=false;
							break;
						}
						if(xp)
							res+='W';
						else
							res+='E';
						}
					y>>=1;
					x>>=1;
					count++;
					}
					if(x&1){
						flag=false;
					}
					if(xp)
						res+='E';
					else
						res+='W';
					x>>1;
					while(x){
						if(x&1){
						if(xp)
							res+='E';
						else
							res+='W';

						}else{
							flag=false;
							break;
						}
					}
				}
			}else{
				if((y&x)==0){
				while(x||y){
					if(x&1){
						if(xp)
							res+='E';
						else
							res+='W';	
					}else{
						if(y<pow(2,count)){
							flag=false;
							break;
						}else{
							y-=pow(2,count);
							if(yp)
								res+='N';
							else
								res+='S';
						}
					}
					x>>=1;
				count++;
				}
			}else{
				//cout<<"Here"<<endl;
				while(x){
					if(x&1){
						if(xp)
							res+='E';
						else
							res+='W';	
					}else{
						if(count!=0&&(y&1)==1){
							flag=false;
							break;
						}
						if(yp)
							res+='S';
						else
							res+='N';
						}
					y>>=1;
					x>>=1;
					count++;
					}
					if(y&1){
						flag=false;
					}
					if(yp)
						res+='N';
					else
						res+='S';
					y>>1;
					while(y){
						if(y&1){
						if(yp)
							res+='N';
						else
							res+='S';

						}else{
							flag=false;
							break;
						}
					}
			}
		}
			if(flag)
				cout<<"Case #"<<k<<": "<<res<<endl;
			else
				cout<<"Case #"<<k<<": "<<"IMPOSSIBLE"<<endl;
		}
		
}