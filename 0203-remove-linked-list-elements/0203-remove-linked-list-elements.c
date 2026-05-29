/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL){
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *i = &dummy;

    while(i->next != NULL){
        if(i->next->val == val){
            struct ListNode *temp = i->next;
            i->next = i->next->next;
            free(temp);
        }else{
            i = i->next;
        }
    }
    return dummy.next;
}