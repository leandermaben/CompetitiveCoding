#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#define long long int lli
using namespace std;
bool indSort(const vector<int>& v1,const vector<int>& v2){
	return v1[0]<v2[0];
}
int main(){
	int n,q,i,temp,k,diff,j,flag,d,count;
	cin>>n>>q;
	vector<vector<int>> arr(n);
	for(i=0;i<n;i++){
		cin>>temp;
		arr[i].push_back(temp);
		arr[i].push_back(i);
	}
	sort(arr.begin(),arr.end(),indSort);
	vector<int> res;
	res.push_back(0);
	res.push_back(arr[0][0]);
	int check[n]={0};
	d=2;
	check[arr[0][1]]=1;
	for(k=1;k<n-1;k++){
		flag=1;
		check[arr[k][1]]=1;
		count=0;
		for(j=arr[k][1]-d+1;j<=arr[k][1]+d-1;j++){
			if(j>=0&&j<n){
				if(check[j]==1)
					count++;
				else
					count=0;
			}
			if(count==d)
				break;
		}
		if(count==d){
			res.push_back(arr[k][0]);
			d++;
			k--;
		}
		/*cout<<"k: "<<k<<"d: "<<d<<endl;
		for(j=0;j<n;j++)
			cout<<check[j]<<" ";
		cout<<endl;*/
	}
	for(i=d;i<=n;i++){
		res.push_back(arr[n-1][0]);
	}
	/*
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<res[i]<<" ";
	}
	*/
	while(q--){
		cin>>d;
		cout<<res[d]<<endl;
	}
}