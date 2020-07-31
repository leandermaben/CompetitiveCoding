#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)

using namespace std;
const lli INF=INT64_MAX;
lli n,m;

lli cost[501][501];

lli min(lli a,lli b){
	return a<b?a:b;
}

void floyd_warshall(){
	lli i,j,k;
	Fi(k,1,n+1){
		Fi(i,1,n+1){
			Fi(j,1,n+1){
				if(cost[i][k]!=INF&&cost[k][j]!=INF)
					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
}

int main(){
	lli a,b,c,q;
	cin>>n>>m>>q;
	Fi(i,1,n+1){
		Fi(j,1,n+1){
			if(i==j)
				cost[i][j]=0;
			else
				cost[i][j]=INF;
		}
	}
	Fi(i,0,m){
		cin>>a>>b>>c;
		if(cost[a][b]!=INF){
			if(cost[a][b]>c){
				cost[a][b]=c;
				cost[b][a]=c;
			}
		}else{
			cost[a][b]=c;
			cost[b][a]=c;
		}
	}
	floyd_warshall();
	Fi(i,0,q){
		cin>>a>>b;
		if(cost[a][b]==INF)
			cout<<"-1"<<endl;
		else
			cout<<cost[a][b]<<endl;
	}
}

