#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    int x[n],memo[n];
    memo[0] = 1;
    int maxa = 1;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=1;i<n;i++)
    { 
        if(x[i]>x[i-1])
        {
            memo[i] = memo[i-1]+1;
            maxa = max(maxa,memo[i]); 
        }
        else
        {
                memo[i] = 1;
                maxa = max(maxa,memo[i]);
        }
    }
    cout<<maxa<<endl;
}