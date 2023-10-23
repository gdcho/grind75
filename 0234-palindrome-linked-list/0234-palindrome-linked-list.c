/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 1. see singly-linked list is equal to reverse
// 2. two pointers

int checkPalindrome(struct ListNode** left, struct ListNode* right) {
    // Base case
    if (right == NULL) return 1;

    int isPalin = checkPalindrome(left, right->next);
    if (!isPalin) return 0;

    isPalin = (right->val == (*left)->val);

    *left = (*left)->next;

    return isPalin;
}

int isPalindrome(struct ListNode* head) {
    return checkPalindrome(&head, head);
}
