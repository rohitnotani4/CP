/*
https://www.interviewbit.com/problems/min-depth-of-binary-tree/
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
 
int getMinDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;
        
    int leftDepth = getMinDepth(root->left);
    int rightDepth = getMinDepth(root->right);
    return min(leftDepth,rightDepth) + 1;
}
int Solution::minDepth(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int minDepth = getMinDepth(A);
    return minDepth;
}
