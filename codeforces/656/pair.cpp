#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

int main(){
	lli t,x,y,z,a,c,b;
	cin>>t;
	lli arr[3];
	while(t--){
		cin>>arr[0]>>arr[1]>>arr[2];
		sort(arr,arr+3);
		x=arr[0];
		y=arr[1];
		z=arr[2];
		if(y!=z){
			cout<<"NO"<<endl;
			continue;
		}else{
			c=y;
			if(x==y){
				a=c;
				b=c;
			}else{
				if(x>y){
					cout<<"NO"<<endl;
					continue;
				}else{
					a=x;
					b=x;
				}
			}
		}
		cout<<"YES"<<endl;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
}