#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> x)
{
    cout<<endl;
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x[0].size();j++)
        {
            cout<<x[i][j]<<" ";
        }
       
    cout<<endl;
    }
   cout<<endl; 
}
long UniqWayMake(vector<int> coins, int amount)
{
  
    // cout<<endl;
     long size = coins.size();
     long dp[size+1][amount+1] = {0}; 
    for(int i=0;i<size+1;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<size+1;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=1;i<size+1;i++)
    {
        for(int j=1;j<amount+1;j++)
        {
         long lower = 0;
            if((j-coins[i-1])>=0)
            {
               lower = dp[i][j-coins[i-1]];
            }
            dp[i][j] = lower+dp[i-1][j];
        }
    }
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[size][amount];

}

void print2( int row, int col,int a)
{

}



int main()
{
    vector<int> coins{1,2 ,3};
    //vector<int> coins{8, 47, 13, 24, 25, 31, 32, 35, 3, 19, 40, 48, 1, 4, 17, 38, 22, 30, 33, 15, 44, 46, 36, 9, 20, 49};
    // vector<int> coins{49, 9, 40, 17, 46, 24, 42, 26, 43, 41, 35, 1, 47, 28, 20, 38, 2, 44, 32, 22, 18, 45, 25};
    // vector<int> coins{48, 6, 34, 50, 49, 36, 30, 35, 40, 41, 17, 43, 39, 13, 4, 20, 19, 2, 46, 7, 38, 33, 28, 18, 21,};
    // vector<int> coins{44, 5, 9, 39, 6, 25, 3, 28,16, 19, 4, 49, 40, 22, 2, 12, 45, 33, 23, 42, 34, 15, 46, 26, 13, 31, 8,};
    // sort(coins.begin(), coins.end());
    int size = coins.size();
    int amount = 4;
    vector<vector<int>> dp(size+1,vector<int>(amount+1,0));
    cout<<"Max unique way to make change is ::::::::::: "<<UniqWayMake(coins,amount)<<" :::::::::::::"<<endl<<endl;
    cout<<":::::::::::::::::: DPTABLE ::::::::::::::::::"<<endl;
    // print(dp);

}