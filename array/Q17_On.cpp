#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        while(!(i > j))
        {
            if(abs(nums[i]) > abs(nums[j])){
                result[j - i] = nums[i] * nums[i];
                i++;
            }
            else{
                result[j - i] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
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
    vector<int> myarray = {-7,-6,1,2};
    solution.sortedSquares(myarray);
}
