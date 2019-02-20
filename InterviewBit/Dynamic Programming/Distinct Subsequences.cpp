/*
https://www.interviewbit.com/problems/distinct-subsequences/
*/

int Solution::numDistinct(string A, string B) 
{
    int lengthOfA = A.length();
    int lengthOfB = B.length();
    
    int dp[lengthOfB+1][lengthOfA+1];
    
    // To match empty "B" string with A, we will have to delete all characters from A. Hence we have only one solution  
    for(int j=0;j<=lengthOfA;j++)
        dp[0][j] = 1;
        
    for(int i=1;i<=lengthOfB;i++)
        dp[i][0] = 0;
    
    for(int i=1;i<=lengthOfB;i++)
    {
        for(int j=1;j<=lengthOfA;j++)
        {
            if(A[j-1] == B[i-1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[lengthOfB][lengthOfA];
}
