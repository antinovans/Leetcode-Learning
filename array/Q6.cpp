/*Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(size_t i = 0; i< nums.size(); i++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
int main()
{
}