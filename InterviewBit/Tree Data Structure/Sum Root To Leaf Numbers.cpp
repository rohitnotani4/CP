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
 
int sumPathToRoot(TreeNode* curr, int sum)
{
    if (curr == NULL)
        return 0;
    
    int currPlusSum =  ((sum*10)%1003 + curr->val)%1003;
    if (curr->left == NULL && curr->right == NULL)
        return currPlusSum;
        
    int leftSum = sumPathToRoot(curr->left, currPlusSum);
    int rightSum = sumPathToRoot(curr->right, currPlusSum);
    
    return (leftSum + rightSum)%1003;
}

int Solution::sumNumbers(TreeNode* A) 
{
    return sumPathToRoot(A, 0)%1003;
}
