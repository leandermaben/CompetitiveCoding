#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;


/*

Solution:

The most efficient way to find the max score path is to use bellman-ford algorithm (which gives min-cost) with inverted weights.
To test for the case of infinitely large score:

if(positive cycle present){
	if(nth cave is reachable through the cycle ){
		
		score will be infinity
	}
}else{
	get score from bellman ford
}



*/


lli n;

vector<vector<pair<lli,lli>>> paths(2501);

lli tree[2501];

unordered_set<lli> interm;

lli distances[2501]={0};

vector<bool> visited;

bool dfs(lli source){
	visited[source]=true;
	if(source==n)
		return true;
	for(auto x:paths[source]){
		if(!visited[x.first]){
			if(dfs(x.first)){
				interm.insert(source);
			}
		}
	}
	if(interm.count(source))
		return true;
	else
		return false;
}
/*
bool dfs_detect_positive_cycle(lli source,lli score,map<lli,lli> m){
	visited[source]=1;
	m[source]=score;
	for(auto x:paths[source]){
		if(m.count(x.first)&&score-m.find(x.first)->second+x.second>0&&interm.count(x.first)){
			return true;
		}else if(!visited[x.first]){
			if(dfs_detect_positive_cycle(x.first,score+x.second,m))
				return true;
		}
	}
	return false;
}
*/
void bellman_ford(){
	lli i,j,k;
	distances[1]=0;
		Fi(k,0,n-1){
			Fi(i,1,n+1){
			if(distances[i]!=INF){
				Fi(j,0,paths[i].size()){
					if(distances[i]-paths[i][j].second<distances[paths[i][j].first]){
						distances[paths[i][j].first]=distances[i]-paths[i][j].second;
						tree[paths[i][j].first]=i;
					}
				}
			}
		}
	}
}

int main(){
	lli m,i,a,b,c,res;
	pair<lli,lli> temp;
	map<lli,lli> s;
	cin>>n>>m;
	bool flag=false;
	Fi(i,0,n+1){
		distances[i]=INF;
		tree[i]=-1;
	}
	Fi(i,0,m){
		cin>>a>>b>>c;
		temp.first=b;
		temp.second=c;
		paths[a].push_back(temp);
	}
	interm.insert(n);
	Fi(i,1,n+1){
		if(!interm.count(i)){
			visited.assign(2501,false);
			if(dfs(i))
				interm.insert(i);
		}
	}
	visited.assign(2501,false);
	bellman_ford();
	Fi(i,1,n+1){
			if(distances[i]!=INF){
				Fi(j,0,paths[i].size()){
					if(distances[i]-paths[i][j].second<distances[paths[i][j].first]){
						distances[paths[i][j].first]=distances[i]-paths[i][j].second;
						if(interm.count(paths[i][j].first)){
							flag=true;
							break;
						}
					}
				}
			}
			if(flag)
				break;
		}
	if(flag||tree[n]==-1){
		cout<<"-1"<<endl;
	}else{	
		cout<<(-distances[n])<<endl;
	}
}