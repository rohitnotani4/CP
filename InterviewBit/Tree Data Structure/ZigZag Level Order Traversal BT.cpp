/*
https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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
 
void zigzagDFS(TreeNode* root, vector<vector<int> >& ans)
{
    int leftToRight = 0;
    TreeNode* curr;
    vector<int> temp;
    stack<TreeNode*> left, right;
    left.push(root);
    // currLevel.push(NULL);
    
    while(!left.empty() || !right.empty())
    {
        while(!left.empty())
        {
            curr = left.top();
            left.pop();
            if(curr->left != NULL)
                right.push(curr->left);
            if(curr->right != NULL)
                right.push(curr->right);
                
            temp.push_back(curr->val);
        }
        
        if(left.empty())
        {
            if(temp.size())
                ans.push_back(temp);
            temp.clear();
        }
        
        while(!right.empty())
        {
            curr = right.top();
            right.pop();
            if(curr->right != NULL)
                left.push(curr->right);
            if(curr->left != NULL)
                left.push(curr->left);    
                
                
            temp.push_back(curr->val);
        }
        
        if(right.empty())
        {
            if(temp.size())
                ans.push_back(temp);
            temp.clear();
        }
    }
    
}
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > ans;
    if(A != NULL)
        zigzagDFS(A,ans);
    
    return ans;
}
