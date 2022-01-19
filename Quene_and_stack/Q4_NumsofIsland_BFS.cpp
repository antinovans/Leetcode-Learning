#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while(!q.empty())
                    {
                        auto first = q.front();
                        q.pop();
                        for(auto dir: dirs)
                        {
                            auto x = first[0] + dir[0], y = first[1] + dir[1];
                            if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1') 
                            {
                                continue;
                            }
                            q.push({x, y});
                            grid[first[0] + dir[0]][first[1] + dir[1]] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution solu;
    vector<vector<char>> input = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << solu.numIslands(input);
}