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
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    TreeNode* now = A;
    while(now != NULL)
    {
        if (now->left != NULL)
        {
            TreeNode* pre = now->left;
            // Find the rightmost node of this node
            while(pre->right != NULL)
            {
                pre = pre->right;
            }
            // Point to right of this rightmost node to now->right. In other words this 
            // sets the right pointer of the last node in the left subtree.
            pre->right = now->right;
            // Now set the start of left subtree to now's right.
            now->right = now->left;
            // Set the left of now to NULL
            now->left = NULL;
        }
        else
        {
            // There is nothing on left subtree, move to right subtree
            now = now->right;
        }
    }
    return A;
}

