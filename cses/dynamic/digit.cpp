#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include<string>

#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli MOD=1000000007;
const lli INF=INT64_MAX;

vector<lli> c;

int main(){
	lli n,x,temp;
	cin>>n;
	lli table[1000001];
	table[0]=0;
	Fi(i,1,10){
		table[i]=1;
	}
	Fi(i,10,n+1){
		string s=to_string(i);
		x=INF;
		for(char c:s){
			int d=c-48;
			if(d!=0)
				x=min(x,1+table[i-d]);
		}
		table[i]=x;
	}
	cout<<table[n]<<endl;
}