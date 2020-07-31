#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)

using namespace std;
const lli INF=INT64_MAX;
lli n,m;

unordered_map<lli,lli> cost[100001];

void djikstra(vector<lli>& dist,vector<lli>& tree){
	tree[1]=-1;
	lli cur=-1,z;
	set<pair<lli,lli>> pq;
	pair<lli,lli> temp,temp2;
	set<pair<lli,lli>>::iterator temp3;
	temp.first=0;
	temp.second=1;
	pq.insert(temp);
	Fi(i,2,n+1){
		temp.second=i;
		temp.first=INF;
		pq.insert(temp);
	}
	Fi(i,1,n+1){
		temp=*(pq.begin());
		pq.erase(pq.begin());
		tree[temp.second]=cur;
		dist[temp.second]=temp.first;
		cur=temp.second;

		for(auto x:cost[cur]){

			if(dist[x.first]>dist[cur]+x.second){
				temp2.first=dist[x.first];
				temp2.second=x.first;
				temp3=pq.lower_bound(temp2);
				temp2=*temp3;
				pq.erase(temp3);
				temp2.first=dist[cur]+x.second;
				dist[temp2.second]=dist[cur]+x.second;
				pq.insert(temp2);

			}

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

