/*
https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int checkMaxSubstring(int *count,char currentChar)
{
    int j = ((int)currentChar);
    if(count[j] >= 1)
    {
        return 1; // cout<<"Reset !!!"<<"\n";
    }
    else
        count[j]++;
    
    return 0;
}

int Solution::lengthOfLongestSubstring(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxLen = 0;
    for(int i=0,j;i<A.size();i++)
    {
        int count[128] = {0}, reset = 0, currLen = 0;

        j=i;
        while(j < A.size() && !reset)
        {
            reset = checkMaxSubstring(count, A[j]);
            if(reset)
                break;
            currLen += 1;
            j++;
        }
        maxLen = currLen > maxLen ? currLen : maxLen;
    }
    
    return maxLen;
}
