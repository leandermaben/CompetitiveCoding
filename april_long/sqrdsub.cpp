#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
long long int calcnofoursub(long long int arr[],int n){
	long long int dp[n+1];
	long long int temp,last4=-1,last2=-1,pen2=-1;
	dp[0]=0;
	for(int i=0;i<n;i++){
		dp[i+1]=dp[i];
		//cout<<"Res: "<<arr[i]<<endl;
		if(arr[i]%4==0){
			last4=i;
			//cout<<"HERE :"<<arr[i]<<" "<<endl;
		}else if(arr[i]%2==0){
			if(last4>last2){
				temp=i-last4;
			}else{
				if(last2==-1)
					temp=i+1;
				else
					temp=i-last2;
			}
			pen2=last2;
			last2=i;
			dp[i+1]+=temp;
		}else{
			if(pen2==-1&last4==-1)
				dp[i+1]+=(i+1);
			else if(pen2!=-1&&pen2>last4){
				dp[i+1]+=(i-pen2);
			}else if(last4>pen2){
				dp[i+1]+=(i-last4);
			}
		}
	}
	cout<<"DP: "<<endl;
	for(int i=0;i<=n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return dp[n];
}
int main(){
	int t,flag,n,dig,count;
	long long int nofour,nofoursub,res,k,j,i,odd,oddsub;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>n;
		long long int arr[n];
		odd=0;
		oddsub=0;
		nofour=0;
		nofoursub=0;
		count=0;
		res=n*(n+1)/2;
		for(i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]%2==1){
				odd++;
			}else{
				oddsub+=(odd*(odd+1)/2);
				odd=0;
			}
		}
		oddsub+=(odd*(odd+1)/2);
		//find all subsequences that have 4 !!
		nofoursub=calcnofoursub(arr,n);
		res=res-nofoursub+oddsub;
		cout<<endl<<"nofour sub: "<<nofoursub<<" oddsub: "<<oddsub<<endl;
		cout<<res<<endl;
	}	
}