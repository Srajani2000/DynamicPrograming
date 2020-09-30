#include <bits/stdc++.h>
using namespace std;


bool findclock(vector<int> arr,int angle,int index,char x)
{
    // cout<<"angle "<<angle<<" index "<<index<<" " <<x<<endl;
    if(angle==0 && index==arr.size()-1)
     return true;
     else if(index==arr.size()-1) return false;
     else
     {
            bool x = findclock(arr,(angle+arr[index+1])%360,index+1,'C'); //clock wise
            bool y = findclock(arr,((360+angle)-arr[index+1])%360,index+1,'A'); // anti clock wise
            return x||y;
      }
}


int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);  
    for(int i=0;i<n;i++) cin>>arr[i];
    bool x = findclock(arr,arr[0],0,'C');
    bool y = findclock(arr,360-arr[0],0,'A');
    if(x||y) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}