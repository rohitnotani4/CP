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
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if (A[i][j])
                continue;
            if (i == 0 && j == 0)
                dp[i][j] = 1; 
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if(j > 0)
                dp[i][j] += dp[i][j-1];
        }
    }
    return dp[rows-1][cols-1];
}
