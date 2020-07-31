#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

int main(){
	lli n,x,temp,t;
	cin>>t;
	Fi(k,1,t+1){
		cout<<"Case #"<<k<<":"<<endl;
		cin>>n;
		bool table[n][n],flag;
		string in,out,res;
		cin>>in>>out;
		Fi(i,0,in.length()){
			table[i][i]=true;
			Fi(j,i+1,in.length()){
				if(table[i][j-1]&&out[j-1]=='Y'&&in[j]=='Y')
					table[i][j]=true;
				else
					table[i][j]=false;
			}
			for(lli j=i-1;j>=0;j--){
				if(table[i][j+1]&&out[j+1]=='Y'&&in[j]=='Y')
					table[i][j]=true;
				else
					table[i][j]=false;
			}
		}
		Fi(i,0,in.length()){
			res="";
			Fi(j,0,in.length()){
				res+=(table[i][j]?'Y':'N');
			}
			cout<<res<<endl;
		}
	}
}