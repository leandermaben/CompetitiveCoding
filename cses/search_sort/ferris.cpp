#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

int main(){
	lli temp,n,m,k,i,j,x,count;
	cin>>n>>x;
	lli w[n];

	Fi(i,0,n){
		cin>>temp;
		w[i]=temp;
	}
	
	sort(w,w+n);

	i=0;
	j=n-1;
	count=0;
	while(i<j){
		count++;
		if(w[i]+w[j]<=x){
			i++;
			j--;
		}else{
			j--;
		}
	}
	if(i==j)
		count++;
	cout<<count<<endl;
}