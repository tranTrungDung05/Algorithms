/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;

    struct ListNode *curr_l1 = list1;
    struct ListNode *curr_l2 = list2;

    struct ListNode *head;

    if(curr_l1->val <= curr_l2->val){
        head = list1;
        curr_l1 = curr_l1->next;
    }else if(curr_l2->val <= curr_l1->val){
        head = list2;
        curr_l2 = curr_l2->next;
    }

    struct ListNode *tail = head;

    while(curr_l1 != NULL && curr_l2 != NULL){
        if(curr_l1->val <= curr_l2->val){
            tail-> next = curr_l1;
            tail = tail->next;
            curr_l1 = curr_l1->next;
        }else if(curr_l2->val <= curr_l1->val){
            tail-> next = curr_l2;
            tail = tail->next;
            curr_l2 = curr_l2->next;
        }
    }
    
    if(curr_l1 != NULL)
        tail->next = curr_l1;
    
    if(curr_l2 != NULL)
        tail->next = curr_l2;
        
    return head;
}