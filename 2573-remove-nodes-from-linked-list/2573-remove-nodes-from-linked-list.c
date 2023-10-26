/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode;
    
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    head = reverse(head);
    
    struct ListNode* newHead = head;
    struct ListNode* curr = head;
    int maxValue = head->val;
    
    while (curr && curr->next) {
        if (curr->next->val < maxValue) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
            if (curr->val > maxValue) {
                maxValue = curr->val;
            }
        }
    }
    
    return reverse(newHead);
}