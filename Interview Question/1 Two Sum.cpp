/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int>  bruteForce(vector<int>& nums, int target)
    {
        int size = nums.size();
        for(int i=0; i<size-1; i++)
        {
            for(int j=i; j<size; j++)
            {
                if((nums[i] + nums[j]) == target)
                    return {i,j};
            }
        }
        return {}; // No solution found
    }

    vector<int>  twoPassHashTable(vector<int>& nums, int target)
    {
        // store the data into hash table and find
        unordered_map<int,int> numMap;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            numMap[nums[i]] = i;
        }

        for(int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if(numMap.count(complement) && numMap[complement] != i)
                return {i,numMap[complement]};
        }
        return {};
    }

    vector<int>  onePassHashTable(vector<int>& nums, int target)
    {
        // find and store into hash table
        unordered_map<int,int> numMap;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if(numMap.count(complement))
                return {numMap[complement],i};
            numMap[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15}; 
    int target = 9;

    Solution sol;
    vector<int> answers;
    //answers = sol.bruteForce(nums, target);
    //answers = sol.onePassHashTable(nums, target);
    answers = sol.twoPassHashTable(nums, target);

    for(int& i : answers)
        cout<< i << ',';
}