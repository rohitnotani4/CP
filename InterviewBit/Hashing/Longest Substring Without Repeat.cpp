/*
https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int Solution::lengthOfLongestSubstring(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<char,int> duplicateChar;
    int start =0, end = 0, maxLen = 0;
    while(start <= end && end < A.size())
    {
        duplicateChar[A[end]]++;
        while(start <= end && duplicateChar[A[end]] > 1)
        {
            duplicateChar[A[start]]--;
            start++;
        }
        end++;
        maxLen = max(maxLen, end - start);
    }
    return maxLen;
}
