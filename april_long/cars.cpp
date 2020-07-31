#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t;
	long long int cost[100000],profit,n,k;
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		profit=0;
		for(int i=0;i<n;i++)
			cin>>cost[i];
		sort(cost,cost+n);
		for(int i=n-1;i>=0;i--){
			if(cost[i]-k>0){
				profit+=(cost[i]-k);
				profit=profit%1000000007;
				k++;
			}else{
				break;
			}
		}
		cout<<profit<<endl;
	}
}