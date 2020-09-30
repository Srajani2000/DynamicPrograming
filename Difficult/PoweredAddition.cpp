#include <bits/stdc++.h>
using namespace std;

int Powered(vector<int> arr)
{
    int maxi = arr[0];
    int x = 0;
    int T= 0;
    int logp = 0;
    for(int i=1;i<arr.size();i++)
    {
        
      if(arr[i]<arr[i-1])
      {
          arr[i] = arr[i]+logp;
          int factor = arr[i]-arr[i-1];

          int logx  = log2(factor);
          T = T+logx;
          arr[i] = arr[i]+pow(2,logx-1);
      }
    }
}

int main()
{
    vector<int> x{1,7,6,5};
    Powered(x);
}