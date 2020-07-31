/*
You are a treasure hunter looking for the rare stone kryptonite.
Your quest leads you to the entrace of cave system in a mountain 
in the middle of nowhere.
You find an old man at the entrance who tells you that the cave 
system has 'n' caves and 'm' magical tunnels.
Whenever you pass through a tunnel you get an additional strength 
'x' which could be positive or negative.
You enter through cave 1 and the treasure is in cave 'n'.

But wait that's not all.
In the nth cave there is a guardian who will let you take 
the stone only if you have the maximum possible strength.

Also you enter with strength 0 and all the tunnels are 
unidirectional(You can only travel in one direction.) 
but you can go through each tunnel and cave any number of times.

Find the maximum possible strength you can get.
If it is infinity print -1;

Input:
First Line - n and m where n is number of caves and m is number of tunnels
Next m lines will contain description of tunnels

a b x

tunnel starts from a, ends at b and gives strength of x

Output:

Single value of maximum possible strength or -1 if score is infinity.

Input
n=5 m=4

1 2 25
2 3 10
3 4 10
2 4 15

Output:45 (Going from 1->2->3->4)

*/

#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;

lli n;

vector<vector<pair<lli,lli>>> scores(2501);

int visited[2501]={0};

lli max(lli a,lli b){
	return a>b?a:b;
}

bool dfs_detect_positive_cycle(lli source,lli score,unordered_set<lli> s){
	visited[source]=1;
	s.insert(source);
	lli max=0;
	for(auto x:scores[source]){
		if(s.count(x.first)&&score+x.second>0){
			return true;
		}else if(!visited[x.first]){
			if(dfs_detect_positive_cycle(x.first,score+x.second,s))
				return true;
		}
	}
	return false;
}

lli compute_score(lli source,lli score,vector<bool>visited2){
	visited2[source]=true;
	lli mx=-INF;
	if(source==n)
		return score;
	for(auto x:scores[source]){
		if(!visited2[x.first])
			mx=max(mx,compute_score(x.first,score+x.second,visited2));
	}
	return mx;
}

int main(){
	lli m,i,a,b,c,res;
	pair<lli,lli> temp;
	unordered_set<lli> s;
	cin>>n>>m;
	Fi(i,0,m){
		cin>>a>>b>>c;
		temp.first=b;
		temp.second=c;
		scores[a].push_back(temp);
	}
	if(dfs_detect_positive_cycle(1,0,s)){
		cout<<"-1"<<endl;
	}else{
		vector<bool> visited2(n+1,false);
		res=compute_score(1,0,visited2);
		cout<<res<<endl;
	}
}