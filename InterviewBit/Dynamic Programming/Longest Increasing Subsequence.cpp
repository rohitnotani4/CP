/*
https://www.interviewbit.com/problems/longest-increasing-subsequence/
*/

int Solution::lis(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    vector<int> dp(n, 1);
    int maxLength = dp[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if (A[j] < A[i] && dp[i] < (dp[j]+1))
            {
                dp[i] = dp[j] + 1;
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}
