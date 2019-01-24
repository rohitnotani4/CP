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

class BSTIterator {
public:
    stack<TreeNode*> track;
    TreeNode* node = NULL; 
    bool forward;

    BSTIterator(TreeNode *root, bool moveLeft) 
    {
        node = root;
        forward = moveLeft;
    }
     
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return node != NULL || !track.empty();
    }
     
    /** @return the next smallest number */
    int next() 
    {
        while(hasNext())
        {
            if (node != NULL)
            {
                track.push(node);
                node = forward ? node->left : node->right;
            }
            else
            {
                TreeNode* top = track.top();
                track.pop();
                int nextVal = top->val;
                node = forward ? top->right : top->left;
                return nextVal;
            }
        }
        return -1; // Return is required otherwise compilation error
    } 
};

int Solution::t2Sum(TreeNode* A, int B) 
{
    
    if (A == NULL || (A->left == NULL && A->right == NULL))
        return 0;
    
    BSTIterator l(A, true);
    BSTIterator r(A, false);
    
    for (int i = l.next(), j = r.next(); i < j;) 
    {
        int sum = i + j;
        if (sum == B) 
            return 1;
        else if (sum < B)
            i = l.next();
        else
            j = r.next();
    }
    return 0;
}
