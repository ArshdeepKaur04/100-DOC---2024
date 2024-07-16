/*
#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the length of a linked list
int length(ListNode *head) {
    int len = 0;
    ListNode *current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

// Function to find the merge point of two linked lists
int findMergePoint(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    // Adjust the starting points if lists have different lengths
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff > 0) {
            currentA = currentA->next;
            diff--;
        }
    } else if (lenB > lenA) {
        int diff = lenB - lenA;
        while (diff > 0) {
            currentB = currentB->next;
            diff--;
        }
    }

    // Traverse both lists until a common node is found
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA == currentB) {
            return currentA->val; // Found the merge point
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }

    return -1; // No merge point found
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
    cout << "Create the first linked list:" << endl;
    ListNode* headA = createLinkedList();

    cout << "Create the second linked list:" << endl;
    ListNode* headB = createLinkedList();

    // Finding the merge point
    int mergeValue = findMergePoint(headA, headB);
    if (mergeValue != -1) {
        cout << "Merge Point Value: " << mergeValue << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
*/

#include <iostream>
using namespace std;

// Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int length(ListNode *head) {
    int len = 0;
    ListNode *current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

int findMergePoint(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    // Adjust the starting points if lists have different lengths
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff > 0) {
            currentA = currentA->next;
            diff--;
        }
    } else if (lenB > lenA) {
        int diff = lenB - lenA;
        while (diff > 0) {
            currentB = currentB->next;
            diff--;
        }
    }

    // Traverse both lists until a common node is found
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA == currentB) {
            return currentA->val; // Found the merge point
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }
}

int main() {
    // Creating linked list 1: 1 -> 2 -> 3
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    // Creating linked list 2: 4 -> 5 -> 3
    ListNode *headB = new ListNode(4);
    headB->next = new ListNode(5);
    // Linking the lists at node with value 3
    headB->next->next = headA->next->next;

    // Finding the merge point
    int mergeValue = findMergePoint(headA, headB);
    if (mergeValue != -1) {
        cout << "Merge Point Value: " << mergeValue << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}