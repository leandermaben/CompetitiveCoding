#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

int main(){
	lli t,n,x,y,k,i,tmp;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>k;
		lli un[k];
		set<lli>s;
		for(i=0;i<n;i++){
			cin>>tmp;
			s.insert(tmp);
		}
		if(s.size()>k){
			cout<<"-1"<<endl;
			continue;
		}
		x=0;
		for(auto it:s)
			un[x++]=it;
		while(x<k)
			un[x++]=1;
		cout<<n*k<<endl;
		while(n--){
			for(i=0;i<k;i++)
				cout<<un[i]<<" ";
		}
		cout<<endl;
	}
}