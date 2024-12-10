/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    //Definition for singly-linked list.
    struct ListNode
    {
    public:
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int _val): val(_val), next(nullptr) {}
        ListNode(int _val, ListNode* _next): val(_val), next(_next) {}
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        if(ptr1==nullptr)
            return list2;

        if(ptr2==nullptr)
            return list1;

        if(ptr1->val < ptr2->val)
        {
            ptr1->next = mergeTwoLists(ptr1->next,ptr2);
            return ptr1;
        }
        else
        {
            ptr2->next = mergeTwoLists(ptr2->next,ptr1);
            return ptr2;
        }
    }
};

int main()
{
//Input: list1 = [1,2,4], list2 = [1,3,4]

    Solution::ListNode nodeA1(1);
    Solution::ListNode nodeA2(2);
    Solution::ListNode nodeA3(4);

    nodeA1.next = &nodeA2;
    nodeA2.next = &nodeA3;

    Solution::ListNode nodeB1;
    Solution::ListNode nodeB2;
    Solution::ListNode nodeB3;

    nodeB1.next = &nodeB2;
    nodeB1.val = 1;
    nodeB2.next = &nodeB3;
    nodeB2.val = 3;
    nodeB3.val = 4;

    Solution sol;
    Solution::ListNode* listNode = sol.mergeTwoLists(&nodeA1, &nodeB1);

    cout<<endl;
    while(listNode != nullptr)
    {
        cout<<listNode->val<<" ";
        if(listNode->next !=  nullptr)
            listNode = listNode->next;
        else break;
    }
}