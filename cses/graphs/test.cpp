#include<bits/stdc++.h>
#include<iostream>
#define lli long long int
using namespace std;
int main(){
	vector<lli> temp;
	temp.push_back(5);
	vector<lli> x;
	x.push_back(10);
	x=temp;
	cout<<x[0]<<endl;
	x[0]=2;
	cout<<temp[0]<<endl;

}