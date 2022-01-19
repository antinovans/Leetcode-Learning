#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int number = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(findDegitNumber(nums[i],0) % 2 == 0)
            {
                number++;
            }
        }
        return number;
    }
    int findDegitNumber(int num, int NoD)
    {
        if(num / 10 == 0)
        {
            return NoD+1;
        }
        else
        {
            NoD++;
            return findDegitNumber(num/10, NoD++);
        }
    }
};
int main()
{
    Solution solu;
    vector<int> myint = {1111,230,13000,20};
    cout << solu.findNumbers(myint);
}