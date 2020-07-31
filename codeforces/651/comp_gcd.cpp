#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
	lli n,t,i,next,k;
	cin>>t;
	while(t--){
		cin>>n;
		lli a[2*n];
		for(i=0;i<2*n;i++){
			cin>>a[i];
		}
		i=0;
		k=0;
		while(k<n-1){
			if(a[i]!=-1){
				next=i+1;
				if(a[i]%2){
					while(next<2*n){
						if(a[next]%2==1){
							break;
						}
						next++;
					}

				}else{
					while(next<2*n){
						if(a[next]%2==0){
							break;
						}
						next++;
					}
				}
				if(next<2*n){
					a[next]=-1;
					k++;
					cout<<(i+1)<<" "<<(next+1)<<endl;
				}
			}
			i++;
		}
	}
}