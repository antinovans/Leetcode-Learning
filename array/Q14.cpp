// Input: nums = [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pureOnes = 0;
        int consecutives = 0;
        for (int lastZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] == 0) {
                pureOnes = 0;
                lastZeroFoundAt = cur;
                int leftSide = 0;
                int rightSide = 0;
                //leftside consecutive 1s
                for(int i = lastZeroFoundAt - 1; i >=0 ; i--)
                {
                    if(nums[i] == 1)
                    {
                        leftSide++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                //rightside consecutive 1s
                for(int j = lastZeroFoundAt + 1; j<nums.size() ; j++)
                {
                    if(nums[j] == 1)
                    {
                        rightSide++;
                    }
                    else
                    {
                        break;
                    }
                }
                consecutives = max(consecutives, leftSide+rightSide+1);
            }
            else
            {
                pureOnes++;
                consecutives = max(consecutives, pureOnes);
            }
        }
        return consecutives;
    }
    
};
int main()
{
    Solution solution;
    vector<int> myarray = {0,0,1,1,1,0,1,1,1,0};
    cout << solution.findMaxConsecutiveOnes(myarray);
}