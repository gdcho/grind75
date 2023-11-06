/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* leftPrev = &dummy;
    struct ListNode* cur = head;

    // move pointer to left starting point
    for (int i=0; i<left-1; i++){
        leftPrev = cur;
        cur = cur->next;
    }

    // reverse sublist
    struct ListNode* prev = NULL;
    for (int i=0; i< right-left+1; i++){
        struct ListNode* tmpNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmpNext;
    }

    // Connect the end of the reversed sublist to the remaining list.
    leftPrev->next->next = cur; 
    // Connect the start of the sublist to the previous part of the list.
    leftPrev->next = prev;      

    return dummy.next;
}
