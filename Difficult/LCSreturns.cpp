#include <bits/stdc++.h>
using namespace std;


int maximum(int a, int b)  
{  
    return (a > b)? a : b;  
}


void print(vector<vector<int>> matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


int LCSreturn(string a,string b)
{
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
    int max = 1;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i=2;i<=b.size();i++)
    {    if( b[i-1]!=b[i-2]) max++;
         dp[0][i]= max;
    }
    for(int i=1;i<a.size()+1;i++)
    {
        for(int j=1;j<b.size()+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = maximum(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    print(dp);
    return dp[a.size()][b.size()];
}
int main()
{
    cout<< "  max "<<LCSreturn("aa","baaa");
    return 0;
}