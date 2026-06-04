/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* findMiddle(struct ListNode* head){
    int mid_idx = 0;

    for(struct ListNode *i = head; i != NULL; i = i->next){
        mid_idx++;
    }

    mid_idx /= 2;

    while(mid_idx != 0){
        head = head->next;
        mid_idx--;
    }
    return head;
}

struct ListNode* findMiddlePrev(struct ListNode* head){
    struct ListNode *mid = findMiddle(head);

    if(head == mid) return NULL;

    for(struct ListNode *i = head; i != NULL; i = i->next){
        if(i->next == mid)
            return i;
    }

    return NULL;
}

struct TreeNode* build(struct ListNode* head){
    if(head == NULL) return NULL;
    
    if(head->next == NULL)
    {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    struct ListNode *mid = findMiddle(head);
    struct ListNode *prev = findMiddlePrev(head);

    prev->next = NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = build(head);
    root->right = build(mid->next);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return build(head);
}