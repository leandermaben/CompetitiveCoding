#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

lli distances[100001];
lli tree[100001];
typedef vector<vector<pair<lli,lli>>> list2d;
typedef vector<pair<lli,lli>> list;

list2d paths(100001);

lli cycle,n,m;
bool flag=true;
stack<lli> st;

void bellman_cycle(lli source){
	distances[source]=0;
	Fi(k,0,n){
		cycle=-1;
		Fi(i,1,n+1){
			if(distances[i]==INF)
				continue;
			for(auto x:paths[i]){
				if(distances[i]+x.second<distances[x.first]){
					cycle=x.first;
					distances[x.first]=distances[i]+x.second;
					tree[x.first]=i;
				}
			}
		}
		if(cycle==-1)
			break;
	}
}

int main(){
	bool pres=false;
	lli i,a,b,c,cur;
	cin>>n>>m;
	vector<lli> res;
	Fi(i,0,m){
		cin>>a>>b>>c;
		paths[a].push_back(pair<lli,lli>(b,c));
	}
	Fi(i,0,n+1){
		distances[i]=INF;
		tree[i]=-1;
	}
	Fi(i,1,n+1){
		if(distances[i]==INF){
			bellman_cycle(i);
			if(cycle==-1)
				continue;
			else{
				cout<<"YES"<<endl;
				Fi(i,0,n){
					cycle=tree[cycle];
				}
				cur=cycle;
				while(cur!=cycle || !res.size()){
					res.push_back(cur);
					cur=tree[cur];
				}
				res.push_back(cycle);
				for(lli j=res.size()-1;j>=0;j--)
					cout<<res[j]<<" ";
				pres=true;
				break;
			}
		}
	}
	if(!pres)
		cout<<"NO"<<endl;		
}