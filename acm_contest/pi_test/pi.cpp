#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;


typedef long long int lli;
typedef pair<lli,lli> pr;

const lli INF=INT64_MAX;
const lli MOD=1000000007;

lli minSpace(set<string>& st,string& s,lli pos,vector<lli>& table){
	if(pos==s.length())
		return -1;
	if(table[pos]==-2){
		lli mn=INF;
		for(auto x:st){
			if(s.substr(pos,x.length())==x){
				if(minSpace(st,s,pos+x.length(),table)!=INF){
					mn=min(mn,minSpace(st,s,pos+x.length(),table))+1;
				}
			}
		}
		table[pos]=mn;
	}
	return table[pos];
}

int main(){
	lli t,n,m;
	cin>>t;
	while(t--){
		string s,temp;
		cin>>s;
		cin>>m;
		set<string> st;
		n=s.length();
		vector<lli> table(n,-2);
		Fi(i,0,m){
			cin>>temp;
			st.insert(temp);
		}
		lli res=minSpace(st,s,0,table);
		if(res!=INF)
			cout<<res<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;

	}
}