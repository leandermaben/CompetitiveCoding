#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int done,x,y,t,first,flag,n,dig,depth,temp,it;
	long long int eq,uneq,offset,c,j,i,k,start;
	char sig;
	cin>>t>>n;
	for(k=1;k<=t;k++){
		uneq=-1;
		eq=-1;
		first=1;
		it=5;
		int b[200];
		char res[200];
		offset=0;
		while(1){
			if(!first)
				it=4;
			first=0;
			for(i=1;i<=it&&(i+offset<=n/2);i++){
				cout<<(i+offset)<<endl<<flush;
				cin>>x;
				if(x=='N')
					exit(0);
				b[offset+i]=x;
				cout<<(n-i+1-offset)<<endl<<flush;
				cin>>y;
				if(x=='N')
					exit(0);
				b[n-i+1-offset]=y;
				if(x==y&&eq==-1)
					eq=(i+offset);
				else if(x!=y&&uneq==-1)
					uneq=(i+offset);
			}
			offset+=it;
			if(offset>=n/2){
				for(i=1;i<=n;i++){
					res[i-1]=b[i]+'0';
				}
				res[i-1]='\0';
				cout<<res<<endl<<flush;
				cin>>sig;
				if(sig=='N')
					exit(0);
				else
					break;
			}
			//cout<<"checking at "<<offset<<endl;
			if(eq!=-1){
				cout<<eq<<endl<<flush;
				cin>>x;
				if(x=='N')
					exit(0);
				if(x==b[eq]){
					//cout<<"eq same"<<endl;
					if(uneq==-1){
						cout<<"1"<<endl<<flush;
						cin>>x;
						if(x=='N')
					exit(0);
						flag=4;
					}
					else{
						//cout<<"equ same and uneq present"<<endl;
						cout<<uneq<<endl<<flush;
						cin>>x;
						if(x==b[uneq])
							flag=4;
						else
							flag=2;
					}
				}else{
					if(uneq==-1){
						cout<<"1"<<endl<<flush;
						cin>>x;
						if(x=='N')
							exit(0);
						flag=1;
					}
					else{
						cout<<uneq<<endl<<flush;
						cin>>x;
						if(x=='N')
							exit(0);
						if(x==b[uneq])
							flag=3;
						else
							flag=1;
					}
				}

			}else{
				cout<<uneq<<endl<<flush;
				cin>>x;
				if(x=='N')
					exit(0);
				if(x==b[uneq]){
					cout<<"1"<<endl<<flush;
					cin>>x;
					flag=4;
				}else{
					cout<<"1"<<endl<<flush;
					cin>>x;
					flag=1;
				}
			}
			//cout<<"flag is: "<<flag<<endl;
			if(flag==1){
				for(i=1;i<=offset;i++){
					b[i]=1-b[i];
					b[n-i+1]=1-b[n-i+1];
				}
			}else if(flag==2){
				for(i=1;i<=offset;i++){
					temp=b[i];
					b[i]=b[n-i+1];
					b[n-i+1]=temp;
				}
			}else if(flag==3){
				for(i=1;i<=offset;i++){
					b[i]=1-b[i];
					b[n-i+1]=1-b[n-i+1];
					temp=b[i];
					b[i]=b[n-i+1];
					b[n-i+1]=temp;
				}
				
			}
		}
		
	}
	return 0;

}	
