/*
Question:
Given a singly linked list, write a function to print the elements in reverse order.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printReverseRecursive(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    
    // Recursive call to print the next node in reverse
    printReverseRecursive(head->next);
    
    // Print the current node's value
    std::cout << head->val << " ";
}

ListNode* createLinkedList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n;
    
    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> value;
        
        ListNode* newNode = new ListNode(value);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

int main() {
    ListNode* head = createLinkedList();
    
    std::cout << "Elements in reverse order: ";
    printReverseRecursive(head); // Output: elements in reverse order

    return 0;
}