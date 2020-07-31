#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;
lli mod=1000000007;
vector<lli> bfs(lli u,lli v,vector<bool> visited,vector<vector<lli>> cities,queue<vector<lli>> q){
	vector<lli> temp;
	temp.push_back(u);
	vector<lli> pres;
	lli cur;
	visited[u]=true;
	if(u==v){
		return temp;
	}
	q.push(temp);
	while(!q.empty()){
		pres=q.front();
		cur=pres[pres.size()-1];
		q.pop();
		for(lli i=0;i<cities[cur].size();i++){
			if(!visited[cities[cur][i]]){
				visited[cities[cur][i]]=true;
				pres.push_back(cities[cur][i]);
				q.push(pres);
				if(cities[cur][i]==v)
					return pres;
				pres.erase(pres.end()-1);
			}
		}
	}
	return temp;
}
int main(){
	lli n,t,i,j,temp1,temp2,q,u,v,x,count,res;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool sieve[1001];
	vector<int> primes;
	sieve[0]=false;
	sieve[1]=false;
	for(i=2;i<1001;i++)
		sieve[i]=true;
	for(i=2;i*i<1001;i++){
		if(sieve[i]){
			for(j=i*i;j<1001;j+=i)
				sieve[j]=false;
		}
	}
	for(i=2;i<1001;i++)
		if(sieve[i]){
			primes.push_back(i);
		}
	cin>>t;
	while(t--){
		cin>>n;
		int costs[n];
		vector<vector<vector<lli>>> factors;
		vector<vector<lli>> cities(n);
		for(i=0;i<n-1;i++){
			cin>>temp1>>temp2;
			temp1--;
			temp2--;
			cities[temp1].push_back(temp2);
			cities[temp2].push_back(temp1);
		}
		for(i = 0;i<n;i++){
			cin>>x;
			costs[i]=x;
			vector<vector<lli>> temp;
			for(j=0;j<primes.size()&&primes[j]*primes[j]<=costs[i];j++){
				count=0;
				//cout<<"X: "<<x<<endl;
				//cout<<"Prime: "<<primes[j]<<endl;
				while(x%primes[j]==0){
					//cout<<"Divisible "<<endl;
					count++;
					x/=primes[j];
				}
				if(count>0){
					vector<lli> fact;
					fact.push_back(primes[j]);
					fact.push_back(count);
					temp.push_back(fact);
				}
				if(x==1)
					break;
			}
			if(x>1){
				vector<lli> fact;
				fact.push_back(x);
				fact.push_back(1);
				temp.push_back(fact);
			}
			factors.push_back(temp);
		}
		/*for(i=0;i<factors.size();i++){
			cout<<costs[i]<<endl;
			for(j=0;j<factors[i].size();j++){
				cout<<factors[i][j][0]<<": "<<factors[i][j][1]<<endl;
			}
			cout<<endl;
		}*/
		cin>>q;
		while(q--){
			cin>>u>>v;
			u--;
			v--;
			vector<bool> visited(n,false);
			queue<vector<lli>> qu;
			vector<lli> path=bfs(u,v,visited,cities,qu);
			//for(i=0;i<path.size();i++)
			//	cout<<path[i]<<" ";
			//cout<<endl;
			vector<vector<lli>> prod;
			unordered_map<lli,lli> map;
			for(i=0;i<path.size();i++){
				for(j=0;j<factors[path[i]].size();j++){
					map[(factors[path[i]][j][0])]+=((factors[path[i]][j][1])%mod);
				}
			}
			res=1;
			for(auto x:map){
				res*=((x.second+1)%mod);
				res%=mod;
			}
			cout<<res<<endl;
		}

	}
}