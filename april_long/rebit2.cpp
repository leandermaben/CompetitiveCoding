#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#define lli long long int
using namespace std;
lli mod=998244353;
vector<int> lparen;
vector<int> rparen;
vector<int> an;
vector<int> orr;
vector<int> exor;
vector<int> hsh;
vector<vector<lli>> res;
long long int p[100001];
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
void solve(char l[],int a,int b){
	long long int i;
	int start,end;
	/*for(int i=0;i<res.size();i++){
		cout<<res[i][0]<<" ";
		cout<<res[i][1]<<" ";
		cout<<res[i][2]<<" ";
		cout<<res[i][3]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	i=0;
	while(an.size()&&i<an.size()){
		if(an[i]>b)
			break;
		if(an[i]>=a&&an[i]<=b){
			vector<long long int> temp;
			//cout<<"In And with size: "<<an.size()<<endl;
			if(l[an[i]-1]=='#'){
				if(l[an[i]+1]=='#'){
					temp.push_back(9);
					temp.push_back(1);
					temp.push_back(3);
					temp.push_back(3);
					res.push_back(temp);
					l[an[i]-1]=-5;
					l[an[i]+1]=-5;
					p[an[i]-1]=res.size()-1;
					p[an[i]+1]=res.size()-1;
				}else{
					//cout<<"a: "<<a<<" b: "<<b<<endl;
					int ind=p[an[i]+1];
					//cout<<"index "<<ind<<endl;
					//cout<<l<<endl;
					vector<lli> second=res[ind];
					temp.push_back(2*second[3]+4*second[0]+second[1]+2*second[2]);
					temp.push_back(second[1]);
					temp.push_back(second[1]+2*second[2]);
					temp.push_back(second[1]+2*second[3]);
					res.push_back(temp);
					l[an[i]-1]=-5;
					l[an[i]+1]=-5;
					p[an[i]-1]=res.size()-1;
					p[an[i]+1]=res.size()-1;
					res[ind]=temp;

				}
			}else{
				if(l[an[i]+1]=='#'){
					int ind=p[an[i]+1];
					vector<lli> first=res[ind];
					temp.push_back(2*first[3]+4*first[0]+first[1]+2*first[2]);
					temp.push_back(first[1]);
					temp.push_back(first[1]+2*first[2]);
					temp.push_back(first[1]+2*first[3]);
					res.push_back(temp);
					l[an[i]-1]=-5;
					l[an[i]+1]=-5;
					p[an[i]-1]=res.size()-1;
					p[an[i]+1]=res.size()-1;
					res[ind]=temp;				
				}else{
					int ind1=p[an[i]-1];
					int ind2=p[an[i]+1];
					vector<lli> first=res[ind1];
					vector<lli> second=res[ind2];
					temp.push_back(first[0]*second[0]+first[0]*second[1]+first[1]*second[0]+first[0]*second[2]+first[2]*second[0]+first[2]*second[3]+first[3]*second[2]+first[0]*second[3]+first[3]*second[0]);
					temp.push_back(first[1]*second[1]);
					temp.push_back(first[2]*second[1]+first[1]*second[2]+first[2]*second[2]);
					temp.push_back(first[3]*second[1]+first[1]*second[3]+first[3]*second[3]);
					res.push_back(temp);
					l[an[i]-1]=-5;
					l[an[i]+1]=-5;
					p[an[i]-1]=res.size()-1;
					p[an[i]+1]=res.size()-1;
					res[ind1]=temp;
					res[ind2]=temp;
				}
			}
			an.erase(an.begin()+i);
		}else
			i++;
	}
	/*for(int i=0;i<res.size();i++){
		cout<<res[i][0]<<" ";
		cout<<res[i][1]<<" ";
		cout<<res[i][2]<<" ";
		cout<<res[i][3]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	i=0;
	while(exor.size()&&i<exor.size()){
		//cout<<"In Exor"<<endl;
		if(exor[i]>b)
			break;
		if(exor[i]>=a&&exor[i]<=b){
			vector<long long int> temp;
			if(l[exor[i]-1]=='#'){
				if(l[exor[i]+1]=='#'){
					temp.push_back(4);
					temp.push_back(4);
					temp.push_back(4);
					temp.push_back(4);
					res.push_back(temp);
					l[exor[i]-1]=-5;
					l[exor[i]+1]=-5;
					p[exor[i]-1]=res.size()-1;
					p[exor[i]+1]=res.size()-1;
				}else{
					//cout<<"Here"<<endl;
					int ind=p[exor[i]+1];
					vector<lli> second=res[ind];
					/*for(int a=0;a<4;a++)
						cout<<second[a]<<" ";
					cout<<endl;*/
					temp.push_back(second[3]+second[0]+second[1]+second[2]);
					temp.push_back(second[3]+second[0]+second[1]+second[2]);
					temp.push_back(second[3]+second[0]+second[1]+second[2]);
					temp.push_back(second[3]+second[0]+second[1]+second[2]);
					res.push_back(temp);
					l[exor[i]-1]=-5;
					l[exor[i]+1]=-5;
					p[exor[i]-1]=res.size()-1;
					p[exor[i]+1]=res.size()-1;
					res[ind]=temp;
					
				}
			}else{
				if(l[exor[i]+1]=='#'){
					int ind=p[exor[i]+1];
					vector<lli> first=res[ind];
					temp.push_back(first[3]+first[0]+first[1]+first[2]);
					temp.push_back(first[3]+first[0]+first[1]+first[2]);
					temp.push_back(first[3]+first[0]+first[1]+first[2]);
					temp.push_back(first[3]+first[0]+first[1]+first[2]);
					res.push_back(temp);
					l[exor[i]-1]=-5;
					l[exor[i]+1]=-5;
					p[exor[i]-1]=res.size()-1;
					p[exor[i]+1]=res.size()-1;
					res[ind]=temp;
					
				}else{
					int ind1=p[exor[i]-1];
					int ind2=p[exor[i]+1];
					vector<lli> first=res[ind1];
					vector<lli> second=res[ind2];
					temp.push_back(first[0]*second[0]+first[1]*second[1]+first[2]*second[2]+first[3]*second[3]);
					temp.push_back(first[0]*second[1]+first[1]*second[0]+first[2]*second[3]+first[3]*second[2]);
					temp.push_back(first[0]*second[2]+first[2]*second[0]+first[1]*second[3]+first[3]*second[1]);
					temp.push_back(first[0]*second[3]+first[3]*second[0]+first[1]*second[2]+first[2]*second[1]);
					res.push_back(temp);
					l[exor[i]-1]=-5;
					l[exor[i]+1]=-5;
					p[exor[i]-1]=res.size()-1;
					p[exor[i]+1]=res.size()-1;
					res[ind1]=temp;
					res[ind2]=temp;
					
				}
				
			}
			exor.erase(exor.begin()+i);
		}else
			i++;
	}
	/*for(int i=0;i<res.size();i++){
		cout<<res[i][0]<<" ";
		cout<<res[i][1]<<" ";
		cout<<res[i][2]<<" ";
		cout<<res[i][3]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	i=0;
	while(orr.size()&&i<orr.size()){
		//cout<<"In Or"<<endl;
		if(orr[i]>b)
			break;
		if(orr[i]>=a&&orr[i]<=b){
			vector<long long int> temp;
			if(l[orr[i]-1]=='#'){
				if(l[orr[i]+1]=='#'){
					temp.push_back(1);
					temp.push_back(9);
					temp.push_back(3);
					temp.push_back(3);
					res.push_back(temp);
					l[orr[i]-1]=-5;
					l[orr[i]+1]=-5;
					p[orr[i]-1]=res.size()-1;
					p[orr[i]+1]=res.size()-1;
				}else{
					int ind=p[orr[i]+1];
					vector<lli> second=res[ind];
					temp.push_back(second[0]);
					temp.push_back(4*second[1]+second[0]+2*second[2]+2*second[3]);
					temp.push_back(2*second[2]+second[0]);
					temp.push_back(second[0]+2*second[3]);
					res.push_back(temp);
					l[orr[i]-1]=-5;
					l[orr[i]+1]=-5;
					p[orr[i]-1]=res.size()-1;
					p[orr[i]+1]=res.size()-1;
					res[ind]=temp;
					
				}
			}else{
				if(l[orr[i]+1]=='#'){
					int ind=p[orr[i]+1];
					vector<lli> first=res[ind];
					temp.push_back(first[0]);
					temp.push_back(4*first[1]+first[0]+2*first[2]+2*first[3]);
					temp.push_back(2*first[2]+first[0]);
					temp.push_back(first[0]+2*first[3]);
					res.push_back(temp);
					l[orr[i]-1]=-5;
					l[orr[i]+1]=-5;
					p[orr[i]-1]=res.size()-1;
					p[orr[i]+1]=res.size()-1;
					res[ind]=temp;
					
				}else{
					int ind1=p[orr[i]-1];
					int ind2=p[orr[i]+1];
					vector<lli> first=res[ind1];
					vector<lli> second=res[ind2];
					temp.push_back(first[0]*second[0]);
					temp.push_back(first[0]*second[1]+first[1]*second[0]+first[1]*second[1]+first[1]*second[2]+first[2]*second[1]+first[3]*second[1]+first[1]*second[3]+first[3]*second[2]+first[2]*second[3]);
					temp.push_back(first[0]*second[2]+first[2]*second[2]+first[2]*second[0]);
					temp.push_back(first[0]*second[3]+first[3]*second[3]+first[3]*second[0]);
					res.push_back(temp);
					l[orr[i]-1]=-5;
					l[orr[i]+1]=-5;
					p[orr[i]-1]=res.size()-1;
					p[orr[i]+1]=res.size()-1;
					res[ind1]=temp;	
					res[ind2]=temp;
					
				}
				
			}
			orr.erase(orr.begin()+i);
		}else
			i++;
	}
}
lli power(lli a,lli b){
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
		return a*a*power(a,b-2);
}
lli inv(lli a){
	return power(a,mod-2);
}
int main(){
	int t,flag;
	long long int qinv,sel,minimum,x,k,m,i,j,count,n,sp,diff,temp,hcount;
	cin>>t;
	while(t--){
		char l[100001];
		hcount=0;
		cin>>l;
		n=strlen(l);
		lparen.clear();
		rparen.clear();
		an.clear();
		orr.clear();
		exor.clear();
		res.clear();
		hsh.clear();
		stack<lli> st;
		
		for(i=0;i<n;i++){
			switch(l[i]){
				case '(': st.push(i);break;
				case ')':{
							rparen.push_back(i);
							lparen.push_back(st.top());
							//cout<<"lparen id: "<<st.top()<<endl;
							st.pop();
							break;}
				case '&':an.push_back(i);break;
				case '|':orr.push_back(i);break;
				case '^':exor.push_back(i);break;
				case '#':{
					hcount++;
					vector<lli> temp;
					temp.push_back(1);
					temp.push_back(1);
					temp.push_back(1);
					temp.push_back(1);
					res.push_back(temp);
					l[i]=-5;
					p[i]=res.size()-1;
				}
			}
		}
		for(i=0;i<lparen.size();i++){
			solve(l,lparen[i],rparen[i]);
			p[lparen[i]]=p[lparen[i]+1];
			p[rparen[i]]=p[rparen[i]-1];
			l[lparen[i]]=-5;
			l[rparen[i]]=-5;
		}
		solve(l,0,n-1);
		/*cout<<endl;
		for(i=0;i<res.size();i++){
			cout<<res[i][0]<<" ";
			cout<<res[i][1]<<" ";
			cout<<res[i][2]<<" ";
			cout<<res[i][3]<<" ";
			cout<<endl;
		}
		cout<<endl;*/
		//if(res.size()<2){
		/*
		cout<<res[p[0]][0]<<" ";
		cout<<res[p[0]][1]<<" ";
		cout<<res[p[0]][2]<<" ";
		cout<<res[p[0]][3]<<" ";*/
		/*}else{
			cout<<res[1][0]<<" ";
			cout<<res[1][1]<<" ";
			cout<<res[1][2]<<" ";
			cout<<res[1][3]<<" ";
		}*/
		//cout<<endl;
		/*for(i=0;i<n;i++){
			cout<<p[i]<<" ";
		}
		cout<<endl;*/
		qinv=modInverse(power(4,hcount),mod);
		cout<<(res[p[0]][0]*qinv)%mod<<" ";
		cout<<(res[p[0]][1]*qinv)%mod<<" ";
		cout<<(res[p[0]][2]*qinv)%mod<<" ";
		cout<<(res[p[0]][3]*qinv)%mod<<" ";
		cout<<endl;

	}	
}