#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

vector<lli> c;

lli coins(vector<lli>& table,int sum){
	lli mn=INF;
	if(table[sum]==-1){
		if(sum==0)
			return 0;
		else{
			for(auto x:c){
				if(sum>=x&&coins(table,sum-x)!=INF)
					mn=min(mn,1+coins(table,sum-x));
			}
			table[sum]=mn;
		}
	}
	return table[sum];
}

int main(){
	lli n,x,temp;
	cin>>n>>x;
	vector<lli> table(x+1,-1);
	Fi(i,0,n){
		cin>>temp;
		c.push_back(temp);
	}
	if(coins(table,x)==INF)
		cout<<"-1"<<endl;
	else
		cout<<coins(table,x)<<endl;
}