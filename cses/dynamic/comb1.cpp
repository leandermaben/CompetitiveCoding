#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli MOD=1000000007;
const lli INF=INT64_MAX;

vector<lli> c;

lli perm(vector<lli>& table,lli sum){
	if(table[sum]==-1){
		lli res=0;
		if(sum==0){
			table[sum]=1;
		}else{
			for(auto x:c){
				if(x<=sum){
					res+=perm(table,sum-x);
					res%=MOD;
				}
			}
			table[sum]=res;
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
	cout<<perm(table,x)<<endl;
}