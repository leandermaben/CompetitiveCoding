#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int t,flag,n,dig,depth;
	string a;
	string::iterator i;
	long long int k,j;
	cin>>t;
	getline(cin,a);
	for(k=1;k<=t;k++){
		string s,res;
		getline(cin,s);
		depth=0;
		for(i=s.begin();i!=s.end();i++){
			dig=*i-'0';
			if(depth==dig)
				res.push_back(*i);
			else if(depth<dig){
				for(j=0;j<dig-depth;j++)
					res.push_back('(');
				res.push_back(dig+'0');
				depth=dig;
			}else{
				for(j=0;j<depth-dig;j++)
					res.push_back(')');
				res.push_back(dig+'0');
				depth=dig;
			}
		}
		for(j=0;j<depth;j++)
			res.push_back(')');
		cout<<"Case #"<<k<<": "<<res<<endl;

	}	
}