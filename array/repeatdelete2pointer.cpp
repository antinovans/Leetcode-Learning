#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> deleteDuplicate(vector<int>& arr) {
        int writePointer = 1;
        int numsTodelete = 0;
        for(int readPointer = 1; readPointer < arr.size(); readPointer++) 
        {
            // If the current element we're reading is *different* to the previous
            // element...
            if (arr[readPointer] != arr[readPointer - 1]) 
            {
                // Copy it into the next position at the front, tracked by writePointer.
                arr[writePointer] = arr[readPointer];
                // And we need to now increment writePointer, because the next element
                // should be written one space over.
                writePointer++;
            }
            else{numsTodelete++;}
        }
        for(int i = 0; i< numsTodelete; i++)
        {
            arr.pop_back();
        }
        print(arr);
        return arr;
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
    solution.deleteDuplicate(myarray);
}