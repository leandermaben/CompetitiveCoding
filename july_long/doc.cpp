#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;
typedef long long int lli;
const lli INF=INT64_MAX;

int main(){
	lli t,n,x,i;
	cin>>t;
	while(t--){
		cin>>n>>x;
		lli a[n];
		Fi(i,0,n){
			cin>>a[i];
			a[i]=ceil(a[i]/x);
		}
		sort(a,a+n);
		i=0;
		lli d=1;
		while(i<n){
			if(d>=ceil(log2(a[i]))+1){
				d++;
			}else{
				d=ceil(log2(a[i]))+2;
			}
			i++;
		}
		cout<<(d-1)<<endl;
	}
}