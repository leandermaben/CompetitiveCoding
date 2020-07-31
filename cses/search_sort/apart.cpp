#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

int main(){
	lli temp,n,m,k,i,j,x,count;
	cin>>n>>m>>k;
	lli req[n];
	lli s[m];
	pair<lli,lli> p;
	Fi(i,0,n){
		cin>>x;
		req[i]=x;
	}

	sort(req,req+n);
	
	Fi(i,0,m){
		cin>>temp;
		s[i]=temp;
	}
	
	sort(s,s+m);
	i=0;
	j=0;
	count=0;
	while(i<n&&j<m){
		if(req[i]-k<=s[j] && req[i]+k>=s[j]){
			count++;
			i++;
			j++;
		}
		else if(req[i]+k<s[j]){
			i++;
		}
		else{
			j++;
		}
	}

	cout<<count<<endl;
}