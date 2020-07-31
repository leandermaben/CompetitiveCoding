#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

lli min(lli a,lli b){
	return a<b?a:b;
}

int main(){
	lli t,n,temp,check,res,count,mi;
	cin>>t;
	while(t--){

		cin>>n;
		unordered_map<lli,lli> mapa,mapb;
		map<lli,lli> map_final;
		set<lli> st;

		//mapa -stores number of each type of element in array a
		//set just stores all unique elements in a and b in sorted order

		Fi(i,0,n){
			cin>>temp;
			mapa[temp]++;
			st.insert(temp);
		}
		Fi(i,0,n){
			cin>>temp;
			mapb[temp]++;
			st.insert(temp);
		}
		mi=*st.begin();
		//count-number of elements that have to be swapped(in both arrays)
		//check- to ensure that equal number of elements should be swapped from both arrays
		//map_final stores number of each element that has to be swapped

		check=0;
		count=0;
		for(auto x:st){
			//for each unique element checking number of excess elements in a or b

			temp=mapa[x]-mapb[x];
			if(temp%2!=0){
				//if there are odd number of extra for a given element then quit
				check=-1;
				break;
			}

			if(temp>0){
				//extra in a
				map_final[x]=temp/2;
				check+=(temp/2);
			}
			else if(temp<0){
				//extra in b
				temp=-temp;
				map_final[x]=temp/2;
				check-=(temp/2);
			}
			count+=(temp/2);
		}

		if(check!=0){
			cout<<"-1"<<endl;
			continue;
		}

		temp=0;
		res=0;
		map<lli,lli>::iterator trav=map_final.begin();
		
		while(temp<count/2){
			//considering only the smallest count/2 elements for cost
			if(trav->second+temp<=count/2){
				temp+=trav->second;
				res+=min(2*trav->second*mi,(trav->first*trav->second));
			}else{
				temp=count/2;
				res+=min(2*(count/2-trav->second)*mi,trav->first*(count/2-trav->second));
			}
			trav++;
		}
		
		cout<<res<<endl;

	}
}
