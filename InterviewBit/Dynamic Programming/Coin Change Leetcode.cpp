/*
https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        vector<int> dp(amount+1, amount+1);
        return BottomUpDP(coins, amount, dp);
    }
    
    int TopDownDP(vector<int>& coins, int remainder, vector<int>& dp)
    {
        if (remainder < 0)
            return -1;
        
        if(remainder == 0)
            return 0;      
        
        if (dp[remainder - 1] != 0) 
            return dp[remainder - 1];
        
        int minimum = INT_MAX;
        for(int i = 0;i<coins.size();i++)
        {
           int changeResult = TopDownDP(coins, remainder - coins[i], dp);
            
            if (changeResult >= 0 && changeResult < minimum)
            {
                minimum = 1 + changeResult;
            }
        }
        
        dp[remainder-1] = (minimum == INT_MAX ? -1 : minimum);
        return dp[remainder - 1];
    }
    
    int BottomUpDP(vector<int>& coins, int amount, vector<int>& dp)
    {        
        dp[0] = 0;
        for(int j=1;j<=amount;j++)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(j - coins[i] >= 0)
                {
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
                }                
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
