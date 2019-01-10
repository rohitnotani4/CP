/*
https://www.interviewbit.com/problems/valid-binary-search-tree/
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
 
int checkIfValidBST(TreeNode* root, int lowerBound, int upperBound)
{
    
    if(root==NULL)
        return 1;
    
    int isBST = 0;
    if(root->val >= lowerBound && root->val < upperBound)
        isBST = 1;
    
    return isBST 
            && checkIfValidBST(root->left,lowerBound, root->val)
            && checkIfValidBST(root->right,root->val,upperBound);
}
 
 
int Solution::isValidBST(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return checkIfValidBST(A,INT_MIN,INT_MAX);
}
