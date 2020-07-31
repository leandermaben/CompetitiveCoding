#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;

const lli INF=INT64_MAX;
const lli MOD=1000000007;

int main(){
	lli n;
	cin>>n;
	lli table[1000001]={0};
	table[1]=1;
	table[2]=2;
	table[3]=4;
	table[4]=8;
	table[5]=16;
	table[6]=32;
	Fi(i,7,n+1){
		Fi(j,1,7){
			table[i]+=table[i-j];
			table[i]%=MOD;
		}
	}
	cout<<table[n];
}

/*
Wondering how you'll master the never-ending concepts in competitve programming?
Don't Worry ACM Manipal's got your back with The ACM Manipal Blog 
Our first feature is on decoding the data structure - Graphs.
So what are you waiting for? Click on the link below and begin your journey
to becomming a master of competitve coding.
*/