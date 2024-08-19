/*
Question "Add Number Linked Lists" on GfG
Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list
that represents the sum of these two numbers.
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
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
    
    void insertNode(Node* &head, Node* &tail, int data) {
        //creating a new node
        Node* temp = new Node(data);
    
        //empty list
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        
        else {
            tail -> next = temp;
            tail = tail->next;
        }
    }
    
    Node* add(Node* first, Node* second) {
        int sum = 0;
        int carry = 0;
        int digit = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
    
        while (first != NULL || second != NULL || carry != 0) {
            int val1 = 0;
            if (first != NULL) {
                val1 = first -> data;
            }
    
            int val2 = 0;
            if (second != NULL) {
                val2 = second -> data;
            }
            
            sum = carry + val1 + val2;
            digit = sum % 10;
            insertNode(ansHead, ansTail, digit);
            carry = sum / 10;
    
            if (first != NULL) {
                first = first -> next;
            }
    
            if (second != NULL) {
                second = second -> next;
            }
        }
    
        return ansHead;
    }

    // Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
        //step1 - reverse input LL
        num1 = reverseList(num1);
        num2 = reverseList(num2);
    
        //step2 - add 2 LL
        Node* ans = add(num1, num2);
    
        //step3 - reverse the ans LL
        ans = reverseList(ans);
    
        return ans;
    }
};