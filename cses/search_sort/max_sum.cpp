#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

int main(){
	lli n,i,mx,c,temp;
	cin>>n;
	mx=-INF;
	c=0;
	Fi(i,0,n){
		cin>>temp;
		if(c+temp<=0){
			mx=max(c+temp,mx);
			c=0;
		}
		else{
			c+=temp;
			mx=max(c,mx);
		}
	}
	cout<<mx;
}