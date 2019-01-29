/*
https://www.interviewbit.com/problems/length-of-longest-subsequence/
*/

int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    int n=A.size();
    vector<int> lis (n,1);
    vector<int> lds (n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if (A[j] < A[i] && lis[i] < (lis[j] + 1))
                lis[i] = lis[j] + 1;
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if (A[j] < A[i] && lds[i] < (lds[j] + 1))
                lds[i] = lds[j] + 1;
        }
    }
    
    int maxLength = 0;
    for(int i=0;i<n;i++)
    {
        maxLength = max(maxLength, lis[i] + lds[i] - 1);
    }
    return maxLength;
}
