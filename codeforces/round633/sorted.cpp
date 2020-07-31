#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;
int main(){
	lli t,n,i,f,l;
	cin>>t;
	while(t--){
		cin>>n;
		lli a[n],res[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		f=0;
		l=n-1;
		i=-1;
		while(f<l){
			res[++i]=a[l--];
			res[++i]=a[f++];
		}
		if(n%2)
			res[++i]=a[f];
		for(i=n-1;i>=0;i--)
			cout<<res[i]<<" ";
		cout<<endl;
	}
}