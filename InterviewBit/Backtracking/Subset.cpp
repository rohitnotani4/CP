/*
https://www.interviewbit.com/problems/subset/
*/

void makeSet(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& ans, int curr)
{
    for(int index = curr;index < nums.size(); index++)
    {
        currSubset.push_back(nums[index]);
        ans.push_back(currSubset);
        
        makeSet(nums, currSubset, ans, index + 1);
        
        currSubset.pop_back();
    }
    return ;
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    vector<int> currSubset;
    vector<vector<int> > ans;
    ans.push_back(currSubset);
    if(A.size() < 1)
        return ans;
    
    sort(A.begin(),A.end());
    
    makeSet(A, currSubset, ans, 0);
        
    return ans;
}
