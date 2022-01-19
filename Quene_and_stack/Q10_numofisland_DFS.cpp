#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size();r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    ans++;
                    dfs(grid, r,c);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        grid[r][c] = '0';
        if(r + 1 < m && grid[r+1][c] == '1')
            dfs(grid, r+1, c);
        if(r - 1>=0 && grid[r-1][c] == '1')
            dfs(grid, r-1, c);
        if(c + 1 < n && grid[r][c+1] == '1')
            dfs(grid, r, c+1);
        if(c - 1>= 0 && grid[r][c-1] == '1')
            dfs(grid, r, c-1);
    }
};