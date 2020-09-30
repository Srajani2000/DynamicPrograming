#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> memo;
unsigned long long G(int s)
{
    if(s<=1){
        memo[s] = 1;
        return 1;
        }

    else
    {
        unsigned long long result = 0;
        unsigned long long  G1,G2;
        for(int i=1;i<=s;i++)
        {
            if((memo[i-1]!=0))
            {
                G1 = memo[i-1];
            }
            else{
                G1 = G(i-1);
                memo[i-1] = G1;
            }
            if((memo[s-i]!=0))
            {
                G2 = memo[s-i];
            }
            else 
            {
                G2 = G(s-i);
                memo[s-i] = G2;
            }
            result = result+G1*G2;
        }
        return result;
    }
    
}

int main()
{
    int n = 10;
    memo.resize(n,0);
    cout<<"The nth Catalan Number  :::::::::::::: "<<G(70)<<" :::::::::::::"<<endl;
    return 0;
}