#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;
typedef long long int lli;
const lli INF=INT64_MAX;
/*
The planet of Zurg is under attack from the neighbouring planet of Xeres.
General Kyle of Zurg has a weapon that can destroy 'all enemy spaceships 
in Zurg's atmosphere at the time of firing' but he can fire it only once.

The people of Xeres are lazy and won't change their attack pattern.
So General Kyle gives you the entry and exit time of each enemy spacecraft 
from the previous day and asks you to help him find out the maximum 
number of spacesips he can destroy.

Input:
n - number of spacecrafts
next n lines have 2 integers- entry and exit time of each spacecraft
(a spacecraft cannot be hit at exit time but can be hit at entry time 
as entry and exit are considered instantaneous)

Output:
Maximum number of spacecrafts that can be destroyed

Sample input:

3
1 4
3 5
6 7

Output:
2

If Kyle fires at time=3, he can hit 
2 spacecrafts

*/
int main(){
	lli i,j,n;
	cin>>n;
	lli ent[n],ext[n];
	Fi(i,0,n){
		cin>>ent[i]>>ext[i];
	}
	sort(ent,ent+n);
	sort(ext,ext+n);
	lli mx=0,cur=0;
	i=0;
	j=0;
	while(i<n&&j<n){
		if(ent[i]<ext[j]){
			cur++;
			i++;
		}
		else if(ent[i]>ext[j]){
			cur--;
			j++;
		}else{
			i++;
			j++;
		}
		mx=max(mx,cur);
	}
	cout<<mx;
}
