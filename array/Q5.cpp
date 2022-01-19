/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t index1 = m;
        size_t index2 = n;
        for(index1; index1 < nums1.size(); index1 ++)
        {
            nums1.erase(nums1.begin() + index1);
            index1--;
        }
        for(index2; index2 < nums2.size(); index2 ++)
        {
            nums1.erase(nums1.begin() + index2);
            index2--;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        print(nums1);
    }
    void print(vector<int> &myarr)
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
    vector<int> myarray1 = {1,0,0,2,1,9,3};
    vector<int> myarray2 = {8,0,4};
    solution.merge(myarray1, 7 , myarray2 ,3);
}