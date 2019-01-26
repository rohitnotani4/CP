/*
Inorder Tree Traversal without recursion and without stack!
*/

/* Algorithm
1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
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
                curr = curr->left;
            }
            else //Left subtree has already been visited. Go to right after visiting current.
            {
                predecessor->right = NULL;
                cout<<curr->val<<" ";
                curr = curr->right;
            }
        }  
    }
}    
