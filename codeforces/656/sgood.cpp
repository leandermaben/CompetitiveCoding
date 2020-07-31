#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

lli sol(lli st,lli end,string& s,char c){
	if(st<end){
		lli mid=(st+end)/2;
		lli left=0,right=0;
		Fi(i,st,mid+1){
			if(s[i]!=c)
				left+=1;
		}
		Fi(i,mid+1,end+1){
			if(s[i]!=c)
				right+=1;
		}
		return min(left+sol(mid+1,end,s,c+1),right+sol(st,mid,s,c+1));
	}else{
		if(s[st]==c)
			return 0;
		else
			return 1;
	}
}

int main(){
	lli cost,mid,t,temp,n,tr,end,st;
	char c;
	cin>>t;
	pair<lli,lli> p;
	while(t--){
		string s;
		cin>>n;
		cin>>s;
		if(n==1){
			if(s[0]=='a')
				cout<<"0"<<endl;
			else
				cout<<"1"<<endl;
			continue;

		}
		cout<<sol(0,n-1,s,'a')<<endl;
	}
}