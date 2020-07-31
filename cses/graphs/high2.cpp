#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

lli n;

vector<vector<pair<lli,lli>>> paths(2501);

lli scores[2501][2501];

int visited[2501]={0};




bool dfs_detect_positive_cycle(lli source,lli score,unordered_set<lli> s){
	visited[source]=1;
	s.insert(source);
	lli max=0;
	for(auto x:paths[source]){
		if(s.count(x.first)&&score+x.second>0&&scores[x.first][n]!=-INF){
			return true;
		}else if(!visited[x.first]){
			if(dfs_detect_positive_cycle(x.first,score+x.second,s))
				return true;
		}
	}
	return false;
}


void floyd_warshall(){
	Fi(k,1,n+1){
		Fi(i,1,n+1){
			Fi(j,1,n+1){
				if(scores[i][k]!=-INF&&scores[k][j]!=-INF)
					scores[i][j]=max(scores[i][j],scores[i][k]+scores[k][j]);
			}
		}
	}
}

int main(){
	lli m,i,a,b,c,res;
	pair<lli,lli> temp;
	unordered_set<lli> s;
	cin>>n>>m;
	Fi(i,0,n+1){
		Fi(j,0,n+1){
			scores[i][j]=-INF;
		}
	}
	Fi(i,0,m){
		cin>>a>>b>>c;
		temp.first=b;
		temp.second=c;
		paths[a].push_back(temp);
		scores[a][b]=c;
	}
	floyd_warshall();
	if(dfs_detect_positive_cycle(1,0,s)){
		cout<<"-1"<<endl;
	}else{
		cout<<scores[1][n]<<endl;
	}
}