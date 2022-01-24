#include <unordered_map>
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        if(map.find(n)!= map.end()){
            return map[n];
        }
        int sum = climbStairs(n-1) + climbStairs(n-2);
        map[n] = sum;
        return sum;

    }
private:
    std::unordered_map<int, int> map;
};