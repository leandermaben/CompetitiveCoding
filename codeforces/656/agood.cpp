#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

int main(){
	lli t,x,y,z,a,c,b,temp,n,tr,end,st;
	cin>>t;
	pair<lli,lli> p;
	while(t--){
		cin>>n;
		pair<lli,lli> arr[n];
		lli arr2[n];
		Fi(i,0,n){
			cin>>temp;
			p.first=temp;
			p.second=i;
			arr[i]=p;
			arr2[i]=temp;
		}
		sort(arr,arr+n);
		tr=0;
		end=n-1;
		st=0;
		lli i=0;
		lli cur;
		while(tr<end){
			if(arr[i].second<st){
				i++;
				continue;
			}
			cur=arr[i].first;
			i++;
			if(arr2[tr]==cur){
				tr++;
			}else if(arr2[end]==cur){
				end--;
			}else{
				while(arr2[tr]!=cur){
					tr++;
				}
				st=tr;
				tr++;
			}
		}
		cout<<(st)<<endl;
	}
}