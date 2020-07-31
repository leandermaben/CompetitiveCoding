#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int validate(int mat[][100],int i,int j,int n,int sp){
	int check[n+1];
	for(int k=0;k<n;k++){
		for(int l=1;l<=n;l++)
			check[l]=0;
		for(int l=0;l<n;l++){
			if(mat[k][l]!=-1&&check[mat[k][l]])
				return 0;
			else if(mat[k][l]!=-1)
				check[mat[k][l]]=1;
		}
	}
	for(int l=0;l<n;l++){
		for(int k=1;k<=n;k++)
			check[k]=0;
		for(int k=0;k<n;k++){
			if(mat[k][l]!=-1&&check[mat[k][l]])
				return 0;
			else if(mat[k][l]!=-1)
				check[mat[k][l]]=1;
		}
	}
	
	if(i==n-1&&j==n-1)
	{
		int trace=0;
		for(int k=0;k<n;k++)
			trace+=mat[k][k];
		if(trace!=sp)
			return 0;
	}
	return 1;
}
int solveMat(int mat[][100],int i,int j,int n,int sp){
	int l,m;
	for(int k=1;k<=n;k++){
		mat[i][j]=k;
		if(!validate(mat,i,j,n,sp))
			continue;
		else{
			if(i==n-1&&j==n-1)
				return 1;
			else if(j==n-1){
				if(solveMat(mat,i+1,0,n,sp))
					return 1;
			}
			else{
				if(solveMat(mat,i,j+1,n,sp))
					return 1;
			}
		}
	}
	mat[i][j]=-1;
	return 0;
}
int main(){
	int t,flag;
	long long int l,m,r,c,x,k,trace,i,j,count,n,diff;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n>>k;
		trace=0;
		int mat[100][100];
		for(l=0;l<n;l++){
			for(m=0;m<n;m++){
				mat[l][m]=-1;
			}
		}
		if(solveMat(mat,0,0,n,k)){
			cout<<"Case #"<<i<<": "<<"POSSIBLE"<<endl;
			for(l=0;l<n;l++){
				for(m=0;m<n;m++){
					cout<<mat[l][m]<<" ";
				}
				cout<<endl;
			}
		}else{
			cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
		}
		
	}	
}