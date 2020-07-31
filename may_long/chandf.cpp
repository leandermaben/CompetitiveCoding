#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	lli t,x,y,l,r,z,count;
	cin>>t;
	while(t--){
		cin>>x>>y>>l>>r;
		z=x|y;
		vector<lli> pos;
		lli temp=z;
		count=0;
		while(temp){
			if(!(temp|0)){
				pos.push_back(count);
			}
			temp>>=1;
			count++;
		}
		while(z<l){
			
		}
		
		
	}
}