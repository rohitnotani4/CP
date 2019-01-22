/*
https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
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
 
int findIndex(vector<int>& inorder,int start,int end, int value)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==value)
            return i;
    }    
}

TreeNode* makeTree(vector<int>& postorder, vector<int>& inorder, int i,int j, int& p)
{
    
    if(i > j)
        return NULL;
    
    TreeNode* node = new TreeNode(postorder[p]);
    p--;
    
    if(i==j)
        return node;
    
    int in = findIndex(inorder, i, j, node->val);
    node->right = makeTree(postorder, inorder,in+1, j, p);
    node->left = makeTree(postorder, inorder, i, in-1, p);
    return node;
    
}
    
    
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    if(A.size() < 1 || B.size() < 1)
        return NULL;
        
    int p=B.size()-1;
    return makeTree(B, A, 0, p, p);
}
