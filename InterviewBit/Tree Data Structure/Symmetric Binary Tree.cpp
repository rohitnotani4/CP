/*
https://www.interviewbit.com/problems/symmetric-binary-tree/
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
 
int checkIfSymmetric(TreeNode* leftPart, TreeNode* rightPart)
{
    if(leftPart == NULL && right == NULL)
        return 1;
    
    if(leftPart == NULL || right == NULL)
        return 0;
        
    return  leftPart->val == rightPart->val
            && checkIfSymmetric(leftPart->left,rightPart->right)
            && checkIfSymmetric(leftPart->right,rightPart->left);
}

int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==NULL)
        return 1;
 
    return checkIfSymmetric(A,A);
}
