/*
https://www.interviewbit.com/problems/regular-expression-ii/
*/

int Solution::isMatch(const string s, const string p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int textSize = s.size();
    int patternSize = p.size();
    
    vector<vector<bool> > dp(textSize+1, vector<bool>(patternSize+1));

    // An empty string would match with empty pattern so dp[0][0] = 'T'
    dp[0][0] = true;
    
    // An empty pattern wouldn't match with any text having length > 0. 
    // So T[i][0] = 'F' for all i > 0 and i < length of text
    for(int i=1;i<=textSize;i++)
        dp[i][0] = false;
    
    // A non empty pattern will match with an empty text only if the pattern is of type a*, a*b* etc.
    for(int j=1;j<=patternSize;j++)
    {
        if(p[j-1]=='*' && j-2 >= 0)
            dp[0][j] = dp[0][j-2];
        else
            dp[0][j] = false;
    }
    
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[i].size();j++)
        {
            if(p[j-1]=='.' || p[j-1] == s[i-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            if(p[j-1]=='*')
            {
                dp[i][j] = dp[i][j-2];
                if(p[j-2]=='.' || p[j-2] == s[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = false;
            }
                
        }
    }
    return dp[textSize][patternSize];
}
