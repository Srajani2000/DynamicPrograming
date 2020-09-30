#include <bits/stdc++.h>
using namespace std;



void print(vector<vector<int>> matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}





void LCIS(vector<int> Y,vector<int> X)
{
int n = X.size();
int m = Y.size();
int un = 0;
 vector<vector<int>> DP(n+1,vector<int>(m+1,0));
    int memorytheta = 0;
    int ele = 0;
    vector<int> elements;
	for(int i=1 ; i<=n ; i++){
		int theta = 0;
        int memory = memorytheta;
		for(int j=1 ; j<=m ; j++){
			DP[i][j] = DP[i-1][j];
			if(X[i-1] > Y[j-1]) theta = max(theta, DP[i-1][j]);
			if(X[i-1] == Y[j-1]){
                un = i-1;
                
                 DP[i][j] = theta + 1;
                   
                   if(memorytheta<=DP[i][j])
                   {
                       memorytheta = DP[i][j];
                   }
                 }
		}
        int strong = 1;
        if(memorytheta==memory+1)
        {
            ele = X[i-1];   
            elements.push_back(X[i-1]);
        }
        else if(memorytheta==memory && elements.size()!=0 && X[i-1]>ele && strong!=1)
        {
        
            elements.pop_back();
            elements.push_back(X[i-1]);
        }
     

	}
	for(int j=2 ; j<=m ; j++) DP[n][j] = max(DP[n][j], DP[n][j-1]);
    cout<<DP[n][m]<<endl;
    if(DP[n][m]!=1){
    for(int i=0;i<elements.size();i++)
    {
        cout<<elements[i]<<" ";
    }
    }
    else
    {
        cout<<X[un]<<endl;
    }
    cout<<endl;
    

    print(DP);
}


int main()
{


    vector<int> x,y;
    int xs;
    cin>>xs;
    while(xs--)
    {
        int m;
        cin>>m;
        x.push_back(m);
    }
    xs = 0;
    cin>>xs;
    while(xs--)
    {
        int m;
        cin>>m;
        y.push_back(m);
    }

 LCIS(x,y);



    // vector<int> x{4 ,2, 4, 3, 10, 3, 6};
    // vector<int> y{7 ,5, 2, 3, 0, 1, 6, 1, 4};
            

    // vector<int> x{7 ,4, 4, 5, 0, 6, 5, 4, 10};
    // vector<int> y{5, 2, 10, 9};
    // vector<int> x{7 ,0, 1, 2, 6, 0, 10, 3, 5};
    // vector<int> y{8 ,4, 0, 3};
//   vector<int> x{37 ,49 ,24};
//     vector<int> y{33 ,5, 70};
    // vector<int> x{7, 10, 1, 2, 1, 7, 1, 5, 9, 9};
    // vector<int> y{6 ,2 ,5 ,6 ,7, 7, 5 ,5 ,2};
    // vector<int> x {25, 29, 37, 207, 122, 189, 118, 42, 54, 95, 154, 160, 162, 225, 228, 237, 248};
    // vector<int> y{25, 29, 248, 37, 147, 209, 42, 54, 255, 95, 154, 160, 162, 225, 228, 237, 73, 248, 10};
   
}
