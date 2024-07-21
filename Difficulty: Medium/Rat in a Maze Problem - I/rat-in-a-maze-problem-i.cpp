//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int dx[4] =  {-1,1,0,0};
    int dy[4] =  {0,0,-1,1};
    char mov[4] = {'U','D','L','R'};
    bool isPossible(vector<vector<int>>&mat,vector<vector<bool>>&visited,int i,int j, int n){
        if(((i >= 0 && i < n) && (j >= 0 && j < n)) && (mat[i][j] == 1) && (visited[i][j] == false)){
              return true;
          }
          return false;
           
      }
      void solve(vector<vector<int>>&mat,vector<vector<bool>>&visited,int srcx, int srcy,
      vector<string>&path,string output,int n){
          if(srcx == n -1 && srcy == n -1){
              path.push_back(output);
              return;
          }
          for(int i = 0; i < 4; i++){
              int nsrcx = srcx + dx[i];
              int nsrcy = srcy + dy[i];
              if(isPossible(mat,visited,nsrcx, nsrcy,n)){
                  visited[nsrcx][nsrcy] = true;
                  solve(mat,visited,nsrcx,nsrcy,path,output+mov[i],n);
                  //backtracking
                  visited[nsrcx][nsrcy] = false;
              }
          }
          
      }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>path;
        if(mat[0][0] == 0)
         return path;
        
        int n = mat.size();
        int srcx = 0, srcy = 0;
        string output = "";
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[srcx][srcy] = true;
        solve(mat,visited,srcx,srcy,path,output,n);
        
        return path;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends