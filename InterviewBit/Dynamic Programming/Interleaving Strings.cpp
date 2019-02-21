/*
https://www.interviewbit.com/problems/interleaving-strings/
*/

int Solution::isInterleave(string s1, string s2, string s3) 
{
    int s3len = s3.length();
    int s1len = s1.length();
    int s2len = s2.length();
    
    if(s3len != s1len + s2len)
        return false;
    
    bool dp[s1len+1][s2len+1];
    
    for(int i=0;i<=s1len;i++)
    {
        for(int j=0;j<=s2len;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = true;
            }
            else
            if(i==0)
            {
                // s1 is empty, so check if s2 is interleaved in s3 until j-1
                // and also if the current character is interleaved in s3
                // If both are true, then s2 is interleaved
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]); 
            }
            else
            if(j==0)
            {
                // Same reason as above, just that here string s2 is empty
                dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
            }
            else
            if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
            {                    
                // Current character of s1 matches with current character of s3, 
                // but doesn't match with current character of s2 
                dp[i][j] = dp[i-1][j];
            }
            else
            if(s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1])
            {
                // Current character of s2 matches with current character of s3, 
                // but doesn't match with current character of s1 
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                // Current character of s3 matches with that of both s1 and s2 
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1])
                        || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
    }
        
    return dp[s1len][s2len];
}
