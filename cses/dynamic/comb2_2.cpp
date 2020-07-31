#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
#define Fd(i,s,e) for(lli i=s;i>e;i--)
using namespace std;

typedef long long int lli;

const int MOD=1000000007;
const lli INF=INT64_MAX;

vector<lli> c;

int main(){
	std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,x,temp;
	cin>>n>>x;
	vector<vector<int>> table(n+1,vector<int>(x+1,-1));
	Fi(i,0,n){
		cin>>temp;
		c.push_back(temp);
	}
	Fi(i,0,x+1)
		table[n][i]=0;
	Fi(i,0,n+1)
		table[i][0]=1;
	Fd(i,n-1,-1){
		Fi(j,1,x+1){
			int opt1=(j>=c[i])?table[i][j-c[i]]:0;
			int opt2=table[i+1][j];
			table[i][j]=(opt1+opt2)%MOD;
		}
	}
	cout<<table[0][x]<<endl;
}