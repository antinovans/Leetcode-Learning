// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        for(int i; i < nums.size() - 1; i++)
            {
                if(nums[i] == 0)
                {
                    int j = i+1;
                    while(j<nums.size())
                    {
                        if(nums[j] != 0)
                        {
                            nums[i] = nums[j];
                            nums[j] = 0;
                            break;
                        }
                        j++;
                    }
                }
            }
        print(nums);
        return nums;
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
    vector<int> myarray = {0,0,1,1,1,2,2,3,3,4};
    solution.moveZeroes(myarray);
}