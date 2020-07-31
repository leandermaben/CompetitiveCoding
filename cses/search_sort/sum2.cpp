#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;
typedef long long int lli;
const lli INF=INT64_MAX;

int main(){
	lli i,j,x,n;
	cin>>n>>x;
	lli a[n];
	bool flag=false;
	unordered_map<lli,lli> mp;
	Fi(i,0,n){
		cin>>a[i];
		if(mp.count(x-a[i])){
			flag=true;
			cout<<mp[x-a[i]]+1<<" "<<i+1<<endl;
			break;
		}
		mp[a[i]]=i;

	}
	if(!flag)
		cout<<"IMPOSSIBLE"<<endl;
}
