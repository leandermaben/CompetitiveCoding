#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool sortByN(vector<int>& a,vector<int>& b){
	if(a[0]==b[0])
		return a[1]<b[1];
	else
		return a[0]<b[0];
}
int main(){
	int t,flag;
	long long int sel,minimum,x,k,m,i,j,count,n,sp,diff,temp;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		vector<vector<int>> val(k);
		vector<int> min;
		vector<int> score(k,n);
		for(i=0;i<n;i++){
			for(j=0;j<k;j++){
				cin>>temp;
				val[j].push_back(temp);
			}
		}
		minimum=k;
		/*for(i=0;i<k;i++){
			for(j=0;j<n;j++){
				cout<<val[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(i=0;i<n;i++){
			vector<vector<int>> check(m+1,vector<int>(3,k));
			for(j=0;j<=m;j++)
				check[j][2]=j;
			for(j=0;j<k;j++){
				temp=val[j][i];
				check[temp][1]--;
			}
			for(j=0;j<min.size();j++){
				check[val[min[j]][i]][0]--;
			}
			sort(check.begin(),check.end(),sortByN);
			sel=check[0][2];
			for(j=0;j<k;j++){
				if(val[j][i]!=sel)
					score[j]--;
				minimum=minimum<score[j]?minimum:score[j];
			}
			min.clear();
			for(j=0;j<k;j++){
				if(score[j]==minimum)
					min.push_back(j);
			}
			cout<<sel<<" ";
		}
		cout<<endl;
	}	
}