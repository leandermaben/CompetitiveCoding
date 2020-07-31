#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	lli t,n,k,i,j,l,count,wrong;
	cin>>t;
	while(t--){
		cin>>n>>k;
		lli a[n+1];
		lli h[n+1];
		lli res[n][3];
		lli check[n+1];
		count=0;
		wrong=0;
		j=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			h[a[i]]=i;
			if(a[i]==i)
				check[i]=1;
			else{
				check[i]=0;
				wrong++;
			}	
		}
		for(i=1;i<=n-2;){
			if(!check[i]){
				count++;
				if(h[i]!=a[i]){
					res[j][2]=h[i];
					res[j][1]=h[h[i]];
					res[j++][0]=i;
					check[i]=1;
					check[h[i]]=1;
					wrong-=2;
					if(a[i]==h[h[i]]){
						wrong--;
						check[a[i]]=1;
					}
					a[h[h[i]]]=a[i];
					h[a[i]]=h[h[i]];
					i++;

				}else{
					l=i+1;
					while((check[l]||l==h[i])&&l<=n){
						l++;
					}
					if(l==n+1)
						break;
					wrong--;
					res[j][2]=h[i];
					res[j][0]=i;
					res[j++][1]=l;
					check[i]=1;
					a[h[i]]=a[l];
					h[a[l]]=h[i];
					a[l]=a[i];
					h[a[i]]=l;
					i=l;
				}
			}else{
				i++;
			}
		}
		if(wrong==0){
			cout<<count<<endl;
			for(i=0;i<j;i++){
				cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
			}
		}else{
			cout<<"-1"<<endl;
		}
		/*else{
			if(a[n-2]==n-2||a[n-1]==n-1||a[n]==n)
				cout<<"-1"<<endl;
			else{
				count++;
				res[j][0]=n-2;
				res[j][2]=h[n-2];
				res[j++][1]=h[h[n-2]];
				if(count<=k){
					cout<<count<<endl;
					for(i=0;i<j;i++){
						cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
					}
				}else{
					cout<<"-1"<<endl;
				}
			}
		}*/
	}
}

