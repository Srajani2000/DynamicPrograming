#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> umap; 


int max(int a, int b)  
{  
    return (a > b)? a : b;  
}


int KnapSack(int item[],int weight[],int item_m,int weight_n)
{
   int memo[item_m][weight_n];
   for(int i=0;i<weight_n;i++)
   {    
       memo[0][i] = weight[0]<=i?umap.find(weight[0])->second:0;
   }

//    for(int i=0;i<weight_n;i++)
//    {
     
//            cout<<memo[0][i]<<" ";  
//    }
//    cout<<endl;
    int maxweight = 0;
   for(int i=1;i<item_m;i++)
   {
       for(int j=0;j<weight_n;j++)
       {
           if(weight[i]<=j){
           memo[i][j] = max(memo[i-1][j],memo[i-1][j-weight[i]]+item[i]);
           }
           else{
               memo[i][j] = memo[i-1][j];
           }
           if(maxweight<memo[i][j])
           {
               maxweight = memo[i][j];
           }
    
       }
   }
   for(int i=0;i<item_m;i++)
   {
       for(int j=0;j<weight_n;j++)
       {
        cout<<memo[i][j]<<" ";
       }
       cout<<endl;
   }
   return maxweight;
}


int main()
{
    int weight[] =  {5,3,4,2};
    int item[] = {60,50,70,30};
    for(int i=0;i<4;i++)
    {
        umap.insert({weight[i],item[i]});
    }
    int x = KnapSack(item,weight,4,6);
    cout<<"The final value is :::::::::::::: "<<x<<" ::::::::::::::"<<endl;
    return 0;

}