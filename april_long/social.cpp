#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int i,count,n,sp;
	cin>>t;
	while(t--){
		cin>>n;
		count=0;
		sp=0;
		i=0;
		flag=1;
		while(!sp){
			cin>>sp;
			i++;
		}
		while(i<n){
			
				sp=0;
				count=0;
				while(!sp){
					cin>>sp;
					i++;
					if(!sp){
						count++;
					}
					if(i>=n&&sp==0){
						count=10;
						break;
					}
				}
				if(count<5){
					cout<<"NO"<<endl;
					flag=0;
				}
			
			if(!flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		
	}
}