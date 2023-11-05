/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

     // Create a dummy node which will be the start of the result list.
    struct ListNode* dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* curr = dummyHead;
    int carry = 0;
    
    while (p != NULL || q != NULL) {
        // Sum the two numbers and the carry
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        
        // Create a new node with the digit value of (sum mod 10)
        struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Append the new node to the result list.
        curr->next = newNode;
        curr = newNode;
        
        // Move to the next elements in the lists
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    
    // Check if there is a carry left
    if (carry > 0) {
        struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        curr->next = newNode;
    }
    
    // Return the result list, which is the next of the dummy node.
    struct ListNode* result = dummyHead->next;
    free(dummyHead); // Don't forget to free the dummy head
    return result;
    
}