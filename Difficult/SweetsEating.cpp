#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long int x[n+1];
	for(int i=0;i<n;i++)cin>>x[i];
	sort(x,x+n);


	for(int i=0;i<n;i++)if(i)x[i]+=x[i-1];

    
	for(int i=0;i<n;i++){
		if(i>=m)x[i]+=x[i-m];
		cout<<x[i]<<' ';
	}
}