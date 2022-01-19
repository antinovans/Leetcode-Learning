// Input: arr = [17,18,5,4,6,1]
// Output: [18,6,6,6,1,-1]
// Explanation: 
// - index 0 --> the greatest element to the right of index 0 is index 1 (18).
// - index 1 --> the greatest element to the right of index 1 is index 4 (6).
// - index 2 --> the greatest element to the right of index 2 is index 4 (6).
// - index 3 --> the greatest element to the right of index 3 is index 4 (6).
// - index 4 --> the greatest element to the right of index 4 is index 5 (1).
// - index 5 --> there are no elements to the right of index 5, so we put -1.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        size_t i = 0;
        for(i; i < arr.size() - 1; i++)
        {
            size_t j = i+1;
            int largest = arr[j];
            while(j < arr.size())
            {
                if(arr[j] > largest)
                {
                    largest = arr[j];
                }
                j++;
            }
            arr[i] = largest;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
int main()
{
    Solution solution;
    vector<int> myarray = {17,18,5,4,6,1};
    solution.replaceElements(myarray);
}
