#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

int visited[100001]={0};
lli start;
queue<lli> s;
bool detect_cycle(vector<vector<lli>>& adjList,lli source,lli count){
	visited[source]=count;
	for(lli x:adjList[source]){
		if(visited[x]==0){
			if(detect_cycle(adjList,x,count+1)){
				s.push(source);
				return true;
			}
		}else if(abs(count-visited[x])>=2){
			s.push(x);
			s.push(source);
			return true;
		}
	}
	return false;
}

int main(){
	lli n,m,i,j,a,b,st;
	stack<lli> res;
	cin>>n>>m;
	lli count=0;
	bool flag=false;
	vector<lli> temp;
	vector<vector<lli>> adjList(n+1,temp);
	for(i=0;i<m;i++){
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		if(visited[i]==0){
			flag=flag||detect_cycle(adjList,i,1);
		}
		if(flag)
			break;
	}
	if(!flag)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		st=s.front();
		s.pop();
		res.push(st);
		while(s.front()!=st){
			res.push(s.front());
			s.pop();
		}	
		res.push(st);
		cout<<res.size()<<endl;
		while(!res.empty()){
			cout<<res.top()<<" ";
			res.pop();
		}
	}
	
}