/*
https://www.interviewbit.com/problems/regular-expression-match/
*/

string getOptimisedPattern(const string &p)
{
    string optPattern;
    int i = 0;
    while(i < p.size())
    {
        if(p[i] == '*')
        {
            optPattern.push_back(p[i]);
            while(i < p.size() && p[i] == '*')
                i++;
        }
        else
        {
            optPattern.push_back(p[i]);
            i++;
        }
    }
    return optPattern;
}

int Solution::isMatch(const string s, const string p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(s.size() < 0 || p.size() < 0)
        return 0;
    
    // string text = s;
    string optPattern = getOptimisedPattern(p);;
    int textSize = s.size();
    int patternSize = optPattern.size();
    vector<vector<bool>> dp(textSize+1, vector<bool>(patternSize+1));
    
    if (optPattern.size() == 1 && optPattern[0] == '*')
        return 1;
    
    // An empty string would match with empty pattern
    dp[0][0] = 1;
    
    // An empty pattern wouldn't match with any text having length > 0
    for(int i=1;i<=textSize;i++)
        dp[i][0] = 0;

    for(int j=1;j<=patternSize;j++)
    {
        if (optPattern[j-1]=='*')
            dp[0][j] = dp[0][j-1];
        else
            dp[0][j] = 0;
    }
    
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[i].size();j++)
        {
            if (s[i-1] == optPattern[j-1] || optPattern[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            if(optPattern[j-1]=='*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }    
    return dp[textSize][patternSize];
}
