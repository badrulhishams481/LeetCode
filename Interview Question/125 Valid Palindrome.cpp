/*

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/

#include <iostream>
#include <string>


using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // step1: if a char is not an alpha we can simply ignore it and update out pointer to the next char (both pointers)
        // step2: then, we check by converting to the lower case, (numbers has no effect)
        // return true, if palindrome, else false
        int start = 0;
        int end = s.size()-1;

        while(start<=end)
        {
            // step1
            if(!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if(!isalnum(s[end]))
            {
                end--;
                continue;
            }

            // step2
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }

};

int main()
{
    string _string =  "A man, a plan, a canal: Panama";
    Solution sol;
    bool isPalindrome = sol.isPalindrome(_string);
    if(isPalindrome)
        cout<< "Original text: " <<_string <<" ,is a palindrome";
    else
        cout<< "Original text: " << _string << " ,is not a palindrome";

    return 0;
}