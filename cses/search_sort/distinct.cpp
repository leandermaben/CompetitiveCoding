#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
	lli temp,n,i;
	cin>>n;
	set<lli> s;
	for(i=0;i<n;i++){
		cin>>temp;
		s.insert(temp);
	}
	cout<<s.size();
}