#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int t,flag,n,dig,depth,pos;
	string a,pre,post,temp;
	char c;
	vector<string> pat;
	//string::iterator i;
	long long int ind,max,k,j,i,len;
	cin>>t;
	for(k=1;k<=t;k++){
		string s,res;
		flag=1;
		pre="";
		post="";
		max=0;
		cin>>n;
		//getline(cin,a);
		for(i=0;i<n;i++){
			//getline(cin,s);
			cin>>s;
			pat.push_back(s);
			pos=s.find('*');
			if(max<s.length()){
				max=s.length();
				ind=i;
			}
			if(post==""){
				post=s.substr(pos+1);

			}else{
				pos=s.find('*');
				if(pos==s.length()-1)
					continue;
				else
					temp=s.substr(pos+1);
				if(post.length()<temp.length()){
					if(post!=temp.substr(temp.length()-post.length())){
						flag=0;
						break;
					}else{
						post=temp;
					}
				}else{
					if(post.substr(post.length()-temp.length())!=temp){
						flag=0;
						break;
					}
				}
			}
			if(pre==""){
				pre=s.substr(0,pos);

			}else{
				pos=s.find('*');
				if(pos==0)
					continue;
				else
					temp=s.substr(0,pos);
				if(pre.length()<temp.length()){
					if(pre!=temp.substr(0,pre.length())){
						flag=0;
						break;
					}else{
						pre=temp;
					}
				}else{
					if(pre.substr(0,pos)!=temp){
						flag=0;
						break;
					}
				}
				
			}
		}
		if(flag){
			pos=pat[ind].find('*');
			if(pos==0)
				cout<<"Case #"<<k<<": "<<pat[ind].substr(1)<<endl;
			else if(pos==pat[i].length()-1)
				cout<<"Case #"<<k<<": "<<pat[ind].substr(0,pos)<<endl;
			else
				cout<<"Case #"<<k<<": "<<pat[ind].substr(0,pos)+pat[ind].substr(pos+1)<<endl;
		}else{
			cout<<"Case #"<<k<<": *"<<endl;
		}
		

	}	
}