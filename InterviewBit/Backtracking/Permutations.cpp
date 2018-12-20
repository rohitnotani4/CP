/*
https://www.interviewbit.com/problems/permutations/
*/

bool getAllPermutations(vector<vector<int> >& ans,unordered_set<int>& temp, vector<int>& A, 
int currentIndex)
{
    if(temp.size() == A.size())
        return true;
    
    if(temp.size() < A.size())
    {
        for(int j=0;j<A.size();j++)
        {
            if(temp.count(A[j]) == 0)
            {
                temp.insert(A[j]);
                if(getAllPermutations(ans,temp,A,j+1))
                {
                    vector<int> oneRow;
                    for(unordered_set<int>::iterator it=temp.begin(); it!=temp.end(); ++it)
                        oneRow.push_back(*it);
                    
                    ans.push_back(oneRow);
                }
                temp.erase(A[j]);
            }
        }
    }
    return false;
}
 
vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> ans;
    unordered_set<int> temp;
 
    getAllPermutations(ans, temp,A,0);    
    return ans;
}
