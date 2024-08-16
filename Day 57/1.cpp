/*
Question "Quick Sort on Linked List" on GfG
You are given a Linked List. Sort the given Linked List using quicksort. 
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
    Node* getTail(Node* head) {
        Node* temp = head;
        while(temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }
    
    Node* partition(Node* head, Node* tail) {
        Node* pivot = head;
        Node* curr = head->next;
        Node* prev = head;
        
        while(curr != tail->next) {
            if (pivot->data > curr->data) {
                prev = prev->next;
                swap(prev->data, curr->data);
            }
            curr = curr->next;
        }
        swap(prev->data, pivot->data);
        return prev;
    }
    
    void solveSort(Node* head, Node* tail) {
        if (head == nullptr || tail == nullptr || head == tail) {
            return;
        }
        
        Node* pivot = partition(head, tail);
        if (pivot != head) {
            solveSort(head, pivot);
        }
        if(pivot != tail) {
            solveSort(pivot->next, tail);
        }
    }
  
    struct Node* quickSort(struct Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* tail = getTail(head);
        solveSort(head, tail);
        
        return head;
    }
};