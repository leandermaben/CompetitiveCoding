#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const int MOD=1000000007;
const lli INF=INT64_MAX;

vector<lli> c;
vector<vector<int>> table(101,vector<int>(1000001,-1));
int comb(int sum,int i){
	int res=0;
	if(table[i][sum]==-1){
		if(sum==0)
			table[i][sum]=1;
		else if(i==c.size())
			table[i][sum]=0;
		else{
			if(c[i]<=sum)
				res+=comb(sum-c[i],i);
			res%=MOD;
			res+=comb(sum,i+1);
			res%=MOD;
			table[i][sum]=res;
		}
	}
	return table[i][sum];
}


int main(){
	std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,x,temp;
	cin>>n>>x;
	Fi(i,0,n){
		cin>>temp;
		c.push_back(temp);
	}
	cout<<comb(x,0)<<endl;
}