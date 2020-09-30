#include <bits/stdc++.h>
using namespace std;

    
int main() { 
    int m, n;
    cin >> m >> n;          
    int best = 0;    
    vector<vector<int>> R(n,vector<int>(-1,n));    
    for (int y = 0; y < m; y++) {
        int A[n];        
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;                
            if (c == '.') {
                A[j] = 1;
            } else {
                A[j] = 0;
            }
        }
        for (int a = 0; a < n; a++) { 
            bool visible = true;
            for (int b = a+1; b<n; b++) {
                // is b visible from a?
                if (A[b] == 0) {
                    visible = false;
                }
                if (A[a] == 1 && A[b] == 1) {
                    // the shape can extend thru this row too
                    if (R[a][b] >= 0) {
                        R[a][b] += 1;
                    }
                    if (visible && R[a][b] < 0) {
                        R[a][b] = 0;
                    }
                    if (visible && R[a][b] > 0) {
                        // consider the rect formed, by closing off the shape here.
                        int v = 2*R[a][b] + 2*(b-a);
                        if (v > best) {
                            best = v;
                        }
                    }
                }
                else {
                    R[a][b] = -1;
                }
            }
        }
    }
    if (best > 0) {        
        cout << best << endl;
    }
    else {
        cout <<  "impossible"<< endl;
    }    
    return best;
}