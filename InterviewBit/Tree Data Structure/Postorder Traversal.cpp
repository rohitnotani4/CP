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
    
    vector<int> ans;
    if(A==NULL)
        return ans;
        
    stack<TreeNode*> firstStack, secondStack;
    
    firstStack.push(A);
    while(!firstStack.empty())
    {
        TreeNode* curr = firstStack.top();
        firstStack.pop();
        secondStack.push(curr);
        
        if(curr->left != NULL)
            firstStack.push(curr->left);
        if(curr->right != NULL)
            firstStack.push(curr->right);
    }
    
    while(!secondStack.empty())
    {
        ans.push_back(secondStack.top()->val);
        secondStack.pop();
    }
    
    return ans;
}
