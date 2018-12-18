/*
https://www.interviewbit.com/problems/subsets-ii/
*/

void createSubsets(vector<vector<int> >& res, vector<int>& A, vector<int>& curr, int start)
{
    res.push_back(curr);
    
    for(int index = start;index < A.size();index++)
    {
        if(index == start || A[index] != A[index-1])
        {
            curr.push_back(A[index]);
            
            createSubsets(res, A, curr, index + 1);
            
            curr.pop_back();
        }
    }
    return ;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort(A.begin(), A.end());
    vector<vector<int> > res;
    vector<int> curr;
    createSubsets(res, A, curr, 0);
    return res;
}
