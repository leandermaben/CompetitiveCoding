#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

typedef vector<vector<pair<lli,lli>>> list2d;
typedef vector<pair<lli,lli>> list;

lli n,m;
lli distance1[100001];
lli distancen[100001];

list2d path(100001);
list2d rpath(100001);

void dijkstra(){
	lli i;
	pair<lli,lli> cur;
	set<pair<lli,lli>>::iterator temp;
	Fi(i,0,100001){
		distance1[i]=INF;
		distancen[i]=INF;
	}
	distance1[1]=0;
	distancen[n]=0;
	set<pair<lli,lli>> s,s2;
	Fi(i,1,n+1){
		s.insert(pair<lli,lli>(distance1[i],i));
		s2.insert(pair<lli,lli>(distancen[i],i));
	}
	Fi(i,1,n+1){
		cur=*(s.begin());
		s.erase(s.begin());
		if(cur.first==INF){
			break;
		}
		for(auto x:path[cur.second]){
			if(cur.first+x.second<distance1[x.first]){
				temp=(s.lower_bound(pair<lli,lli>(distance1[x.first],x.first)));
				distance1[x.first]=cur.first+x.second;
				s.erase(temp);
				s.insert(pair<lli,lli>(distance1[x.first],x.first));
			}
		}
	}
	Fi(i,1,n+1){
		cur=*(s2.begin());
		s2.erase(s2.begin());
		if(cur.first==INF){
			break;
		}
		for(auto x:rpath[cur.second]){
			if(cur.first+x.second<distancen[x.first]){
				temp=(s2.lower_bound(pair<lli,lli>(distancen[x.first],x.first)));
				distancen[x.first]=cur.first+x.second;
				s2.erase(temp);
				s2.insert(pair<lli,lli>(distancen[x.first],x.first));
			}
		}
	}

}

int main(){
	lli i,j,a,b,c,mn=INF;
	cin>>n>>m;
	Fi(i,0,m){
		cin>>a>>b>>c;
		path[a].push_back(pair<lli,lli>(b,c));
		rpath[b].push_back(pair<lli,lli>(a,c));
	}
	dijkstra();
	Fi(i,1,n+1){
		for(auto x:path[i]){
			if(distance1[i]!=INF&&distancen[x.first]!=INF)
				mn=min(mn,distance1[i]+(x.second/2)+distancen[x.first]);
		}
	}
	cout<<mn;
}