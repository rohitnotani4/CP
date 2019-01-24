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
 
int InorderBST(TreeNode* root,int& k)
{
    if(root==NULL)
        return -1;
    
    int k1 = InorderBST(root->left,k);
    if (k == 0)
        return k1;
    k--;
    if (k == 0)
        return root->val;
    
    return InorderBST(root->right,k);
    
}

int Solution::kthsmallest(TreeNode* root, int k) 
{
    int count = 0;
    return InorderBST(root,k);   
}
