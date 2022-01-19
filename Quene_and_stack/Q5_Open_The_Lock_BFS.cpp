#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int steps = 0;
        unordered_set<string> dump(deadends.begin(), deadends.end());
        if(dump.count(target)>0){
            return -1;
        }
        unordered_set<string> q1, q2, nextq;
        string init = "0000";
        if(dump.count(init)>0){
            return -1;
        }
        if(init == target){
            return 0;
        }
        q1.insert(init);
        q2.insert(target);
        while(!q1.empty() && !q2.empty()){
            if(q1.size() > q2.size()){
                swap(q1,q2);
            }
            nextq.clear();
            for(auto i : q1){
                vector<string> neighbours = GetNeighbour(i);
                for(auto neighbour : neighbours){
                    if(q2.find(neighbour) != q2.end()){
                        return ++steps;
                    }
                    if(dump.find(neighbour) != dump.end()){
                        continue;
                    }
                    if(dump.find(neighbour) == dump.end()){
                        nextq.insert(neighbour);
                        dump.insert(neighbour);
                    }
                }
            }
            swap(q1,nextq);
            steps++;
        }
        return -1;
    }
    vector<string> GetNeighbour(string input){
        vector<string> neighbours;
        for(int i = 0; i < 4; i++){
            string temp = input;
            //traverse every digit incremented by one (9->0)
            temp[i] = (input[i] - '0' + 1) % 10 +'0';
            neighbours.push_back(temp);
            //traverse every digit reduced by one (0->9)
            temp[i] = (input[i] - '0' - 1 + 10) % 10 +'0';
            neighbours.push_back(temp);
        }
        return neighbours;
    }
};

int main()
{
    Solution solu;
    vector<string> a = {"0201","0101","0102","1212","2002"};
    cout << solu.openLock(a,"0202");
}