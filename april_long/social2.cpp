#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int i,count,n,sp,diff;
	cin>>t;
	while(t--){
		cin>>n;
		flag=1;
		vector<int>pos;
		for(i=0;i<n;i++){
			cin>>sp;
			if(sp){
				pos.push_back(i);
			}
		}
		for(i=pos.size()-1;i>0;i--){
			diff=pos[i]-pos[i-1];
			if(diff<6){
				flag=0;
				break;
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
}