#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

lli solve(lli pos,lli num){
	
}


int main(){
	int n,x,h[1001],s[1001],table[1001][100001];
	cin>>n>>x;
	Fi(i,1,n+1){
		cin>>h[i];
	}
	Fi(i,1,n+1){
		cin>>s[i];
	}
	Fi(i,0,n+1){
		Fi(j,0,x+1){
			if(i==0||j==0)
				table[i][j]=0;
			else{
				if(h[i]<=j)
					table[i][j]=max(table[i-1][j],s[i]+table[i-1][j-h[i]]);
				else
					table[i][j]=table[i-1][j];
			}
		}
	}
	cout<<table[n][x]<<endl;
}