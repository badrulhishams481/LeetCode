#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) 
    {
        return 0;
    }
};

int main() {
    
    std::vector<int> vect{1,1,0,1,1,1,0,1,1,1,1};
    //std::vector<int> vect{0,0,0};
    // Iterator used to store the position
    // of searched element
    std::vector<int>::iterator it;

    std::cout<<"Input value is: ";
    for(auto it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << *it; 
    }
    std::cout<<std::endl;

    //find the consecutive 1' value
    // element to be searched
    int counter = 0;
    int element = 1; 
    int maxConsecutive = 0;

    it = std::find(vect.begin(), vect.end(), element);
    if( it != vect.end())
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
            if (it == vect.end()) break;
        }
        std::cout<< "Max number of consecutive: " << maxConsecutive<<std::endl;
    }
    else // if there is no value 1
    {
        std::cout<<"There is no consecutive 1 value" << std::endl;
    }

    return 0;
}
