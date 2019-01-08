/*
https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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
 
TreeNode* constructBST(int low, int high, const vector<int> &A) 
{
    TreeNode* root = NULL;
    if(low <= high)
    {
        int mid = low + (high-low)/2;
        root = new TreeNode(A[mid]);
        root->left = constructBST(low, mid-1,A);
        root->right = constructBST(mid+1,high,A);
    }
    
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return constructBST(0,A.size()-1,A);
}
