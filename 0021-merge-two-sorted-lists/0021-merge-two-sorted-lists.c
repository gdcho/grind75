/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// iterative solution
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
//     struct ListNode dummy;
//     dummy.val = 0;
//     dummy.next = NULL;
    
//     struct ListNode* current = &dummy;

//     while(list1 != NULL && list2 != NULL){
//         if(list1->val < list2->val){
//             current->next = list1;
//             list1 = list1->next;
//         } else {
//             current->next = list2;
//             list2 = list2->next;
//         }
//         current = current->next;
//     }

//     if(list1 == NULL){
//         current->next = list2;
//     } else {
//         current->next = list1;
//     }

//     return dummy.next;
// }

// recursive solution
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Base cases
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    // Recursive case
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}