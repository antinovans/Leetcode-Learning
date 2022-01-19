// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int lastOddFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur]%2 == 0) {
            //swap first then increment lastOddFoundAt;
                swap(nums[lastOddFoundAt++], nums[cur]);
            }
        }
        return nums;
    }
};