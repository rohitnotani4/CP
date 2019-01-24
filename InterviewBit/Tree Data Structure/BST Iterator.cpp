/*
https://www.interviewbit.com/problems/bst-iterator/
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
 
stack<TreeNode*> track;
TreeNode* node = NULL; 

BSTIterator::BSTIterator(TreeNode *root) 
{
    node = root;
}
 
/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    return node != NULL || !track.empty();
}
 
/** @return the next smallest number */
int BSTIterator::next() 
{
    while(hasNext())
    {
        if (node != NULL)
        {
            track.push(node);
            node = node->left;
        }
        else
        {
            TreeNode* top = track.top();
            track.pop();
            int nextVal = top->val;
            node = top->right;
            return nextVal;
        }
    }
    return -1; // Return is required otherwise compilation error
}
 
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
