/*
https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
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
 
int sumPathToRoot(TreeNode* curr, int currSum)
{
    if(curr->left == NULL && curr->right == NULL)
            return currSum;
        
    int leftSum = 0, rightSum = 0;
    if(curr->left != NULL)
        leftSum = sumPathToRoot(curr->left, 
        (((currSum*10)%1003 + (curr->left->val)%1003)%1003));
    
    if(curr->right != NULL)
        rightSum = sumPathToRoot(curr->right, 
        (((currSum*10)%1003 + (curr->right->val)%1003)%1003));
    
    return (leftSum%1003 + rightSum%1003)%1003;              
} 
 
int Solution::sumNumbers(TreeNode* A) 
{
    if(A == NULL)
        return 0;
        
    return sumPathToRoot(A, A->val);
}
