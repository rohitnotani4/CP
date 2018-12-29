/*
https://www.interviewbit.com/problems/inorder-traversal/
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
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int complete = 0;
    vector<int> ans;
    if(A==NULL)
        return ans;
        
    stack<TreeNode*> st;    
    TreeNode* curr = A;
    
    while(!complete)
    {
        if(curr != NULL)
        {
            st.push(curr);  
            // cout<<"Curr = "<<curr<<" Value = "<<curr->val<<" Right = "<<curr->right<<"\n";
            curr = curr->left; 
        }
        else
        {
            if(!st.empty())
            {
                if(!st.top()->right)
                    curr = NULL;
                else
                    curr = st.top()->right;
                    
                // cout<<"Stack Top = "<<st.top()<<" Value = "<<st.top()->val<<" Right = "<<st.top()->right<<"\n";
                ans.push_back(st.top()->val);
                st.pop();
            }
            else
                complete = 1;
        }
        
            
    }
    return ans;   
}
