#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;
int main(){
	lli t,n,i,f,l,max,count;
	cin>>t;
	while(t--){
		cin>>n;
		count=0;
		lli a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		max=a[0]-a[1];
		if(a[0]-a[1]>0){
			a[1]=a[0];
		}
		for(i=2;i<n;i++){
			max=(max>a[i-1]-a[i])?max:a[i-1]-a[i];
			if(a[i-1]-a[i]>0)
				a[i]=a[i-1];
		}
		if(max<0){
			cout<<"0"<<endl;
			continue;
		}
		while(max){
			count++;
			max>>=1;
		}
		cout<<count<<endl;
	}
}

/*

5 4 3 2 1


*/