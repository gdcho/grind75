/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* removeElements(struct ListNode* head, int val) {
//     // Handle nodes at the head which should be removed
//     while (head != NULL && head->val == val) {
//         struct ListNode* temp = head;
//         head = head->next;
//         free(temp);
//     }

//     struct ListNode* current = head;

//     // Ensure we're not at the end and the next node is not NULL
//     while (current != NULL && current->next != NULL) {
//         if (current->next->val == val) {
//             struct ListNode* temp = current->next;
//             current->next = current->next->next;
//             free(temp);
//         } else {
//             current = current->next;
//         }
//     }

//     return head;
// }

// recursive
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;

    head->next = removeElements(head->next, val);

    if (head->val == val) {
        struct ListNode* temp = head->next;
        free(head);
        return temp;
    }

    return head;
}
