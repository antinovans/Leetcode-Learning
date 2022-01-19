// Input: heights = [1,1,4,2,1,3]
// Output: 3
// Explanation: 
// heights:  [1,1,4,2,1,3]
// expected: [1,1,1,2,3,4]
// Indices 2, 4, and 5 do not match.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> originalArr = heights;
        //sort ascending 
        for (int cur = 0; cur < heights.size() - 1; cur++) {
            int rightSide = cur + 1;
            int minIndex = cur + 1;
            int min = heights[cur];
            for(rightSide; rightSide < heights.size(); rightSide++)
            {
                if(heights[rightSide]<min)
                {
                    min = heights[rightSide];
                    minIndex = rightSide;
                }
            }
            if(min != heights[cur])
            {
                swap(heights[cur], heights[minIndex]);
            }
        }

        //checking differences
        int diff = 0;
        for(int i=0; i < originalArr.size(); i++)
        {
            if(originalArr[i] != heights[i])
            {
                diff++;
            }
        }
        return diff;
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
    vector<int> myarray = {1,1,4,2,1,3};
    solution.heightChecker(myarray);
}