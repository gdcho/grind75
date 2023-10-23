/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;  // Change next of current node
        prev = current;        // Move prev to this node
        current = next;        // Move to the next node
    }
    
    return prev;  // New head of the reversed linked list
}
