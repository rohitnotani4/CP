/*
https://www.interviewbit.com/problems/least-common-ancestor/
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
 
bool PreOrderTraversal(TreeNode* A, int value,vector<int>& nodes)
{
    if(A==NULL)
        return false;
    
    nodes.push_back(A->val);
    if(A->val == value)
        return true;
    
    bool foundInleft = PreOrderTraversal(A->left, value, nodes);
    bool foundInRight = PreOrderTraversal(A->right, value, nodes);
    
    if(foundInleft || foundInRight)
        return true;
    nodes.pop_back();
    return false;
}
 
int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lca = -1;
    bool foundVal1 = false, foundVal2 = false;
    vector<int> pathToFirstElement, pathToSecondElement;
    
    foundVal1 = PreOrderTraversal(A,val1,pathToFirstElement);
    if(!foundVal1)
        return lca;
    
    foundVal2 = PreOrderTraversal(A,val2,pathToSecondElement);
    if(!foundVal2)
        return lca;
    
    int i=0;
    while(i < pathToFirstElement.size() && i < pathToSecondElement.size()
        && pathToFirstElement[i] == pathToSecondElement[i])
        i++;
    
    /*
    for(int i=0;i<pathToFirstElement.size();i++)
        cout<<pathToFirstElement[i]<<" ";
    cout<<"\n";
    
    for(int j=0;j<pathToSecondElement.size();j++)
        cout<<pathToSecondElement[j]<<" ";
    cout<<"\n";
    */
 
    lca = pathToFirstElement[i-1];
    return lca;  
}
