#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) 
    {
        // Iterator used to store the position
        // of searched element
        std::vector<int>::iterator it;

        std::cout<<"Input value is: ";
        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            std::cout << *it; 
        }
        std::cout<<std::endl;

        //find the consecutive 1' value
        // element to be searched
        int counter = 0;
        int element = 1; 
        int maxConsecutive = 0;

        it = std::find(nums.begin(), nums.end(), element);
        if( it != nums.end())
        {
            while(true) 
            {
                if (*it == element)
                    counter++;
                else
                {
                    maxConsecutive = std::max(maxConsecutive,counter);
                    //clear counter
                    counter = 0;
                }
                
                maxConsecutive = std::max(maxConsecutive,counter);
                ++it;
                if (it == nums.end()) break;
            }
            return maxConsecutive;
        }
        else // if there is no value 1
        {
            return 0;
        }
    }
};

// Test code
int main() {
    
    std::vector<int> vect{1,1,0,1,1,1,0,1,1,1,1};
    //std::vector<int> vect{0,0,0};
        
    Solution sol;
    int maxCount = 0;
    maxCount = sol.findMaxConsecutiveOnes(vect);

    if ( maxCount != 0)
        std::cout<< "Max number of consecutive: " << maxCount<<std::endl;
    else
        std::cout<<"There is no consecutive 1 value" << std::endl;

    return 0;
}
