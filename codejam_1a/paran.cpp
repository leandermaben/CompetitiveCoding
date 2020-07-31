#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int t,flag,n,dig,depth;
	string a;
	char c;
	vector<string> pat;
	//string::iterator i;
	long long int k,j,i,len,ind;
	cin>>t;
	for(k=1;k<=t;k++){
		string s,res;
		cin>>n;
		getline(cin,a);
		for(i=0;i<n;i++){
			getline(cin,s);
			pat.push_back(s);
		}
		flag=1;
		for(i=0;1;i++){
			c='\0';
			for(j=0;j<n;j++){
				ind=pat[j].length()-i-1;
				if(pat[j][ind]!='*'){
					c=pat[j][ind];
					break;
				}
			}
			if(c!='\0'){
				for(j=0;j<n;j++){
					ind=pat[j].length()-i-1;
					if(pat[j][ind]=='*'){
						pat[j].insert(ind+1,1,c);
					}else if(pat[j][ind]!=c){
						flag=0;
						break;
					}
				}
			}else{
				
			}
			
		}

		cout<<"Case #"<<k<<": "<<res<<endl;

	}	
}