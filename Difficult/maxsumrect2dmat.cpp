#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}



int Kadens(vector<int> arr,int &endindex ,int &startindex)
{
    cout<<"::::::::::::::::::::::kadens algo starts::::::::::::::::::::::::"<<endl;
    int maximum = 0;
    vector<int> result(arr.size(),0);
    vector<int> subarrlength(arr.size(),0);
    cout<<"::::::::::::rowsum array:::::::::::::::"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }



    result[0] = arr[0];
    maximum = result[0];
    endindex = 0;
    for(int i=1;i<arr.size();i++)
    {
        result[i] = max(result[i-1]+arr[i],arr[i]);
        if(result[i]>maximum)
        {
            maximum = result[i];
            endindex = i;
        }
        if(result[i]!=arr[i])
        {
            subarrlength[i] = subarrlength[i-1]+1;
        }
    }
    // cout<<endl;
    // cout<<"maximum  "<<maximum<<endl;
    // cout<<"result"<<endl;
    // for(int i=0;i<result.size();i++)
    // {
    //     cout<<result[i]<<" ";
    // }

    // cout<<endl<<"::::::::::::::::: Length of subarray :::::::::::::::"<<endl;
    //  for(int i=0;i<subarrlength.size();i++)
    //  {
    //      cout<<subarrlength[i]<<"::";
    //  }

     
    startindex =endindex - subarrlength[endindex];
    cout<<endl;
    cout<<"resultant index "<<startindex<<"->"<<endindex<<endl;
 cout<<"::::::::::::::::::::::kadens algo ends::::::::::::::::::::::::"<<endl<<endl<<endl;

    return maximum;
 }

void CalculateSum(vector<vector<int>> matrix)
{
    int top,left,bottom,right;
    
    int result = -1000000000;
    for(int i=0;i<matrix[0].size();i++)
    {
        vector<int> rowsum(matrix.size(),0);
        for(int j=i;j<matrix[0].size();j++)
        {
             for(int k=0;k<matrix.size();k++)
             {
                 rowsum[k] = rowsum[k]+matrix[k][j];
             }

            int bot,to,answer;
               answer =  Kadens(rowsum,bot,to);
              if(result<answer)
              {
                  result = answer;
                  left = i;
                  right = j;
                  bottom = bot;
                  top = to;
              }
        }
    }


    cout<<"::::::::::answer:::::::::::::::"<<endl;
    cout<<left<<" :: "<<right<<" :: "<<top<<" :: "<<bottom<<endl;
    cout<<":::::maximum:::::"<<result<<endl;
}
 int main()
 {

     vector<vector<int>> arr{{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};
     CalculateSum(arr);
     
     return 0;

 }