#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;


typedef long long int lli;
typedef pair<lli,lli> pr;

const lli INF=INT64_MAX;
const lli MOD=1000000007;

void dfs(lli source,vector<vector<pr>>& paths,vector<int>& visited,vector<lli>& top){
	visited[source]=1;
	for(auto x:paths[source]){
		if(!visited[x.first]&&x.second){
			dfs(x.first,paths,visited,top);
		}
	}
	top.push_back(source);
	
}

unordered_map<lli,lli> topological(vector<vector<pr>>& paths){
	lli n=paths.size()-1;
	vector<int> visited(n+1,0);
	vector<lli> top;
	unordered_map<lli,lli> mp;
	Fi(i,1,n+1){
		if(!visited[i]){
			dfs(i,paths,visited,top);
		}
	}
	Fi(i,0,n){
		mp[top[i]]=n-1-i;
	}
	return mp;
}

int main(){
	lli n,m,t,s,x,y;
	bool flag;
	cin>>t;
	while(t--){
		flag=true;
		cin>>n>>m;
		vector<pr> res;
		vector<vector<pr>> paths(n+1);
		while(m--){
			cin>>s>>x>>y;
			paths[x].push_back(pr(y,s));
		}
		unordered_map<lli,lli> mp=topological(paths);
	
		Fi(i,1,n+1){
			for(auto a:paths[i]){
				if(a.second&&mp[i]>mp[a.first]){
					flag=false;
					break;
				}else if(!a.second){
					if(mp[i]>mp[a.first]){
						res.push_back(pr(a.first,i));
					}else{
						res.push_back(pr(i,a.first));
					}
				}else{
					res.push_back(pr(i,a.first));
				}
			}
			if(!flag)
				break;
		}
		if(flag){
			cout<<"YES"<<endl;
			for(auto a:res)
				cout<<a.first<<" "<<a.second<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
}

