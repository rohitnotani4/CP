/*
https://www.interviewbit.com/problems/balanced-binary-tree/
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
 
int balancedHeight(TreeNode* node)
{
    if (node == NULL)
        return 0;
        
    int leftHeight = balancedHeight(node->left);
    int rightHeight = balancedHeight(node->right);
    
    if (leftHeight == -1 || rightHeight == -1)
        return -1;
        
    if (abs (leftHeight - rightHeight) > 1)
        return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (balancedHeight (A) != -1)
        return 1;
    return 0;
}
