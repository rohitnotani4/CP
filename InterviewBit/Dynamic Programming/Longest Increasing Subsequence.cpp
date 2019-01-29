/*
https://www.interviewbit.com/problems/longest-increasing-subsequence/
*/

int Solution::lis(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 2)
        return A.size();
    
    vector<int> dp;    
    for(int i=0;i<A.size();i++)
    {
        dp.push_back(1);
    }
    
    int subsequenceLength = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j] < A[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=0;i<dp.size();i++)
        subsequenceLength = max(subsequenceLength,dp[i]);
    return subsequenceLength;
}
