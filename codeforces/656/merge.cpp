#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

int main(){
	lli t,x,y,z,a,c,b,temp,n;
	cin>>t;
	while(t--){
		cin>>n;
		unordered_set<lli> s;
		Fi(i,0,2*n){
			cin>>temp;
			if(!s.count(temp)){
				cout<<temp<<" ";
				s.insert(temp);
			}
		}
		cout<<endl;
	}
}