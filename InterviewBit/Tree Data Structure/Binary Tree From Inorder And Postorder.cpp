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
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void buildIndexMap(unordered_map<int, int>& indexMap, vector<int>& inorder)
{
    for(int i=0;i<inorder.size();i++)
    {
        indexMap[inorder[i]] = i;
    }    
}

TreeNode* makeTree(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& indexMap, int i,int j, int& p)
{
    if(i > j)
        return NULL;
    
    TreeNode* node = new TreeNode(postorder[p]);
    p--;
    
    if(i==j)
        return node;
    
    int index = indexMap[node->val];
    node->right = makeTree(postorder, inorder, indexMap, index+1, j, p);
    node->left = makeTree(postorder, inorder, indexMap, i, index-1, p);
    return node;
}  
    
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    if(A.size() < 1 || B.size() < 1)
        return NULL;
        
    int endIndex = B.size()-1;
    unordered_map<int, int> indexMap;
    buildIndexMap(indexMap, A);
    return makeTree(B, A, indexMap, 0, endIndex, endIndex);
}
