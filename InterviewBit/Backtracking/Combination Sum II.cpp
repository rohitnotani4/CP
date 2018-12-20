/*
https://www.interviewbit.com/problems/combination-sum-ii/
*/

bool checkIfExists(vector<vector<int> >& result, vector<int>& chosen)
{
    int lastResultIndex = result.size()-1;
    
    if(result.size()==0 || result[lastResultIndex].size() != chosen.size())
        return false;
        
    for(int j=chosen.size()-1;j>=0;j--)
    {
        if(result[lastResultIndex][j]!=chosen[j])
            return false;
    }
    return true;
}

void combinationSumHelper(vector<vector<int> >& result, vector<int>& chosen, vector<int>& input, int index, int currentSum, int target)
{
    if(currentSum > target)
    {
        return;    
    }
    
    if(currentSum == target)
    {
        if(!checkIfExists(result, chosen))
            result.push_back(chosen);
        return ;
    }
    
    for(int i = index;i<input.size();i++)
    {
        chosen.push_back(input[i]);
        currentSum += input[i];
        
        combinationSumHelper(result, chosen, input, i+1, currentSum, target);
        
        chosen.pop_back();
        currentSum -= input[i];
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> chosen;
    vector<vector<int> > result;
    sort(A.begin(),A.end());
    combinationSumHelper(result,chosen,A,0,0,B);
    return result;  
}
