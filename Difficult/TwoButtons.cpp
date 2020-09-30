#include <bits/stdc++.h>
using namespace std;
int dp[100005] = {0};

int TwoButtons(int n,int mvalue,int segment,int nvalue)
{
    cout<<"n "<<n<<endl;
    // return 0;
    if(n>mvalue || n<=1 || n==nvalue)
    {
        cout<<"comes inside "<<n<<endl;
        return INT_MAX;
    }
    else if(n==mvalue)
    {
        // dp[n] = segment+1; 
        return segment+1;
    }
    else 
    {
       int x =  min(TwoButtons(n-1,mvalue,segment+1,nvalue),TwoButtons(n*2,mvalue,segment+1,nvalue));
    //    dp[n] =  x;
       return x;
    }
}
int main()
{
    int y1 = TwoButtons(4-1,6,0,4);
    int y2 = TwoButtons(4*2,6,0,4);
    cout<<"Min size "<<min(y1,y2)<<endl;
}