/*
https://www.interviewbit.com/problems/repeating-subsequence/
*/

int Solution::anytwo(string A) 
{
    if (A.size() < 2)
        return 0;
    
    int n = A.size();
    int lcsModified[n+1][n+1];
    for (int i=0; i<=n; i++)
    {
        lcsModified[i][0] = 0;
        lcsModified[0][i] = 0; 
    }
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==A[j-1] && i != j)
                lcsModified[i][j] = 1 + lcsModified[i-1][j-1];
            else
                lcsModified[i][j] = max(lcsModified[i-1][j], lcsModified[i][j-1]);
        }
    }
    
    if(lcsModified[n][n] >=2)
        return 1;
    
    return 0;
}
