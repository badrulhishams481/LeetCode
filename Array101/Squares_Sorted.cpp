/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool ascending(int x, int y) { return x > y;};
bool descending(int x, int y) { return x < y;};

vector<int> selectionSort(vector<int>& array, int size, bool (*pFunc)(int,int))
{
    // Notes: 3 important index to determine smallest/biggest
    // startIdx - begin until (end-1)
    // bestIdx - smallest/biggest
    // currIdx - next iteration for comparing
    for(int startIdx{0}; startIdx < size-1; startIdx++)
    {
        int bestIdx{startIdx};
        for(int currIdx{startIdx+1}; currIdx<size; currIdx++)
        {
            if (pFunc(array[bestIdx],array[currIdx]))
                bestIdx = currIdx;
        }
        std::swap(array[startIdx],array[bestIdx]);
    }
    return array;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        cout<< "Squared Array: ";
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            int squaredVal = (*it)*(*it);
            nums.at(it-nums.begin()) = squaredVal;
            cout<<  nums.at(it-nums.begin())<<",";
        }
        cout<<endl;
        // sort in ascending order
        nums =  selectionSort(nums, nums.size(), ascending);

        return nums; 
    }
};

int main ()
{
    std::vector<int> outputVect;
    std::vector<int> vect{-7,-3,2,3,11};

    // print out original array
    std::cout<< "Original Array: ";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout<<  vect.at(i) << ",";
    }
    std::cout<< endl;

    Solution sol;
    outputVect = sol.sortedSquares(vect);

    std::cout<< "Sorted Array: ";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout<<  vect.at(i) << ",";
    }
    std::cout<< endl;

    return 0;
}