//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(int row , int col,vector<vector<char>> grid, vector<vector<int>>&vis){
      vis[row][col]=1;
      int m=grid.size();
      int n=grid[0].size();
      queue<pair<int,int>>q;
      q.push({row,col});
      while (!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int delrow=-1;delrow<=1;delrow++){
             for(int delcol=-1;delcol<=1;delcol++){
                 int nrow=row+delrow;
                 int ncol=col+delcol;
                 if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' &&!vis[nrow][ncol]){
                     q.push({nrow,ncol});
                     vis[nrow][ncol]=1;
                 }
             }
          }
      }
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                 bfs (i,j,grid,vis);
                  
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends