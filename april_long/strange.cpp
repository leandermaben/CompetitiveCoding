#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int x,k,i,j,count,n,sp,diff;
	bool sieve[100000];
	vector<int> primes;
	sieve[0]=false;
	sieve[1]=false;
	for(i=2;i<100000;i++)
		sieve[i]=true;
	for(i=2;i*i<100000;i++){
		if(sieve[i]){
			for(j=i*i;j<100000;j+=i)
				sieve[j]=false;
		}
	}
	for(i=2;i<100000;i++)
		if(sieve[i]){
			primes.push_back(i);
		}
	cin>>t;
	while(t--){
		cin>>x>>k;
		if(k==0){
			if(x==1)
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
		else if(log(x)/log(2)<k){
			cout<<"0"<<endl;
		}else if(k==1){
			cout<<"1"<<endl;
		}else{
			count=0;
			for(i=0;i<primes.size();i++){
				while(x%primes[i]==0){
					count++;
					x/=primes[i];
				}
				if(count>=k)
					break;
			}
			if(x>1)
				count++;
			if(count>=k)
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
	}	
}
