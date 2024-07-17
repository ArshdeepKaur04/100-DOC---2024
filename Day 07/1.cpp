/*
Question:
"Delete duplicate-value nodes from a sorted linked list" on HackerRank

You are given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending 
order. Delete nodes and return a sorted list with each distinct value in the original list. The given head pointer
may be null indicating that the list is empty.
*/

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* current = llist;
    while (current && current->next) {
        if (current->data == current->next->data) {
            SinglyLinkedListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return llist;
}