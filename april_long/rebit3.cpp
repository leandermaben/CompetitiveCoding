#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<string.h>
#define lli long long int
enum precedence {bor,bxor,band};
lli mod=998244353;
using namespace std;
lli gcdExtended(lli a, lli b, lli* x, lli* y); 
lli  modInverse(lli a, lli m) 
{ 
    lli x, y; 
    lli g = gcdExtended(a, m, &x, &y); 
    lli res = (x%m + m) % m; 
    return res; 
} 
  
lli gcdExtended(lli a, lli b, lli* x, lli* y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1;
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
lli power(lli a,lli b){
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
		return a*a*power(a,b-2);
}
int precedence(char c){
	if(c=='&')
		return 3;
	else if(c=='^')
		return 2;
	else if(c=='|')
		return 1;
	else
		return -1;
}
string postfix(char l[]){
	string post;
	char c;
	stack<char> st;
	st.push('N');
	lli n=strlen(l);
	for(int i=0;i<n;i++){
		if(l[i]=='#')
			post+=l[i];
		else if(l[i]=='(')
			st.push(l[i]);
		else if(l[i]==')'){
			while(st.top()!='N'&&st.top()!='('){
				c=st.top();
				st.pop();
				post+=c;
			}
			if(st.top()=='(')
				st.pop();
		}else{
			while(precedence(l[i])<=precedence(st.top())&&st.top()!='N'){
				c=st.top();
				st.pop();
				post+=c;
			}
			st.push(l[i]);
		}

	}
	while(st.top()!='N'){
		post+=st.top();
		st.pop();
	}
	return post;
}
vector<lli> solve(string post){
	vector<lli> temp;
	stack<vector<lli>> st;
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	for(int i=0;i<post.length();i++){
		if(post[i]=='#'){
			st.push(temp);
		}else{
			vector<lli> temp2;
			vector<lli> first=st.top();
			st.pop();
			vector<lli> second=st.top();
			st.pop();
			if(post[i]=='&'){
				temp2.push_back((first[0]*second[0]+first[0]*second[1]+first[1]*second[0]+first[0]*second[2]+first[2]*second[0]+first[2]*second[3]+first[3]*second[2]+first[0]*second[3]+first[3]*second[0])%mod);
				temp2.push_back((first[1]*second[1])%mod);
				temp2.push_back((first[2]*second[1]+first[1]*second[2]+first[2]*second[2])%mod);
				temp2.push_back((first[3]*second[1]+first[1]*second[3]+first[3]*second[3])%mod);
				st.push(temp2);
			}else if(post[i]=='^'){
				temp2.push_back((first[0]*second[0]+first[1]*second[1]+first[2]*second[2]+first[3]*second[3])%mod);
				temp2.push_back((first[0]*second[1]+first[1]*second[0]+first[2]*second[3]+first[3]*second[2])%mod);
				temp2.push_back((first[0]*second[2]+first[2]*second[0]+first[1]*second[3]+first[3]*second[1])%mod);
				temp2.push_back((first[0]*second[3]+first[3]*second[0]+first[1]*second[2]+first[2]*second[1])%mod);
				st.push(temp2);
			}else{
				temp2.push_back((first[0]*second[0])%mod);
				temp2.push_back((first[0]*second[1]+first[1]*second[0]+first[1]*second[1]+first[1]*second[2]+first[2]*second[1]+first[3]*second[1]+first[1]*second[3]+first[3]*second[2]+first[2]*second[3])%mod);
				temp2.push_back((first[0]*second[2]+first[2]*second[2]+first[2]*second[0])%mod);
				temp2.push_back((first[0]*second[3]+first[3]*second[3]+first[3]*second[0])%mod);
				st.push(temp2);
			}
		}
	}
	return st.top();
}
int main(){
	int t,flag;
	long long int qinv,sel,minimum,x,k,m,i,j,count,n,sp,diff,temp,hcount;
	cin>>t;
	while(t--){
		char l[300001];
		cin>>l;
		string post;
		post=postfix(l);
		//cout<<post<<endl;
		vector<lli> res=solve(post);
		/*cout<<res[0]<<" ";
		cout<<res[1]<<" ";
		cout<<res[2]<<" ";
		cout<<res[3]<<" ";
		cout<<endl;*/
		qinv=modInverse((res[0]+res[1]+res[2]+res[3])%mod,mod);
		cout<<(res[0]*qinv)%mod<<" ";
		cout<<(res[1]*qinv)%mod<<" ";
		cout<<(res[2]*qinv)%mod<<" ";
		cout<<(res[3]*qinv)%mod<<" ";
		cout<<endl;
	}
}