#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(0, s.size() - 1, s);
    }
    void helper(int frontIndex, int backIndex, vector<char>& input){
        if(frontIndex >= backIndex)
            return;
        swap(input[frontIndex],input[backIndex]);
        helper(frontIndex +1, backIndex-1,input);
    }
};
int main(){
    vector<char> a = {'a','b','c','d','e'};
    Solution solu;
    solu.reverseString(a);
    for(auto i : a){
        cout << i<<" ";
    }
}