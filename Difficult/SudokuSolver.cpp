#include <bits/stdc++.h>
using namespace std;
    // vector<vector<int>> matrix{{0,4,5,0,1,7,0,2,0},
    //                          {0,2,0,3,0,0,1,0,0},
    //                          {0,0,1,0,0,0,3,7,4},
    //                          {0,0,9,0,0,3,5,8,0},
    //                          {1,0,2,5,8,0,4,3,7},
    //                          {0,0,8,7,0,6,9,0,0},
    //                          {0,1,0,4,7,2,0,0,5},
    //                          {0,0,7,0,0,0,2,0,0},
    //                          {0,5,4,6,0,0,0,0,1}};



//    vector<vector<int>> matrix{{5,3,0,0,7,0,0,0,0},
//                              {6,0,0,1,9,5,0,0,0},
//                              {0,9,8,0,0,0,0,6,0},
//                              {8,0,0,0,6,0,0,0,3},
//                              {4,0,0,8,0,3,0,0,1},
//                              {7,0,0,0,2,0,0,0,6},
//                              {0,6,0,0,0,0,2,8,0},
//                              {0,0,0,4,1,9,0,0,5},
//                              {0,0,0,0,8,0,0,7,9}};








   vector<vector<int>> matrix{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {6,0,0,1,9,5,0,0,0},
                             {0,9,8,0,0,0,0,6,0},
                             {8,0,0,0,6,0,0,0,3},
                             {4,0,0,8,0,3,0,0,1},
                             {7,0,0,0,2,0,0,0,6},
                             {0,6,0,0,0,0,2,8,0},
                             {0,0,0,4,1,9,0,0,5},
                             {0,0,0,0,8,0,0,7,9}};






void print(vector<vector<int>> matrix)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool IsPossible(int r,int c,int value)
{
    // in column 
    for(int i=0;i<9;i++)
    {
        //  cout<<" c "<<r<<" c "<<i<<"  "<<matrix[i][c]<<endl;
        if(matrix[i][c]==value)
        {
            // cout<<" c "<<i<<" c "<<c<<endl;
            return false;
        }
    }
    for(int i=0;i<9;i++)
    {
        // cout<<" r "<<r<<" r "<<i<<"  "<<matrix[r][i]<<endl;
        if(matrix[r][i] == value)
        {
            
            return false;
        }
    }
    int x,y;
    x = (r/3)*3;
    y = (c/3)*3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[x+i][y+j]==value)
            {
                return false;
            }
        }
    }
    return true;
}


bool Solve()
{
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++){
        if(matrix[i][j]==0){
            for(int k=1;k<=9;k++)
            {
              
                  if(IsPossible(i,j,k))
                  {
                      
                      matrix[i][j] = k;
                    //   cout<<endl;
                    //   print(matrix);
                    //   cout<<endl;
                      bool flag = Solve();
                      if(flag) return true;
                      else
                      matrix[i][j] = 0;
                  }
                   
            }
            return false;
            }
        }

    }
    return true;

}




int main()
{

    matrix.resize(9,vector<int>(9,0));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>matrix[i][j];
        }
    }
    print(matrix);
    Solve();
    print(matrix);
    // cout<<"is it possible "<<IsPossible(3,4,6,grid)<<endl;
    return 0;
}