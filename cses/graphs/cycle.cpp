#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

lli visited[100001]={0};
typedef vector<vector<pair<lli,lli>>> list2d;
typedef vector<pair<lli,lli>> list;

list2d paths(100001);

lli cycle,n,m;
bool flag=true;
stack<lli> st;

bool dfs_find_cycle(lli source,unordered_map<lli,lli> mp,lli score){
	visited[source]=1;
	mp[source]=score;
	cout<<source<<endl;
	for(auto x:paths[source]){
		if(mp.count(x.first)&&score-mp[x.first]+x.second<0){
			cycle=x.first;
			st.push(x.first);
			st.push(source);
			return true;
		}else if(!visited[x.first]){
			if(dfs_find_cycle(x.first,mp,score+x.second)){
				if(flag)
					st.push(source);
				if(source==cycle)
					flag=false;
				return true;
			}		
		}
	}
	return false;
}

int main(){
	bool pres=false;
	lli i,a,b,c;
	unordered_map<lli,lli> mp;
	cin>>n>>m;
	Fi(i,0,m){
		cin>>a>>b>>c;
		paths[a].push_back(pair<lli,lli>(b,c));
	}
	Fi(i,1,n+1){
		if(!visited[i]&&dfs_find_cycle(i,mp,0)){
			cout<<"YES"<<endl;
			while(!st.empty()){
				cout<<st.top()<<" ";
				st.pop();
			}
			pres=true;
			break;
		}
			
	}

	if(!pres)
		cout<<"NO"<<endl;
		
}