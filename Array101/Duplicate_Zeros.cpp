/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<T> findItem(vector<T> const &v, int target)
{
    std::vector<T> vect;     
    auto it = v.begin();
    while((it = std::find_if(it,v.end(),[&](T const &e ){ return e == target;})) != v.end())
    {
        vect.push_back(std::distance(v.begin(),it));
        ++it;
    }
    return vect;
}


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int target = 0; // element to be find
        vector<int> vect;
        vect = findItem(arr,target);
        if (vect.size() != 0)
        {
            for(int i = 0; i<vect.size(); i++)
            {
                vect.at(i) += i;
                arr.insert(arr.begin()+vect.at(i),target); 
            }
        }
        arr.resize(arr.size()-vect.size());
    }
};

int main()
{
    std::vector<int> vect{5,2,0,3,0,4,5,0};

    //print original vector
    cout<<"Original Vector: ";
    for(auto &i : vect)
        cout << i << " ";
    cout<< endl;

    Solution * sol = new Solution();
    sol->duplicateZeros(vect);
    cout<<"Ajusted Vector: ";
    for(auto &i : vect)
        cout << i << " ";
    cout<< endl;
    
    
}