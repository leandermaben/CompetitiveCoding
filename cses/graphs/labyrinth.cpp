#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;

char mp[1001][1001];
int visited[1001][1001]={0};

vector<lli> bfs_path(lli si,lli sj,lli ei,lli ej,lli n,lli m){
	lli i,j;
	visited[si][sj]=1;
	vector<lli> vec,cur,temp;
	vec.push_back(si);
	vec.push_back(sj);
	vec.push_back(0);
	queue<vector<lli>> q;
	q.push(vec);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		i=cur[0];
		j=cur[1];
		if(i==ei&&j==ej){
			return cur;
		}
		if(i>0&&(!visited[i-1][j])){
			visited[i-1][j]=1;
			temp=cur;
			temp[0]--;
			temp[2]++;
			temp.push_back(0);
			q.push(temp);
		}
		if(i<n-1&&(!visited[i+1][j])){
			visited[i+1][j]=1;
			temp=cur;
			temp[0]++;
			temp[2]++;
			temp.push_back(2);
			q.push(temp);
		}
		if(j>0&&(!visited[i][j-1])){
			visited[i][j-1]=1;
			temp=cur;
			temp[1]--;
			temp[2]++;
			temp.push_back(3);
			q.push(temp);
		}
		if(j<m-1&&(!visited[i][j+1])){
			visited[i][j+1]=1;
			temp=cur;
			temp[1]++;
			temp[2]++;
			temp.push_back(1);
			q.push(temp);
		}
	}
	temp[0]=-1;
	return temp;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	lli n,m,i,j,si,sj,ei,ej;
	vector<lli> res;
	char temp;
	char dir[]={'U','R','D','L'};
	cin>>n>>m;
	lli count=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>temp;
			if(temp=='A'){
				mp[i][j]='.';
				si=i;
				sj=j;
			}else if(temp=='B'){
				mp[i][j]='.';
				ei=i;
				ej=j;
			}else{
				mp[i][j]=temp;
			}
			if(temp=='#'){
				visited[i][j]=1;
			}
		}
	}
	res=bfs_path(si,sj,ei,ej,n,m);
	if(res[0]==-1)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<res[2]<<endl;
		for(i=3;i<res.size();i++)
			cout<<dir[res[i]];
		cout<<endl;
	}
}