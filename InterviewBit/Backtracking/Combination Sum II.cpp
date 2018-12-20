/*
https://www.interviewbit.com/problems/combination-sum-ii/
*/

bool checkifSame(vector<vector<int> >& ans, vector<int>& temp)
{
    int prevSoultion = ans.size()-1;
    
    if(ans.size()==0)
        return false;
        
    if(ans[prevSoultion].size() != temp.size())
        return false;
    
    for(int j=0;j<ans[prevSoultion].size();j++)
    {
        if(ans[prevSoultion][j]!=temp[j])
            return false;
    }
    return true;
}
 
bool calculateSumRecursively 
(vector<vector<int> >& ans,vector<int>& temp, vector<int>& A, int sum,int target, int currentIndex)
{
    if(sum==target)
    {
        return true;
    }
    
    if(sum < target)
    {
        for(int i=currentIndex;i<A.size();i++)   
        {
            // *prev = (*it);
            temp.push_back(A[i]);
            sum += A[i];
            if(calculateSumRecursively(ans,temp,A,sum,target,i+1))
            {
                if(!checkifSame(ans,temp))
                    ans.push_back(temp);
            }
            temp.pop_back();
            sum -= A[i];
        }
    }
    return false;
}
 
 
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int prev = -1;
    vector<int> temp;
    vector<vector<int> > ans;
    
    sort(A.begin(),A.end());
        
    calculateSumRecursively(ans,temp,A,0,B,0);
    return ans;  
}
