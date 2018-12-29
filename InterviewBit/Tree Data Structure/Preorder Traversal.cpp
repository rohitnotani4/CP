/*
https://www.interviewbit.com/problems/preorder-traversal/
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
vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    if(A==NULL)
        return ans;
    stack<TreeNode*> nodes;
    TreeNode* curr = NULL;
    nodes.push(A);
    while(!nodes.empty())
    {
        curr = nodes.top();
        ans.push_back(curr->val);
        nodes.pop();
        
        if(curr->right != NULL)
            nodes.push(curr->right);
        if(curr->left != NULL)
            nodes.push(curr->left);
    }    
    return ans;
}
