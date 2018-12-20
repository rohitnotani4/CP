/*
https://www.interviewbit.com/problems/combination-sum/
*/

void combinationSumHelper(vector<vector<int> >& result,vector<int>& chosen, vector<int>& input,int index, int currentSum,int target)
{
    if(currentSum > target)
    {
        return ;
    }
    
    if(currentSum==target)
    {
        result.push_back(chosen);
        return ;
    }
    
    for(int i = index;i<input.size();i++)
    {
        chosen.push_back(input[i]);
        currentSum += input[i];
            
        combinationSumHelper(result,chosen,input,i,currentSum,target);
            
        chosen.pop_back();
        currentSum -= input[i];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> chosen, uniqueElements;
    vector<vector<int> > result;
    sort(A.begin(), A.end());
    
    for(int i=0;i<A.size();i++)
    {
        if(i==0 || A[i] != A[i-1])
            uniqueElements.push_back(A[i]);
    }
        
    combinationSumHelper(result,chosen,uniqueElements,0,0,B);
    return result; 
}
