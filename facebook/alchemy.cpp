#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

int main(){
	lli n,x,temp,t,a,b;
	cin>>t;
	Fi(k,1,t+1){
		cin>>n;
		char c;
		a=0;
		b=0;
		Fi(i,0,n){
			cin>>c;
			if(c=='A')
				a++;
			else
				b++;
		}
		cout<<"Case #"<<k<<":"<<endl;
		if(abs(a-b)!=1)
			cout<<'N'<<endl;
		else
			cout<<'Y'<<endl;
	}
}