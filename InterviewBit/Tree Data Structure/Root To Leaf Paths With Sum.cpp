/*
https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
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
 
void solve(TreeNode* root,int currentSum,int target,
vector<int>& path, vector<vector<int> >& paths)
{
    if(root == NULL) //&& currentSum = target
        return;
    
    if(root->left == NULL && root->right==NULL)
    {
        if(currentSum+root->val == target)
        {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
        }
        return;
    }
    
    path.push_back(root->val);  
    solve(root->left,currentSum+root->val,target,path,paths);
    solve(root->right,currentSum+root->val,target,path,paths);
    path.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > ans;
    vector<int> path;
    solve(root,0,sum,path,ans);
    return ans;
}
