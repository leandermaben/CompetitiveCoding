#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)

using namespace std;
const lli INF=10000000000;
lli n,m;

unordered_map<lli,lli> cost[100001];

void djikstra(vector<lli>& dist,vector<lli>& tree){
	tree[1]=-1;
	lli cur=-1,z;
	priority_queue<pair<lli,lli>> pq;
	pair<lli,lli> temp;
	temp.first=0;
	temp.second=1;
	pq.push(temp);
	Fi(i,2,n+1){
		temp.second=i;
		temp.first=-INF;
		pq.push(temp);
	}
	Fi(i,1,n+1){
		temp=pq.top();
		pq.pop();
		tree[temp.second]=cur;
		dist[temp.second]=-temp.first;
		cur=temp.second;
		queue<pair<lli,lli>> q;
		z=pq.size();
		Fi(i,0,z){
			temp=pq.top();
			temp.first=-temp.first;
			pq.pop();
			if(cost[cur][temp.second]&&temp.first>dist[cur]+cost[cur][temp.second]){
				temp.first=dist[cur]+cost[cur][temp.second];
				tree[temp.second]=cur;
			}
			temp.first=-temp.first;
			q.push(temp);
		}
		Fi(i,0,z){
			temp=q.front();
			q.pop();
			pq.push(temp);
		}
	}
}

int main(){
	lli a,b,c;
	pair<lli,lli> temp;
	cin>>n>>m;
	Fi(i,0,m){
		cin>>a>>b>>c;
		temp.first=b;
		temp.second=c;
		if(cost[a][b]){
			if(cost[a][b]>c)
				cost[a][b]=c;
		}else{
			cost[a][b]=c;
		}
	}
	vector<lli> dist(n+1,INF),tree(n+1,-1);
	djikstra(dist,tree);
	Fi(i,1,n+1)
		cout<<dist[i]<<" ";
}

