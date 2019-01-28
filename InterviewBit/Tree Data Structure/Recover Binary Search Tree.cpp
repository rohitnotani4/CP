/*

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
 
TreeNode* findInorderPredecessor(TreeNode* root, TreeNode* parent)
{
    while(root->right != NULL && root->right != parent)
    {
        root = root->right;
    }
    return root;
}

vector<int> MorisInorderModified(TreeNode* curr)
{
    TreeNode* prev = NULL;
    TreeNode* firstNode = NULL;
    TreeNode* secondNode = NULL;
    vector<int> result;
    while(curr != NULL)
    {                       
        if(curr->left == NULL)
        {
            // process curr and move to right     
            if (prev != NULL && prev->val >= curr->val)
            {
                if (firstNode == NULL)
                    firstNode = prev;
                secondNode = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode* pred = findInorderPredecessor(curr->left, curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                if (prev != NULL && prev->val >= curr->val)
                {
                    if (firstNode == NULL)
                        firstNode = prev;
                    secondNode = curr;
                }
                pred->right = NULL;                  
                prev = curr;
                curr = curr->right;
            }
        }         
    }  
    
    if(firstNode != NULL && secondNode != NULL)
    {
        result.push_back(firstNode->val);
        result.push_back(secondNode->val);
    }
    sort(result.begin(), result.end());
    return result;
}
    
     
vector<int> Solution::recoverTree(TreeNode* A) 
{
    return MorisInorderModified(A);
}
