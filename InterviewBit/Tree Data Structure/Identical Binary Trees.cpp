/*
https://www.interviewbit.com/problems/identical-binary-trees/
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
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==NULL && B==NULL)
        return 1;
    
    if(A==NULL || B==NULL)
        return 0;
    
    return  A->val == B->val && isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
}
