/*
https://www.interviewbit.com/problems/regular-expression-ii/
*/

int Solution::isMatch(const string &s, const string &p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int textSize, patternSize;
    
    textSize = s.empty() ? 0 : s.size();
    patternSize = p.empty() ? 0 : p.size();
    
    vector<vector<bool> > dp(textSize+1, vector<bool>(patternSize+1));
    // int dp[textSize+1][patternSize+1];
    dp[0][0] = true;
    
    for(int i=1;i<=textSize;i++)
        dp[i][0] = false;
    
    for(int j=1;j<=patternSize;j++)
    {
        if(p[j-1]=='*')
            dp[0][j] = dp[0][j-2];
        else
            dp[0][j] = false;
    }
    
    for(int i=1;i<=textSize;i++)
    {
        for(int j=1;j<=patternSize;j++)
        {
            if(p[j-1]=='.' || p[j-1] == s[i-1])
                dp[i][j] = dp[i-1][j-1];
            else
            if(p[j-1]=='*')
            {
                dp[i][j] = dp[i][j-2];
                if(p[j-2]=='.' || p[j-2] == s[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
            }
            else
                dp[i][j] = false;
        }
    }
    
    return dp[textSize][patternSize];
}
