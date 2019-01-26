/*
https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
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
 
void preOrderTraversal(TreeNode* root, vector<TreeNode*>& nodeList) 
{
    if(root == NULL)
        return ;
    
    nodeList.push_back(root);
    preOrderTraversal(root->left, nodeList);
    preOrderTraversal(root->right, nodeList);
}

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<TreeNode*> nodeList;
    TreeNode* root = A;
    preOrderTraversal(A,nodeList);
    
    root->left = NULL;
    for(int i=0;i<nodeList.size()-1;i++)
    {
        nodeList[i]->right = nodeList[i+1];
        nodeList[i]->left = NULL;
    }
    
    return root;
}
