/*
https://www.interviewbit.com/problems/ways-to-decode/
*/

int numDecodingsHelper(string& s, vector<int>& memo, int index)
{
    if(memo[index] > -1)
        return memo[index];
           
    if(s[index] =='0')
    {
        memo[index] = 0;
        return memo[index];
    }
    
    int result = numDecodingsHelper(s, memo, index + 1);
    if (index < s.size()-1 && (s[index]=='1'|| s[index]=='2'&& s[index+1] <'7'))
    {
        result += numDecodingsHelper(s, memo, index + 2);
    }
    
    memo[index] = result;
    return memo[index];
}
    
int Solution::numDecodings(string A) 
{
    int length = A.size();
    vector<int> memo(length + 1, -1);
    memo[length] = 1;
    return A.empty() ? 0 : numDecodingsHelper(A, memo, 0);
}
