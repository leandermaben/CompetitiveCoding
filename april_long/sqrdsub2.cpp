#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
long long int calcfoursub(long long int arr[],int n){
	long long int dp[n+1];
	long long int temp,count,pen2,last,last2,last4;
	dp[0]=0;
	count=0;
	last2=-1;
	last4=-1;
	pen2=-1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(arr[i-1]%4==0){
			dp[i]+=i;
			last4=i-1;
		}else if(arr[i-1]%2==0){
			last=last2>last4?last2:last4;
			dp[i]+=(last+1);
			pen2=last2;
			last2=i-1;
		}else{
			last=pen2>last4?pen2:last4;
			dp[i]+=(last+1);
		}
		//cout<<"Res: "<<arr[i]<<endl;
	}
	/*cout<<"DP: "<<endl;
	for(int i=0;i<=n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;*/
	return dp[n];
}
int main(){
	int t,flag,n,dig,count;
	long long int nofour,foursub,res,k,j,i,odd,oddsub;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>n;
		long long int arr[n];
		odd=0;
		oddsub=0;
		count=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]%2==1||arr[i]%2==-1){
				//cout<<"This is odd "<<i<<endl;
				odd++;
			}else{
				//cout<<"This is not odd "<<i<<endl;
				oddsub+=(odd*(odd+1)/2);
				odd=0;
			}
		}
		oddsub+=(odd*(odd+1)/2);
		//find all subsequences that have 4 !!
		foursub=calcfoursub(arr,n);
		res=oddsub+foursub;
		//cout<<endl<<"four sub: "<<foursub<<" oddsub: "<<oddsub<<endl;
		cout<<res<<endl;
	}	
}