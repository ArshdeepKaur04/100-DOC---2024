/*
Question "Merge Sort for Linked List" on GfG
Given a pointer/reference to the head of the linked list, the task is to sort the given linked list using Merge 
Sort.
*/

//Already done in Love Babbar's Course
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head -> next;
    
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
    
        return slow;
    }
    
    Node* mergeLists(Node * left, Node* right) {
        //if left part is empty
        if (left == NULL) {
            return right;
        }
    
        //if right part is empty
        if (right == NULL) {
            return left;
        }
        
        Node* ans = new Node(-1);
        Node* temp = ans;
    
        //merge 2 sorted Linked List
        while (left != NULL && right != NULL) {
            if (left -> data < right -> data) {
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else {
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
    
        while (left != NULL) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
    
        while (right != NULL) {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    
        temp = ans -> next;
        delete ans;
        return temp;
    }
    
    Node* mergeSort(Node* head) {
        //base case
        if (head == NULL || head -> next == NULL) {
            return head;
        }
    
        //break linked list into 2 halves, after finding the mid
        Node* mid = findMid(head);
    
        Node* left = head;
        Node* right = mid -> next;
        mid -> next = NULL;
    
        //recursive calls to sort both halves
        left = mergeSort(left);
        right = mergeSort(right);
    
        //merge both left and right halves
        Node* result = mergeLists(left, right);
    
        return result;
    }
};