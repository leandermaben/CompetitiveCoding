#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

int main(){
	lli t,n,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		x=(1<<n)+((1<<(n/2))-2);
		y=((1<<(n+1))-2)-x;
		cout<<(x-y)<<endl;
	}
}