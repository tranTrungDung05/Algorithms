/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
    int ans = 0;
    if(root == NULL){
        return 0;
    }
    for(int i = 0; i < root->numChildren; i++){
        int depth = maxDepth(root->children[i]);  

        if(depth > ans){
            ans = depth;
        }
    }
    return ans + 1;
}