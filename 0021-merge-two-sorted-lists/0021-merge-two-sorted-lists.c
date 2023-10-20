struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // Create a dummy node.
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* current = &dummy;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // At this point, one of the lists is empty.
    if(list1 != NULL){
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next;
}
