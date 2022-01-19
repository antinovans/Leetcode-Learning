// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > 0)
            {
                if(nums[i] == nums[i - i])
                {
                    nums.erase(nums.begin() + 1);
                    i--;
                }
            }
        }
        return nums.size();
    }
};