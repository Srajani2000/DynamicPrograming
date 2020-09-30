#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}



int Kadens(vector<int> arr,int &maxindex ,int &sublength)
{
    int maximum = 0;
    vector<int> result(arr.size(),0);
    vector<int> subarrlength(arr.size(),0);
    result[0] = arr[0];
    maximum   = result[0];
    maxindex = 0;

    for(int i=1;i<arr.size();i++)
    {
        result[i] = max(result[i-1]+arr[i],arr[i]);
        if(result[i]>maximum)
        {
            maximum = result[i];
            maxindex = i;
        }
        if(result[i]!=arr[i])
        {
            subarrlength[i] = subarrlength[i-1]+1;
        }
    }
    sublength = subarrlength[maxindex];

    //  cout<<"::::::::::::::::: Length of subarray :::::::::::::::"<<endl;
    //  for(int i=0;i<subarrlength.size();i++)
    //  {
    //      cout<<subarrlength[i]<<"::";
    //  }

    //  cout<<endl;
    return maximum;
 }


 int main()
 {
     vector<int> array{-1,2,3-4,5,10};
     int maxindex,sublength;

     cout<<"max sum subarray ::::::::::::::: "<<Kadens(array,maxindex,sublength)<<" ::::::::::::::"<<endl;
     cout<<"max sum index :::::::::::::::::: "<<maxindex<<" ::::::::::::::::"<<endl;
     cout<<"max sum subarray length :::::::::::::::::: "<<sublength+1<<" ::::::::::::::::"<<endl;
     cout<<"sub array index ::::"<<maxindex-sublength<<"::::"<<maxindex<<"::::"<<endl;

  
     return 0;

 }