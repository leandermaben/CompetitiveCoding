#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int t,flag;
	long long int l,r,c,x,k,trace,i,j,count,n,sp,diff;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>n;
		trace=0;
		r=0;
		c=0;
		int mat[n][n];
		int check[n+1];
		for(i=0;i<n;i++){
			flag=0;
			for(l=0;l<=n;l++)
				check[l]=0;
			for(j=0;j<n;j++){
				cin>>mat[i][j];
				if(check[mat[i][j]])
					flag=1;
				else
					check[mat[i][j]]=1;
			}
			trace+=mat[i][i];
			if(flag){
				r++;
			}
		}
		for(j=0;j<n;j++){
			flag=0;
			for(l=0;l<=n;l++)
				check[l]=0;
			for(i=0;i<n;i++){
				if(check[mat[i][j]])
					flag=1;
				else
					check[mat[i][j]]=1;
			}
			if(flag){
				c++;
			}
		}
		cout<<"Case #"<<k<<": "<<trace<<" "<<r<<" "<<c<<endl;
	}	
}