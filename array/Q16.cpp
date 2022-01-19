// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(abs(nums[i])>=1)
            {
                nums[abs(nums[i]) - 1] = -(abs(nums[abs(nums[i]) - 1]));
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == abs(nums[i]))
            {
                ans.push_back(i+1);
            }
        }
        print(ans);
        return ans;
    }
    void print(vector<int> myarr)
    {
        for(int i = 0; i < myarr.size(); i++)
        {
            cout << myarr[i] << " ";
        }
    }
};

int main()
{
    Solution solution;
    vector<int> myarray = {4,3,-2,-7,8,2,3,1};
    solution.findDisappearedNumbers(myarray);
}