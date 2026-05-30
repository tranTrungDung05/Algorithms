/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int countList(struct ListNode *head){
    int count = 0;

    for(struct ListNode *i = head; i != NULL; i = i->next){
        count++;
    }

    return count;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = countList(head);

    int del_idx = count - n;

    // xÃ³a head
    if(del_idx == 0){
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct ListNode *i = head;

    for(int idx = 0; idx < del_idx - 1; idx++){
        i = i->next;
    }

    struct ListNode *temp = i->next;
    i->next = i->next->next;
    free(temp);

    return head;
}