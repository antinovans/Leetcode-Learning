// Input: nums = [3,2,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2.
// The third distinct maximum is 1.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        if(nums.size()>=3)
        {
            return nums[nums.size()-3];
        }
        else{
            return nums[nums.size()-1];
        }
    }
};
int main()
{
    Solution solution;
    vector<int> myarray = {2,3};
    cout << solution.thirdMax(myarray);
}