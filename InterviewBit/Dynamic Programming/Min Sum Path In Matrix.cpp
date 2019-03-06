/*
https://www.interviewbit.com/problems/min-sum-path-in-matrix/
*/

int Solution::minPathSum(vector<vector<int> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 1)
        return 0;
    
    int m = A.size();
    int n = A[0].size();
    
    int minSumDP[m][n];
    
    minSumDP[0][0] = A[0][0];
    
    for(int i=1;i<m;i++)
        minSumDP[i][0] = minSumDP[i-1][0] + A[i][0];
    
    for(int j=1;j<A[0].size();j++)
        minSumDP[0][j] = minSumDP[0][j-1] + A[0][j];
        
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            minSumDP[i][j] = min(minSumDP[i-1][j],minSumDP[i][j-1]) + A[i][j];
        }
    }
    
    return minSumDP[m-1][n-1];
}
