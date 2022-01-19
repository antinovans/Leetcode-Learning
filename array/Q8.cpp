// Input: arr = [10,2,5,3]
// Output: true
// Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        size_t i =0;
        for(i; i < arr.size(); i++)
        {
            for(size_t j = i+1; j < arr.size();j++)
            {
                if(arr[i] == 2*arr[j] || arr[j]==2*arr[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution solution;
    vector<int> myarray = {-20,8,-6,-14,0,-19,14,4};
    solution.checkIfExist(myarray);
}