#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
#define INF 1e9
using namespace std;
char mp[1001][1001];
lli cost[1001][1001];
vector<vector<lli>> visited;
vector<vector<lli>> monsters;
lli yd[]={0,1,0,-1};
lli xd[]={-1,0,1,0};
lli n,m;
lli min(lli a,lli b){
	return (a<b)?a:b;
}

bool e(lli i, lli j){
	if((i>=0)&&(i<n)&&(j>=0)&&(j<m)&&(mp[i][j]!='#')&&(visited[i][j]==0))
		return true;
	return false;
}

bool safe(lli i, lli j,lli dist){
	if(i>=0&&i<n&&j>=0&&j<m&&mp[i][j]!='#'&&visited[i][j]==0&&dist<cost[i][j])
		return true;
	return false;
}

void bfs_compute_monster(){
	vector<lli> v(m,0),temp(3),cur;
	queue<vector<lli>> q;
	for(vector<lli>& x:monsters){
		visited.assign(n,v);
		x.push_back(0);
		cost[x[0]][x[1]]=0;
		visited[x[0]][x[1]]=1;
		q.push(x);
		while(!q.empty()){
			cur=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				if(e(cur[0]+xd[i],cur[1]+yd[i])){
					temp[0]=cur[0]+xd[i];
					temp[1]=cur[1]+yd[i];
					temp[2]=cur[2]+1;
					cost[temp[0]][temp[1]]=min(cost[temp[0]][temp[1]],temp[2]);
					visited[temp[0]][temp[1]]=1;
					q.push(temp);
				}
			}
		}
	}
}
bool isEnd(vector<lli>& state){
	if(state[0]==0||state[0]==n-1||state[1]==0||state[1]==m-1)
		return true;
	return false;
}

vector<lli> bfs_runner(lli si,lli sj){
	vector<lli> v(m,0),temp(3),cur;
	queue<vector<lli>> q;
	visited.assign(n,v);
	temp[0]=si;
	temp[1]=sj;
	temp[2]=0;
	visited[temp[0]][temp[1]]=1;
	q.push(temp);
	if(isEnd(temp)){
		return temp;
	}
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(safe(cur[0]+xd[i],cur[1]+yd[i],cur[2]+1)){
				temp=cur;
				temp[0]=cur[0]+xd[i];
				temp[1]=cur[1]+yd[i];
				temp[2]=cur[2]+1;
				temp.push_back(i);
				visited[temp[0]][temp[1]]=1;
				q.push(temp);
				if(isEnd(temp))
					return temp;
			}
		}
	}
	temp[0]=-1;
	return temp;
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	lli i,j,si,sj,ei,ej;
	vector<lli> res,temp{0,0};
	char c;
	char dir[]={'U','R','D','L'};
	cin>>n>>m;
	lli count=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>c;
			cost[i][j]=INF;
			if(c=='A'){
				mp[i][j]='.';
				si=i;
				sj=j;
			}else if(c=='M'){
				mp[i][j]='M';
				temp[0]=i;
				temp[1]=j;
				monsters.push_back(temp);
			}else{
				mp[i][j]=c;

			}
		}
	}
	bfs_compute_monster();
	/*for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}*/
	res=bfs_runner(si,sj);
	if(res[0]==-1){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		cout<<res[2]<<endl;
		for(i=3;i<res.size();i++)
			cout<<dir[res[i]];
		cout<<endl;
	}
}