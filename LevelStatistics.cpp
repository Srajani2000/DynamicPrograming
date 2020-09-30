#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int number;
        cin>>number;
        int size = number;
        int plays;
        int clears;
        int playcount,clearcount;
        vector<vector<int>> placle(number,vector<int>(2,0));
        int count = 0;
        while(number--)
        {
        cin>>plays;
        cin>>clears;
        placle[count][0] = plays;
        placle[count][1] = clears;
        count++;
        }
        if(number==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool flag = true;
        playcount = placle[0][0];
        clearcount = placle[0][1];
        for(int i=1;i<size;i++)
        {
            if(((placle[i][0]-playcount)<0) || ((placle[i][1]-clearcount)<0))
            {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            else if(((placle[i][0]-playcount)==0)&&((placle[i][1]-clearcount)>0))
            {
                cout<<"NO"<<endl;
                flag = false;
                break;      
            }
            playcount = placle[i][0];
            clearcount = placle[i][1];
        }
        if(flag)
        cout<<"YES"<<endl;
    }
    return 0;
}