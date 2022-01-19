// Input: arr = [0,3,2,1]
// Output: true
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool hasAscend = false;
        bool hasDescend = false;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            //cases to be discard
            if(arr[i] < arr[i + 1] && hasDescend)
            {
                return false;
            }
            if(arr[i] == arr[i+1])
            {
                return false;
            }
            if(arr[i] > arr[i + 1] && !hasAscend)
            {
                return false;
            }
            if(arr[i] < arr[i + 1] && !hasDescend)
            {
                hasAscend = true;
            }
            if(arr[i] > arr[i+1] && hasAscend)
            {
                hasDescend = true;
            }
        }
        if(hasAscend && hasDescend)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};