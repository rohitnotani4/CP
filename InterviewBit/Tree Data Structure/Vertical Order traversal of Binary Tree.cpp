/*
https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
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
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > sol;
    map<int, vector<int> > verticalOrder;
    if(A == NULL)
        return sol;
    
    queue<pair<TreeNode*, int> > visit;
    visit.push(make_pair(A, 0));
    
    while(!visit.empty())
    {
        TreeNode* curr = visit.front().first;
        int hd = visit.front().second;
        
        verticalOrder[hd].push_back(curr->val);
        
        visit.pop();
        
        if(curr->left != NULL)
            visit.push(make_pair(curr->left, hd-1));
            
        if(curr->right != NULL)
            visit.push(make_pair(curr->right, hd+1));
        
    }
    
    for(auto it = verticalOrder.begin();it !=verticalOrder.end(); it++)
    {
        sol.push_back(it->second);
    }
    return sol;
}
