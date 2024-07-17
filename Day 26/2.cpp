/*
Question "21. Merge Two Sorted Lists" on leetcode
You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The 
list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked
list.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};