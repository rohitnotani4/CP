/*
https://www.interviewbit.com/problems/stairs/
*/

int Solution::climbStairs(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int dp[A+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=A;i++)
    {
        
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    return dp[A];
}
