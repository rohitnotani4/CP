/*
https://www.interviewbit.com/problems/coin-sum-infinite/
*/

int Solution::coinchange2(vector<int> &A, int B) 
{
    if(B==0)
        return 1;
    
    if(A.size() < 1)
        return 0;
    
    vector<int> dp(B+1,0);
    dp[0] = 1;
    
    for(int i=0;i<A.size();i++)
    {
        for(int denomination = A[i];denomination <= B; denomination++)
        {
            dp[denomination] = (dp[denomination]%1000007 + dp[denomination - A[i]]%1000007)%1000007;
        }
    }
    return dp[B];
}
