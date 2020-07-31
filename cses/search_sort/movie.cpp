#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;
typedef long long int lli;
const lli INF=INT64_MAX;

int main(){
	lli i,j,n,temp1,temp2;
	cin>>n;
	pair<lli,lli> ent[n],ext[n];
	unordered_set<lli> s;
	Fi(i,0,n){
		cin>>temp1>>temp2;
		ent[i]=pair<lli,lli>(temp1,i);
		ext[i]=pair<lli,lli>(temp2,i);

	}
	sort(ent,ent+n);
	sort(ext,ext+n);
	lli mx=0,cur=0;
	i=0;
	j=0;
	while(i<n&&j<n){
		if(ent[i].first<ext[j].first){
			s.insert(ent[i].second);
			i++;
		}
		else{
			if(s.count(ext[j].second)){
				s.clear();
				mx++;
			}
			j++;
		}
	}
	while(j<n){
		if(s.count(ext[j].second)){
				s.clear();
				mx++;
			}
			j++;
	}
	cout<<mx;
}
