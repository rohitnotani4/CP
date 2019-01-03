/*
https://www.interviewbit.com/problems/path-sum/
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
 
int solve(TreeNode* root, int currentSum, int target)
{
    if(root == NULL) //&& currentSum = target)
    {
        if(currentSum == target)
            return 1;
        else
            return 0;
    }
    
    int ans = 0;
    if(currentSum+root->val == target && root->left == NULL && root->right==NULL)
        return 1;
        
    if(root->left)
        ans = ans || solve(root->left,currentSum+root->val,target);
    
    if(root->right)
        ans = ans || solve(root->right,currentSum+root->val,target);
    
    return ans;    
    
    
}

int Solution::hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(A,0,B);
}
