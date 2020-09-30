#include<bits/stdc++.h> 
using namespace std; 


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int x[n];
        for(int i=0;i<n;i++) cin>>x[i];
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int j=0;j<n-1;j++) dp[j][j+1] = (x[j]==x[j+1])?2:1;
        int ans = 0;
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k = i+j-1;
                if(x[j]==x[k]) dp[j][k] = dp[j+1][k-1]+2;
                else dp[j][k] = max(dp[j][k-1],dp[j+1][k]);
                if(ans<dp[j][k]) ans = dp[j][k];
            }
        }

        (ans>=3)?(cout<<"YES"<<endl):(cout<<"NO"<<endl);

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
}