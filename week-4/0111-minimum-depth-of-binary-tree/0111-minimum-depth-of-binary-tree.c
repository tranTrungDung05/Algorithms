/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;

    int left_depth = 1000000; //10^5
    int right_depth = 1000000; //10^5

    if(root->left != NULL){
        left_depth = minDepth(root->left);
    }
    if(root->right != NULL){
        right_depth = minDepth(root->right);
    }

    if (left_depth < right_depth) {
        return 1 + left_depth;
    } else {
        return 1 + right_depth;
    }
}