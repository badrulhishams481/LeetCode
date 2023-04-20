/*
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {

        vector<int>::iterator it;
        string evenDigit = "";
        int counter = 0;

        for (it = nums.begin(); it != nums.end(); ++it)
        {
            evenDigit = to_string(*it);

            if (evenDigit.size() % 2 == 0 )
                ++counter;
        }
        if (counter)
            return counter;
        else
            return 0;
    }
};

int main ()
{
    std::vector<int> vect{555,901,482,1771}; 

    Solution sol;
    int even = sol.findNumbers(vect);

    if (even)
        std::cout<<"Number of even digit: "<<even<<std::endl;
    else
        std::cout<<"There is no even digit"<<std::endl;

    return 0;
}