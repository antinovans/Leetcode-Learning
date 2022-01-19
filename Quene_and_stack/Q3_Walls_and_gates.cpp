#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<vector<int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (rooms[i][j] == 0) {
          q.push({i, j});
        }
      }
    }
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
      auto first = q.front();
      q.pop();
      for (auto dir : dirs) {
        auto x = first[0] + dir[0], y = first[1] + dir[1];
        if (x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] != INT_MAX) {
          continue;
        }
        rooms[x][y] = rooms[first[0]][first[1]] + 1;
        q.push({x, y});
      }
    }
  }
};
int main()
{
    Solution solu;
    vector<vector<int>> a = {{2147483647,0,2147483647,2147483647,0,2147483647,-1,2147483647}};
    solu.wallsAndGates(a);
}