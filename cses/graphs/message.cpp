#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

int visited[100001]={0};
vector<vector<lli>>adjList;

vector<lli> bfs_path(lli dest){
	lli i,j;
	visited[1]=1;
	vector<lli> vec,cur,temp,err{-1};
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	queue<vector<lli>> q;
	q.push(vec);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(lli x:adjList[cur[0]]){
			if(!visited[x]){
				temp=cur;
				temp[0]=x;
				temp[1]++;
				temp.push_back(x);
				visited[x]=1;
				q.push(temp);
				if(x==dest)
					return temp;
			}
		}
	}
	return err;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	lli n,m,i,j,a,b;
	vector<lli> res;
	cin>>n>>m;
	lli count=0;
	vector<lli> temp;
	vector<vector<lli>> adjList1(n+1,temp);
	adjList=adjList1;
	for(i=0;i<m;i++){
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	res=bfs_path(n);
	if(res[0]==-1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		cout<<res[1]<<endl;
		for(i=2;i<res.size();i++)
			cout<<res[i]<<" ";
	}
}