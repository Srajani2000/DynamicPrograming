#include <bits/stdc++.h>
using namespace std;
int count = 0;


void print(vector< long long> x)
{
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
 long long cms( long long a,vector< long long> &cache)
{

    if(a<0)
    {
        return 0;
    }
    else if(a==0 || a==1)
    {
        cache[a] = 1;
        return 1;
    }
    else 
    {
         long long x;
        if(cache[a-2]==-1 && cache[a-1]==-1)
        {
            x =   cms(a-2,cache)+cms(a-1,cache);
        }
        if(cache[a-2]==-1 && cache[a-1]!=-1)
        {
            x =   cms(a-2,cache)+cache[a-1];
        }
        if(cache[a-2]!=-1 && cache[a-1]==-1)
        {
            x =   cache[a-2]+cms(a-1,cache);
        }
        if(cache[a-2]!=-1 && cache[a-1]!=-1)
        {
            x = cache[a-2]+cache[a-1];
        }
        cache[a] = x;
        return x;
    }
}

int bottomup(int x)
{
    vector<long long> dp(x+1,0);
    dp[0]=1;
    dp[1] =1;
    // int m ;
    int i;
    for(i=2;i<x+1;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<endl;
    cout<<"The min number of way using bot up is :::::::::::: "<<dp[x]<<" ::::::::::::"<<endl; 
return dp[x];
}
int main()
{
    time_t start, end; 
    time(&start); 
    vector< long long> cache(51,-1);
    // print(cache);
    cout<<endl;
    cout<<"The min number of way is :::::::::::: "<<cms(50,cache)<<" ::::::::::::"<<endl;
    cout<<endl;
    cout<<"The min number of way using bot up is :::::::::::: "<<bottomup(50)<<" ::::::::::::"<<endl; 
    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
    return 0;
}