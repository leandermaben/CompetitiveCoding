#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

vector<vector<lli>> adjacency(int n,vector<vector<int>> cities){
	vector<lli> temp;
	vector<vector<lli>> adjList(n+1,temp);
	for(vector<int> x:cities){
		adjList[x[0]].push_back(x[1]);
		adjList[x[1]].push_back(x[0]);
	}

	return adjList;
}
int dfs(vector<bool>& visited,vector<vector<lli>> adjList,lli source,lli count){
	visited[source]=true;
	count++;
	for(int x:adjList[source]){
		if(!visited[x]){
			count=dfs(visited,adjList,x,count);
		}
	}
	return count;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
	vector<bool> visited(n+1,false);
	long cost=0;
	lli left=n;
	lli count=0;
	vector<vector<lli>> adjList=adjacency(n,cities);
	if(c_lib<c_road)
		return n*c_lib;
	for(lli i=1;i<n+1;i++){
		if(!visited[i]){
			count=dfs(visited,adjList,i,0);
			left-=count;
			cost+=c_lib;
			cost+=((count-1)*c_road);
		}
		if(left==0)
			break;
	}
	return cost;
}


int main(){
	vector<vector<int>> cities{{1,2},{2,3},{3,1},{1,7},{5,6},{6,4}};
	cout<<roadsAndLibraries(7,3,2,cities)<<endl;
}