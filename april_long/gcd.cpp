#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int num,x,k,i,j,count,n,sp,diff;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			num=1;
			cout<<"1"<<endl;
			cout<<"1 1"<<endl;
			continue;
		}
		num=n/2;
		cout<<num<<endl;
		bool sieve[n+1];
		vector<vector<int>> res(num);
		sieve[0]=false;
		sieve[1]=false;
		res[0].push_back(1);
		res[0].push_back(2);
		for(i=2;i<n+1;i++)
			sieve[i]=true;
		k=0;
		for(j=4;j<n+1;j+=2){
			sieve[j]=false;
			if(k<num)
				res[++k].push_back(j);
		}
		for(i=3;i*i<n+1;i++){
			if(sieve[i]){
				res[0].push_back(i);
				k=0;
				for(j=i*i;j<n+1;j+=i){
					if(sieve[j]){
						sieve[j]=false;
						if(j/2<num)
							res[j/2].push_back(j);
						else{
							res[j/2-1].push_back(j);
						}
					}
				}
			}
		}
		for(;i<n+1;i++)
			if(sieve[i])
				res[0].push_back(i);
			
		for(i=0;i<res.size();i++){
			cout<<res[i].size()<<" ";
			for(j=0;j<res[i].size();j++){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
		/*cout<<"1 ";
		for(i=0;primes[i]<=n;i++){
			cout<<primes[i]<<" ";
		}
		for(i=2;i<=num;i++){
			cout<<endl;
			cout<<(2*i)<<" ";
			for(j=1;primes[j]<=n;j++){
				if(i%primes[j]==1){
					x=primes[j]*((i/primes[j])*k);
					if(x>num)
						break;
					cout<<x<<" ";
				}
			}
		}*/
	}	
}