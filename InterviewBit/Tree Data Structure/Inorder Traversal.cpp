/*
https://www.interviewbit.com/problems/inorder-traversal/
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
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    
    if (A == NULL)
        return result;
    
    TreeNode* curr = A;    
    stack<TreeNode*> inorderStack;
    while(!inorderStack.empty() || curr != NULL)
    {
        if(curr != NULL)
        {
            inorderStack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = inorderStack.top();
            result.push_back(curr->val);
            inorderStack.pop();
            curr = curr->right;
        }
    }
    
    return result;
}
