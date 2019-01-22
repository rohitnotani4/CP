/*
https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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
 
void buildIndexMap(unordered_map<int,int>& indexMap, vector<int> &inorder)
{
    for(int i=0;i<inorder.size();i++)
    {
        indexMap[inorder[i]] = i;
    }
}

TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int,int>& indexMap, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    
    TreeNode* node = new TreeNode(preorder[p++]);
    
    if (i==j)
        return node;
    
    int index = indexMap[node->val];
    node->left = makeTree(preorder, inorder, indexMap, i, index-1, p);
    node->right = makeTree(preorder, inorder, indexMap, index+1, j, p);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {    
    if (preorder.empty() || inorder.empty())
        return NULL;
    
    unordered_map<int,int> indexMap;
    buildIndexMap(indexMap, inorder);   
    
    int startIndex = 0, endIndex = preorder.size()-1;
    return makeTree(preorder, inorder, indexMap, startIndex, endIndex, startIndex);
}
