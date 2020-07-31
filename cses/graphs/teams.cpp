#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

vector<int> visited(10001,-1);

int bipart(vector<vector<lli>>& adjList,lli source,int color){
	int flag=1;
	visited[source]=color;
	for(lli x:adjList[source]){
		if(visited[x]==-1){
			flag&=bipart(adjList,x,1-color);
		}else if(visited[x]==color){
			return 0;
		}
	}
	return flag;
}

int main(){
	lli n,m,i,j,a,b;
	cin>>n>>m;
	int flag=1;
	vector<lli> temp;
	vector<vector<lli>> adjList(n+1,temp);
	for(i=0;i<m;i++){
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		if(visited[i]==-1){
			flag&=bipart(adjList,i,1);
		}
	}
	if(!flag)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		for(i=1;i<=n;i++)
			cout<<(visited[i]+1)<<" ";
		cout<<endl;
	}
	
	
}