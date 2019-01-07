/*
https://www.interviewbit.com/problems/balanced-binary-tree/
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
 
int depth(TreeNode* A)
{
    if(A==NULL)
        return 0;
    
    int leftHeight = depth(A->left);
    int rightHeight = depth(A->right);
    
    return 1 + max(leftHeight,rightHeight);
}

int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==NULL)
        return 1;
        
    int leftDepth = depth(A->left);
    int rightDepth = depth(A->right);
    
    if(abs(leftDepth - rightDepth) <=1 && isBalanced(A->left) && isBalanced(A->right))
        return 1;
    return 0;
}
