/*

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end(),std::greater<int>());
        return nums[k-1];
    }

    //using priority_queue
    int findLthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_.top()) {
                min_.pop();
                min_.push(nums[i]);
            }
        }
        
        return min_.top();
    }
};

int main()
{
    std::vector<int> _array {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution sol;
    int answer = sol.findKthLargest(_array, k);
    int answer2 = sol.findLthLargest(_array,k);
    cout<<"The answer is: "<<answer<<endl;
    cout<<"The second answer is: "<<answer2<<endl;
}