/*
https://www.interviewbit.com/problems/postorder-traversal/
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
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result;
    if(A==NULL)
        return result;
        
    stack<TreeNode*> nodes;
    TreeNode* curr = A;
    nodes.push(curr);
    while(!nodes.empty())
    {
        curr = nodes.top();
        nodes.pop();
        result.push_back(curr->val);
        
        if(curr->left != NULL)
            nodes.push(curr->left);
            
        if(curr->right != NULL)
            nodes.push(curr->right);
    }
    reverse(result.begin(), result.end());
    return result;
}
