#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> myset;
        for (int i=0; i<nums.size(); i++) myset.insert(nums[i]);
        if(myset.size() < 3)
        {
            auto it = myset.end();
            it--;
            return *it;
        }
        else
        {
            while(myset.size() >3)
            {
                myset.erase(myset.begin());
            }
            return *myset.begin();
        }
    }
    void printSet(set<int> input)
    {
        for (auto it=input.begin(); it != input.end(); ++it) 
            cout << ' ' << *it; 
    }
};
int main () {
    vector<int> myints = {50};
    Solution solution;
    cout << solution.thirdMax(myints);
    return 0;
}