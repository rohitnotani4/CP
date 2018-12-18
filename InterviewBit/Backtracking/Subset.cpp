/*
https://www.interviewbit.com/problems/subset/
*/

void makeSet(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& ans, int curr)
{
    ans.push_back(currSubset);
    for(int index = curr;index < nums.size(); index++)
    {
        currSubset.push_back(nums[index]);

        makeSet(nums, currSubset, ans, index + 1);
        
        currSubset.pop_back();
    }
    return ;
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    vector<int> currSubset;
    vector<vector<int> > ans;

    sort(A.begin(),A.end());
    
    makeSet(A, currSubset, ans, 0);
        
    return ans;
}
