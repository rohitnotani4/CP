/*
https://www.interviewbit.com/problems/unique-paths-in-a-grid/
*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 1)
        return 0;
    
    int rows = A.size(), cols = A[0].size();
    vector<vector<int> > dp(rows, vector<int> (cols, 0));    
    
    if(A[0][0]==1)
        dp[0][0] = 0;
    else
        dp[0][0] = 1;
        
    for(int i=1;i<A.size();i++)
    {
        if(A[i][0]==1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }
    
    for(int j=1;j<A[0].size();j++)
    {
        if(A[0][j]==1)
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j-1];
    }
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {
            if(A[i][j]==1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[rows-1][cols-1];
}
