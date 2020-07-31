#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;
lli mod=1000000007;
lli power(lli a,lli b){
	if(b==0)
		return 1;
	else if(b==1)
		return a%mod;
	else
		return (a%mod*a%mod*power(a,b-2)%mod)%mod;
}
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
	lli n,t,i,j,temp1,temp2,q,u,v,x,count;
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
		vector<lli> factors;
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
			count=0;
			for(j=0;j<primes.size()&&primes[j]*primes[j]<=costs[i];j++){
				//cout<<"X: "<<x<<endl;
				//cout<<"Prime: "<<primes[j]<<endl;
				while(x%primes[j]==0){
					//cout<<"Divisible "<<endl;
					count++;
					x/=primes[j];
				}
				if(x==1)
					break;
			}
			if(x>1){
				count++;
			}
			factors.push_back(count);
		}
		cout<<"Factors :"<<endl;
		for(i=0;i<factors.size();i++){
			cout<<factors[i]<<" ";
		}
		cout<<endl;
		cin>>q;
		while(q--){
			cin>>u>>v;
			u--;
			v--;
			count=0;
			vector<bool> visited(n,false);
			queue<vector<lli>> qu;
			vector<lli> path=bfs(u,v,visited,cities,qu);
			/*for(i=0;i<path.size();i++)
				cout<<path[i]<<" ";
			cout<<endl;*/
			for(i=0;i<path.size();i++){
				count+=factors[path[i]];
			}
			lli res=power(2,count)%mod;
			cout<<count<<endl;
		}

	}
}