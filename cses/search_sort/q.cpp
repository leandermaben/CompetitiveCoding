#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;
typedef long long int lli;
const lli INF=INT64_MAX;

int main(){
	lli i,j,n;
	cin>>n;
	lli ent[n],ext[n];
	Fi(i,0,n){
		cin>>ent[i]>>ext[i];
	}
	sort(ent,ent+n);
	sort(ext,ext+n);
	lli mx=0,cur=0;
	i=0;
	j=0;
	while(i<n&&j<n){
		if(ent[i]<ext[j]){
			cur++;
			i++;
		}
		else if(ent[i]>ext[j]){
			cur--;
			j++;
		}else{
			i++;
			j++;
		}
		mx=max(mx,cur);
	}
	cout<<mx;
}
