#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int table[301][301][301];

int part(vector<int> v,int a,int b,int c,int item){
	vector<int> parts;
	parts.push_back(a);
	parts.push_back(b);
	parts.push_back(c);
	sort(parts.begin(),parts.end());
	int result=0;
	if(table[parts[0]][parts[1]][parts[2]]==-1){
		if(parts[0]-v[item]>=0)
			result=result||part(v,parts[0]-v[item],parts[1],parts[2],item-1);
		if(parts[1]-v[item]>=0)
			result=result||part(v,parts[0],parts[1]-v[item],parts[2],item-1);
		if(parts[2]-v[item]>=0)
			result=result||part(v,parts[0],parts[1],parts[2]-v[item],item-1);
		table[parts[0]][parts[1]][parts[2]]=result;
	}
	//cout<<a<<" "<<b<<" "<<c<<" "<<endl;
	//cout<<table[parts[0]][parts[1]][parts[2]]<<endl;
	return table[parts[0]][parts[1]][parts[2]];
}

int main(){
	int n,i,j,k,sum=0,temp;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
		sum+=temp;
	}
	//cout<<"Sum is "<<sum<<endl;
	if(sum%3!=0)
		cout<<0;
	else{
		for(i=0;i<=sum/3;i++){
			for(j=0;j<=sum/3;j++){
				for(k=0;k<=sum/3;k++){
					table[i][j][k]=-1;
				}
			}
		}
		table[0][0][0]=1;
		table[0][0][v[0]]=1;
		cout<<part(v,sum/3,sum/3,sum/3,n-1);
		/*for(i=0;i<=sum/3;i++){
			for(j=0;j<=sum/3;j++){
				for(k=0;k<sum/3;k++){
					cout<<table[i][j][k]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}*/
	}
}