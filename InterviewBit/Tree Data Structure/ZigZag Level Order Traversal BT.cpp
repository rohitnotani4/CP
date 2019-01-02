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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > result;
    if (A == NULL)
        return result;
    queue<TreeNode*> nodes;
    nodes.push(A);
    while(!nodes.empty())
    {
        vector<int> level;
        int size = nodes.size();
        while(size > 0)
        {
            TreeNode* curr = nodes.front();
            nodes.pop();
            level.push_back(curr->val);
            
            if(curr->left != NULL)
                nodes.push(curr->left);
            
            if(curr->right != NULL)
                nodes.push(curr->right);
            
            size--;
        }
        if (result.size()%2)
        {
            reverse(level.begin(), level.end());
        }
        result.push_back(level);         
    }
    return result;
}
