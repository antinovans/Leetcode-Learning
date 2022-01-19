#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
            //swap first then increment lastNonZeroFoundAt;
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
        print(nums);
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