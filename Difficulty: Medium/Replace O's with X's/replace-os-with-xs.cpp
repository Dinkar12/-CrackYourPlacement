//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int n , int m ,int row, int col ,vector<vector<char>> &mat, vector<vector<int>>&vis){
        vis[row][col] = 1;
        
        int delrow[] = {-1, 0 , 1 ,0};
        int delcol[] = {0 ,1, 0 ,-1};
        //check on four directions
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow <n && ncol>=0 && ncol <m &&
            vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O'
            ){
                dfs(n,m,nrow, ncol, mat, vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m , 0));
        
        for(int j=0; j<m; j++){
            // top horiz row
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(n,m ,0, j , mat, vis);
            }
            //bottom row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n,m,n-1, j , mat, vis);
            }
        }
        
        for(int i=0; i<n; i++){
            // left row
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(n,m,i,0, mat, vis);
            }// right row
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(n,m,i,m-1,mat,vis);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends