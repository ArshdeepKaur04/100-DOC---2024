/*
Question "Sort a linked list of 0s, 1s and 2s" on GfG
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s 
linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle
of 0s and 2s.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        Node* temp = head;
    
        while (temp != NULL) {
            if (temp->data == 0) {
                zeroCount++;
            }
            else if (temp->data == 1) {
                oneCount++;
            }
            else if (temp->data == 2) {
                twoCount++;
            }
            temp = temp -> next;
        }
    
        temp = head;
        while (temp != NULL) {
            while (zeroCount) {
                temp->data = 0;
                temp = temp->next;
                zeroCount--;
            }
            while(oneCount) {
                temp->data = 1;
                temp = temp->next;
                oneCount--;
            }
            while(twoCount) {
                temp->data = 2;
                temp = temp->next;
                twoCount--;
            }
        }
    
        return head;
    }
};