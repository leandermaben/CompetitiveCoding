#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

char mp[1000][1000];
int visited[1000][1000]={0};

void dfs(lli i,lli j,lli n,lli m){
	visited[i][j]=1;
	if(i>0&&(!visited[i-1][j]))
		dfs(i-1,j,n,m);
	if(i<n-1&&(!visited[i+1][j]))
		dfs(i+1,j,n,m);
	if(j>0&&(!visited[i][j-1]))
		dfs(i,j-1,n,m);
	if(j<m-1&&(!visited[i][j+1]))
		dfs(i,j+1,n,m);
}

int main(){
	lli n,m,i,j;
	char temp;
	cin>>n>>m;
	lli count=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>temp;
			mp[i][j]=temp;
			if(temp=='#'){
				visited[i][j]=1;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!visited[i][j]){
				count++;
				dfs(i,j,n,m);
			}
		}
	}
	cout<<count<<endl;
}