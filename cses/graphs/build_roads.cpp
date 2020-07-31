#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

int visited[100001]={0};

void dfs(vector<vector<lli>>& adjList,lli source){
	visited[source]=1;
	for(lli x:adjList[source]){
		if(!visited[x]){
			dfs(adjList,x);
		}
	}
}

int main(){
	lli n,m,i,j,a,b;
	vector<lli> sources;
	cin>>n>>m;
	lli count=0;
	vector<lli> temp;
	vector<vector<lli>> adjList(n+1,temp);
	for(i=0;i<m;i++){
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		if(!visited[i]){
			sources.push_back(i);
			dfs(adjList,i);
			count++;
		}
	}
	cout<<(count-1)<<endl;
	for(i=0;i<count-1;i++){
		cout<<sources[i]<<" "<<sources[i+1]<<endl;
	}
}