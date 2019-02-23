/*
https://www.interviewbit.com/problems/regular-expression-match/
*/

string getOptimisedPattern(const string &p)
{
    string optPattern;
    bool isFirst = true;
    for(int i=0;i<p.size();i++)
    {
        if(p[i]=='*')
        {
            if(isFirst)
            {
                optPattern.push_back(p[i]);
                isFirst = false;
            }
        }
        else
        {
            optPattern.push_back(p[i]);
            isFirst = true;
        }
    }
    return optPattern;
}
 
int Solution::isMatch(const string &s, const string &p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(s.size() < 0 || p.size() < 0)
        return 0;
    
    string optPattern = getOptimisedPattern(p);;
    int textSize, patternSize;
    textSize = s.empty() ? 0 : s.size();
    patternSize = optPattern.empty() ? 0 : optPattern.size();
    //cout<<"TextSize "<<textSize<<" OptPattern Size = "<<patternSize<<"\n";
    vector<vector<bool> > dp(textSize+1, vector<bool>(patternSize+1));
    //int dp[textSize+1][patternSize+1];
    dp[0][0] = 1;
    
    for(int i=1;i<=textSize;i++)
        dp[i][0] = 0;
    
    for(int j=1;j<=patternSize;j++)
    {
        if(optPattern[j-1]=='*')
            dp[0][j] = dp[0][j-1];
        else
            dp[0][j] = 0;
    }
    
    //if(patternSize > 0 && optPattern[0]=='*')
    //    dp[0][1] = true;
        
    for(int i=1;i<=textSize;i++)
    {
        for(int j=1;j<=patternSize;j++)
        {
            if(optPattern[j-1]=='?' || (optPattern[j-1] == s[i-1]))
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            if(optPattern[j-1]=='*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = 0;
            
            //cout<<"dp["<<i<<"]["<<j<<"]= "<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    
    return dp[textSize][patternSize];
}
