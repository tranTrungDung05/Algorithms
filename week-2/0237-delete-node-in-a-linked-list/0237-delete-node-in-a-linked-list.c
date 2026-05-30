/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swapNode(struct ListNode *node){
    int value = node->val;
    //swap value
    node->val = node->next->val;
    node->next->val = value;
}
void deleteNode(struct ListNode* node) {
    swapNode(node);
    struct ListNode *temp = node->next;
    node->next = node->next->next;
    free(temp);
}