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
 
stack<TreeNode *> myStack;
 
void pushAll(TreeNode* node)
{
    while(node != NULL)
    {
        myStack.push(node);
        node = node->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) 
{
    stack<TreeNode *> clearStack;
    myStack.swap(clearStack);
    pushAll(root);
}
 
/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    return !myStack.empty(); 
}
 
/** @return the next smallest number */
int BSTIterator::next() 
{
    TreeNode *tmpNode = myStack.top();
    myStack.pop();
    pushAll(tmpNode->right);
    return tmpNode->val;
}
 
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
