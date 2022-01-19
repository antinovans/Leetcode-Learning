#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> ans(temperatures.size(),0);
        std::stack<int> iterators;
        std::stack<int> temp;
        temp.push(temperatures[0]);
        iterators.push(0);
        if(temperatures.size() == 1){
            return ans;
        }
        for(int i = 1; i < temperatures.size(); i++){
            while(!temp.empty() && temperatures[i] > temp.top()){
                ans[iterators.top()] = i - iterators.top();
                iterators.pop();
                temp.pop();
            }
            temp.push(temperatures[i]);
            iterators.push(i);
        }
        return ans;
    }
};
void Print(std::vector<int> input){
    for(auto i:input){
        std::cout<< i<< " ";
    }
}
int main(){
    Solution solu;
    std::vector<int> temperatures = {73,71,75,71,69,72,76,73};
    Print(solu.dailyTemperatures(temperatures));
}