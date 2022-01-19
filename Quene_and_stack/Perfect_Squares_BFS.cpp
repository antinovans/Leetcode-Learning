#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> squares;
        for(int i = 0; i * i <= n ;i++){
            squares.push_back(i*i);
        }
        int layers = 1;
        std::unordered_set<int> q, remainder;
        q.insert(n);
        while(q.size() > 0){
            remainder.clear();
            for(auto element : q){
                for(auto square : squares){
                    if(element == square){
                        return layers;
                    }
                    else if(square > element){
                        break;
                    }
                    else{
                        remainder.insert(element - square);
                    }
                }
            }
            std::swap(q,remainder);
            layers++;
        }
        return -1;
    }
};