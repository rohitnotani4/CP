/*
https://www.interviewbit.com/problems/least-common-ancestor/
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* lowestCommonAncestor(TreeNode* root, int val1, int val2)
{
    if(root == NULL)
        return NULL;
        
    if (root->val == val1 || root->val == val2)
        return root;
        
    TreeNode* left = lowestCommonAncestor(root->left, val1, val2);
    TreeNode* right = lowestCommonAncestor(root->right, val1, val2);
    
    if(left != NULL && right != NULL)
        return root;
        
    return left != NULL ? left : right;
}

int checkIfExists(TreeNode* A, int val)
{
    if(A == NULL)
        return 0;
        
    if(A->val == val)
        return 1;
        
    return checkIfExists(A->left, val) || checkIfExists(A->right, val);
}
 
int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (!checkIfExists(A, val1) || !checkIfExists(A, val2))
        return -1;

    TreeNode* lcaRoot = lowestCommonAncestor(A, val1, val2);
    if(lcaRoot != NULL)
        return lcaRoot->val;
    return -1;
}
