/*
https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
 
void InorderBST(TreeNode* root, vector<int>& allNodes)
{
    if(root==NULL)
        return ;
    
    InorderBST(root->left,allNodes);
    allNodes.push_back(root->val);
    InorderBST(root->right,allNodes);
    
}
 
int Solution::kthsmallest(TreeNode* root, int k) 
{
    int count = 0;
    vector<int> allNodes;
    InorderBST(root,allNodes);   
    return allNodes[k-1];
}
