/*
https://www.interviewbit.com/problems/stairs/
*/

int Solution::climbStairs(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (A <= 0)
        return 0;
        
    int dp[A];
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<A;i++)
    {
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[A-1];
}
