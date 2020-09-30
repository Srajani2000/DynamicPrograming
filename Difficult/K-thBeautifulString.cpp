#include <bits/stdc++.h>
using namespace std;

void computeindex(long long n_term,long long &i,long long &j)
{
    long long block1,block2;
    block1 = ((-1.0/2.0) + (double)sqrt(1+8*n_term)/2.0);
    block2 =  ((-1.0/2.0) - (double)sqrt(1+8*n_term)/2.0);
    // cout<<block1<<" "<<block2<<endl;
    long long block = max(block1,block2);
    long long first = (block*(block+1))/2;
    // int second = first+block;
     i = n_term-first;
     j = block;
    // cout<<"I J "<<i<<" "<<j<<endl;
    
}


int main()
{
    long long test,n,k,i,j;
    cin>>test;
    while(test--)
    {
    cin>>n>>k;
    string x = "";
    for(int i=0;i<n;i++)
    {
        x = x+"a";
    }
    computeindex(k-1,i,j);
    x[n-1-i] = 'b';
    x[n-2-j] = 'b';
    cout<<x<<endl;
    }

}