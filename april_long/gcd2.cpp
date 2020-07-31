#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int num,x,k,i,j,count,n,sp,diff;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		num=n/2;
		if(n==1){
			cout<<"1"<<endl;
			cout<<"1 1"<<endl;
		}else{
			cout<<num<<endl;
			if(n%2==0){
			for(i=1;i<n;i+=2){
				cout<<"2 "<<i<<" "<<(i+1)<<endl;
			}
		}else{
			cout<<"3 1 2 3"<<endl;
			for(i=4;i<n;i+=2){
				cout<<"2 "<<i<<" "<<(i+1)<<endl;
			}
		}	
		}
		
	}	
}