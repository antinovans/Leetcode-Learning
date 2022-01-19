#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        int length = arr.size();
        //moving upwards
        while(i+1 < length && arr[i] < arr[i + 1])
        {
            i++;
        }
        //discards cases
        if(i == 0 || i == length - 1)
        {
            return false;
        }
        //moving upwards
        while(i+1 < arr.size() && arr[i] > arr[i + 1])
        {
            i++;
        }
        return i== length - 1;
    }
};