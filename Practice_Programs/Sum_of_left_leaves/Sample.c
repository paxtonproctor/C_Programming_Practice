/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int left(struct TreeNode* root) {
    if (!root) return 0;
    if ((!root->left) && (!root->right))
        return root->val;
    return sumOfLeftLeaves(root->right)+left(root->left);
}

int sumOfLeftLeaves(struct TreeNode* root){
    if((!root) || ((!root->left) && (!root->right)))
        return 0;
    return sumOfLeftLeaves(root->right)+left(root->left);
}
