/*
https://www.interviewbit.com/problems/max-depth-of-binary-tree/
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
int Solution::maxDepth(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==NULL)
        return 0;
    
    int leftDepth = maxDepth(A->left);
    int rightDepth = maxDepth(A->right);
    
    return 1 + max(leftDepth,rightDepth);
}
