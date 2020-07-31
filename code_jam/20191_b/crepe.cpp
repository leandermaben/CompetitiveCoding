#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
bool compareFirst(vector<lli>& a,vector<lli>& b){
	return a[0]<b[0];
}
bool compareSecond(vector<lli>& a,vector<lli>& b){
	return a[1]<b[1];
}
bool res(vector<lli>& a,vector<lli>& b){
	if(a[1]==b[1])
		return a[0]<b[0];
	return a[1]>b[1];

}
int main(){
	int t;
	lli p,q,i,j,x,y,k;
	char d;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>p>>q;
		vector<vector<lli>> west;
		vector<vector<lli>> east;
		vector<vector<lli>> north;
		vector<vector<lli>> south;
		for(i=0;i<p;i++){
			vector<lli> temp(2);
			cin>>x>>y>>d;
			temp[0]=x;
			temp[1]=y;
			switch(d){
				case 'N':{
					north.push_back(temp);
					break;
				}
				case 'S':{
					south.push_back(temp);
					break;
				}
				case 'W':{
					west.push_back(temp);
					break;
				}
				case 'E':{
					east.push_back(temp);
					break;
				}
			}
		}
		sort(east.begin(),east.end(),compareFirst);
		sort(west.begin(),west.end(),compareFirst);
		vector<vector<lli>> hpol;
		vector<lli> temp;
		temp.push_back(0);
		temp.push_back(0);
		hpol.push_back(temp);
		for(i=0;i<east.size();i++){
			temp.clear();
			if(hpol[hpol.size()-1][0]!=east[i][0]+1){
				temp.push_back(east[i][0]+1);
				temp.push_back(hpol[hpol.size()-1][1]+1);
				hpol.push_back(temp);
			}else{
				//cout<<"here"<<endl;
				hpol[hpol.size()-1][1]++;
			}
		}
		lli westCount=0;
		lli westIndex=0;
		lli polIndex=hpol.size()-1;
		for(i=0;i<hpol.size();i++){
			while(westIndex<west.size()&&west[westIndex][0]<=hpol[i][0])
				westIndex++;
			if(westIndex==west.size())
				break;
			hpol[i][1]+=(west.size()-westIndex);

		}
		/*for(i=west.size()-1;i>=0;i--){
			westIndex=west[i][0];
			westCount++;
			while(polIndex>=0&&hpol[polIndex][0]>=westIndex){
				polIndex--;
			}
			while(polIndex>=0&&hpol[polIndex][0]>westIndex){
				hpol[polIndex][1]++;
				polIndex--;
			}
		}*/
		sort(north.begin(),north.end(),compareSecond);
		sort(south.begin(),south.end(),compareSecond);
		vector<vector<lli>> vpol;
		temp.clear();
		temp.push_back(0);
		temp.push_back(0);
		vpol.push_back(temp);
		for(i=0;i<north.size();i++){
			temp.clear();
			if(vpol[vpol.size()-1][0]!=north[i][1]+1){
				temp.push_back(north[i][1]+1);
				temp.push_back(vpol[vpol.size()-1][1]+1);
				vpol.push_back(temp);
			}else{
				vpol[vpol.size()-1][1]++;
			}
		}
		lli southCount=0;
		lli southIndex=0;
		for(i=0;i<vpol.size();i++){
			while(southIndex<south.size()&&south[southIndex][1]<=vpol[i][0])
				southIndex++;
			if(southIndex==south.size())
				break;
			//cout<<"In south "<<vpol[i][0]<<endl;
			vpol[i][1]+=(south.size()-southIndex);

		}
		/*polIndex=vpol.size()-1;
		for(i=south.size()-1;i>=0;i--){
			southIndex=south[i][1];
			southCount++;
			while(polIndex>=0&&vpol[polIndex][0]<southIndex){
				vpol[polIndex][1]++;
				polIndex--;
			}
		}*/
		/*cout<<"HPOL: "<<endl;
		for(i=0;i<hpol.size();i++)
			cout<<hpol[i][0]<<" "<<hpol[i][1]<<endl;

		cout<<"VPOL: "<<endl;
		for(i=0;i<vpol.size();i++)
			cout<<vpol[i][0]<<" "<<vpol[i][1]<<endl;
		*/
		sort(hpol.begin(),hpol.end(),res);
		sort(vpol.begin(),vpol.end(),res);
		cout<<"Case #"<<k<<": "<<hpol[0][0]<<" "<<vpol[0][0]<<endl;
	}
	
}