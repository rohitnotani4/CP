/*
https://www.interviewbit.com/problems/2sum-binary-tree/
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
 
bool inOrderTraversal(TreeNode* A, unordered_set<int>& hashTable, int B)
{
    if (A == NULL)
        return false;
    
   if (hashTable.find(B - (A->val)) != hashTable.end())
        return true;
    else
    {
        hashTable.insert(A->val);
    }
    return inOrderTraversal(A->left, hashTable, B) || inOrderTraversal(A->right, hashTable, B);
}

int Solution::t2Sum(TreeNode* A, int B) 
{
    unordered_set<int> hashTable;
    
    if (inOrderTraversal(A, hashTable, B))
        return 1;
    
    return 0;
}
