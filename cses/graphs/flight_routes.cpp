#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;
typedef vector<vector<pair<lli,lli>>> list2d;
typedef vector<pair<lli,lli>> list;

list2d paths(100001);

vector<lli> res;

lli k,n,m;

const lli INF=INT64_MAX;

lli cnt[100001]={0};

void dijkstra_gen(){
	pair<lli,lli> cur;
	priority_queue<pair<lli,lli>> pq;
	pq.push(pair<lli,lli>(0,1));
	while(!pq.empty()&&cnt[n]!=k){
		cur=pq.top();
		pq.pop();
		cnt[cur.second]++;
		if(cur.second==n)
			res.push_back(-cur.first);
		if(cnt[cur.second]<=k){
			for(auto x:paths[cur.second]){
				pq.push(pair<lli,lli>(cur.first-x.second,x.first));
			}
		}
	}
}

int main(){
	bool pres=false;
	lli i,a,b,c,cur;
	cin>>n>>m>>k;
	Fi(i,0,m){
		cin>>a>>b>>c;
		paths[a].push_back(pair<lli,lli>(b,c));
	}
	dijkstra_gen();
	Fi(i,0,k){
		cout<<res[i]<<" ";	
	}		
}