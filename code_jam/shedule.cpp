#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
bool sortByStart(const vector<int> a,const vector<int> b){
	return a[0]<b[0];
}
int main(){
	int t,flag,n,dig,depth,temp;
	long long int c,j,i,k,start;
	cin>>t;
	for(k=1;k<=t;k++){
		flag=1;
		j=-1;
		c=0;
		cin>>n;
		char res[n+1];
		res[n]='\0';
		vector<vector<int>> mat(n);
		for(i=0;i<n;i++){
			cin>>temp;
			mat[i].push_back(temp);
			cin>>temp;
			mat[i].push_back(temp);
			mat[i].push_back(i);
		}
		sort(mat.begin(),mat.end(),sortByStart);
		res[mat[0][2]]='C';
		for(i=1;i<n;i++){
			start=mat[i][0];
			if(start>=mat[c][1]){
				c=i;
				res[mat[i][2]]='C';
			}else{
				if(j==-1){
					j=i;
					res[mat[i][2]]='J';
				}else if(mat[i][0]>=mat[j][1]){
					j=i;
					res[mat[i][2]]='J';
				}else{
					cout<<"Case #"<<k<<": "<<"IMPOSSIBLE"<<endl;
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<"Case #"<<k<<": "<<res<<endl;

	}	
}