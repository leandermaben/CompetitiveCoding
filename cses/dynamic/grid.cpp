#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include<string>

#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli MOD=1000000007;
const lli INF=INT64_MAX;

int main(){
	lli n,x,temp;
	cin>>n;
	char cart[1000][1000];
	int table[1000][1000];
	Fi(i,0,n){
		Fi(j,0,n){
			cin>>cart[i][j];
		}
	}
	Fi(i,0,n){
		Fi(j,0,n){
			if(cart[i][j]=='*'){
				table[i][j]=0;
			}
			else if(i==0&&j==0){
				table[i][j]=1;
			}else if(i==0){
				table[i][j]=table[i][j-1];
			}else if(j==0){
				table[i][j]=table[i-1][j];
			}
			else{
				table[i][j]=(table[i-1][j]+table[i][j-1])%MOD;
			}
		}
	}
	cout<<table[n-1][n-1]<<endl;
}