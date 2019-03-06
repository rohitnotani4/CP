/*
https://www.interviewbit.com/problems/coin-sum-infinite/
*/

int Solution::coinchange2(vector<int> &A, int B) 
{
    vector<vector<int>> dp (2, vector<int> (B+1, 0));
    
    dp[0][0] = 1;
    for (int i = 1; i <= A.size(); i++) 
    {
        /*
          Set the subproblem for the amount of 0 to 1 when
          solving this row
        */
        dp[1][0] = 1;
        for (int j = 1; j <= B; j++) 
        {
            int currentCoinValue = A[i-1];
            /*
            dp[i][j] will be the sum of the ways to make change not considering
            this coin (dp[i-1][j]) and the ways to make change considering this
            coin (dp[i][j] - currentCoinValue] ONLY if currentCoinValue <= j, otherwise
            this coin can not contribute to the total # of ways to make change at this
            sub problem target amount)
            */
            int withoutThisCoin = dp[0][j];
            int withThisCoin = currentCoinValue <= j ? dp[1][j - currentCoinValue] : 0;
    
            dp[1][j] = (withoutThisCoin% 1000007 + withThisCoin% 1000007)% 1000007;
        }
        
        for(int j = 1; j <= B; j++)
        {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    return dp[0][B];
}
