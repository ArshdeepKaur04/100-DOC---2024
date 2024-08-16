/*
Question "Reverse a Linked List in Groups" on GfG
Given a linked list, the task is to reverse every k node (where k is an input to the function) in the linked list. 
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        //base call
        if (head == NULL) {
            return NULL;
        }
    
        //step-1: Reverse first k nodes
        node* next = NULL;
        node* curr = head;
        node* prev = NULL;
        int count = 0;
    
        while (curr != NULL && count < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
    
        //step-2: Recursive call
        if (next != NULL) {
            head -> next = reverseIt(next, k);
        }
    
        //step-3: Return the head of the reversed list
        return prev;
    }
};