/*
Preorder Tree Traversal without recursion and without stack!
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
 
TreeNode* findInorderPredecessor(TreeNode* predecessor, TreeNode* parent)
{
    while(predecessor->right != parent && predecessor->right != NULL)
    {
          predecessor = predecessor->right;
    }
    return predecessor;
}

void MorrisInorderTraversal(TreeNode* root)
{
    TreeNode* curr = root
    while(curr != NULL)
    {
        //Left subtree is null so print the node and go to right subtree
        if (curr->left == NULL)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else
        {
            // To find predecessor keep going right till right node is not null or right node is not current.
            TreeNode* predecessor = findInorderPredecessor(curr->left, curr);
            
            //If right node is null then go left after establishing link from predecessor to current.
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                cout<<curr->val<<" ";
                curr = curr->left;
            }
            else //Left subtree has already been visited. Go to right after visiting current.
            {
                predecessor->right = NULL;
                curr = curr->right;
            }
        }  
    }
}    
