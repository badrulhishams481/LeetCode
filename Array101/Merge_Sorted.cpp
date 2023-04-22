/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/


#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int j=0; j<n; j++)
        {
            static int i = m;
            nums1[i]=nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main ()
{
    vector<int> vect1{1,2,3,0,0,0}; 
    vector<int> vect2{2,5,6};

    // print out the vect
    cout<< "Original Vector 1 is : ";
    for(int& i : vect1)
        cout<<i<<" ";
    cout<<endl;

    // print out the vect
    cout<< "Original Vector 2 is : ";
    for(int& i : vect2)
        cout<<i<<" ";
    cout<<endl;

    Solution sol;
    int vect1Size = vect1.size() - 3; // hardcode, remove zero
    sol.merge(vect1,vect1Size,vect2,vect2.size());

    // print out the vect
    cout<< "Merged Vector is : ";
    for(int& i : vect1)
        cout<<i<<" ";
    cout<<endl;

}