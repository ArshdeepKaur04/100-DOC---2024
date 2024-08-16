/*
Question "Palindrome Linked List" on GfG
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.
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
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head -> next; 
    
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
    
        return slow;
    }
    
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
    
        while (curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
    
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (head -> next == NULL) {
            return true;
        }
        
        Node* mid = getMid(head);
        Node* temp = mid -> next;
        mid -> next = reverseList(temp);
    
        Node* head1 = head;
        Node* head2 = mid -> next;
    
        while (head2 != NULL) {
            if ( (head1 -> data) != (head2 -> data) ) {
                return false;
            }
    
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        temp = mid -> next;
        mid -> next = reverseList(temp);
        return true;
    }
};