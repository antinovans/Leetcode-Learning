#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longestSequence = 0;
        int numsOfZero = 0;
        for (int lastZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            int posibleDistance = cur - lastZeroFoundAt + 1;
            if(nums[cur] == 0 && numsOfZero < 2){
                numsOfZero++;
            }
            if(nums[cur] == 0 && numsOfZero == 2){
                posibleDistance -= 1;
                while(numsOfZero>1){
                    lastZeroFoundAt++;
                    if(nums[lastZeroFoundAt - 1] == 0)
                    {
                        numsOfZero--;
                    }
                }
            }
            longestSequence = max(longestSequence, posibleDistance);
        }
        return longestSequence;
    }
};
int main()
{
    Solution solution;
    vector<int> myarray = {};
    cout << solution.findMaxConsecutiveOnes(myarray);
}