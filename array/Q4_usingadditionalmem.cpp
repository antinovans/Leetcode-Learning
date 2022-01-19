/*Duplicate Zeros*/
/*Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        vector<int> newArr;
        for(int i = 0; i < arr.size(); i++)
        {
            if(newArr.size() == arr.size())
            {
                arr = newArr;
                print(arr);
                return;
            }
            newArr.push_back(arr[i]);  
            if(arr[i] == 0 && newArr.size() < arr.size())
            {
                newArr.push_back(0);
            }
        }
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
    vector<int> myarray = {1,0,0,1,1,1,1};
    solution.duplicateZeros(myarray);
}