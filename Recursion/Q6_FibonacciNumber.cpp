#include <unordered_map>
#include <iostream>
class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        if(map.find(n) != map.end()){
            return map[n];
        }
        auto sum = fib(n-1)+fib(n-2);
        map.insert({n,sum});
        return sum;
    }
private:
    std::unordered_map<int,int> map;
};
int main(){
    Solution solu;
    std::cout << solu.fib(9);
}