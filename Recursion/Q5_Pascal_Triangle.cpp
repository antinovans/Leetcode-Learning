#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output;
        if(rowIndex < 0){
            return {};
        }
        if(rowIndex == 0){
            return {1};
        }
        for(int col = 0; col < rowIndex + 1; col++){
            output.push_back(helper(rowIndex,col));
        }
        return output;
    }
    int helper(int row, int column){
        if(column == 0 || column == row){
            return 1;
        }
        else{
            if(coordinateMap.find({row,column}) != coordinateMap.end()){
                return coordinateMap[{row,column}];
            }
            int ans = helper(row - 1, column - 1) + helper(row - 1, column);
            coordinateMap.insert({{row,column},ans});
            return ans;
        }
    }
private:
    map<vector<int>, int> coordinateMap;
};
int main(){
    Solution solu;
    vector<int> ans = solu.getRow(3);
    for(auto i:ans){
        cout << i << " ";
    }
}