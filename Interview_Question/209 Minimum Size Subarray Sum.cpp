/*

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
		
        int i,j,sum, minlen=n+1;
        i=j=sum=0;
		
        while(j<n){
            sum+=a[j]; // acquiring rear element
            cout<<sum<<endl;
			
            while(i<=j && sum>=target){
                minlen = min(minlen,j-i+1);
                sum-=a[i]; // releasing front element
                i++;
            }
            j++;
        }
        return (minlen==n+1 ? 0:minlen);
    }
};

int main()
{
    int target = 4;
    vector<int> nums = {2,1,1,1,2};
    int minLen = 0;

    Solution sol;
    minLen = sol.minSubArrayLen(target, nums);
    cout<< "Minimal length: " << minLen;

    return 0;
}