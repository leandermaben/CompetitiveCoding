#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)

using namespace std;
const lli INF=INT64_MAX;
lli n,m;

vector<vector<lli>> paths(100001);

stack<lli> st;
bool visited[100001];

void topological(lli source){
	visited[source]=true;
	for( auto x:paths[source]){
		if(!visited[x])
			topological(x);
	}
	st.push(source);
}

int main(){
	lli a,b,temp;
	bool flag=true;
	vector<lli> res;
	unordered_map<lli,lli> mp;
	cin>>n>>m;
	Fi(i,0,m){
		cin>>a>>b;
		paths[a].push_back(b);
	}
	Fi(i,1,n+1){
		if(!visited[i])
			topological(i);
	}
	while(!st.empty()){
		temp=st.top();
		st.pop();
		res.push_back(temp);
		mp[temp]=res.size();
	}
	Fi(i,1,n+1){
		for(auto x:paths[i]){
			if(mp[i]>mp[x])
				flag=false;
		}
	}
	if(flag){
		Fi(i,0,n)
			cout<<res[i]<<" ";
	}else
	cout<<"IMPOSSIBLE"<<endl;
	
}

