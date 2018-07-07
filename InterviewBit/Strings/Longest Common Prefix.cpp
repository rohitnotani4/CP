/*
https://www.interviewbit.com/problems/longest-common-prefix/
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 1)
        return A[0];
    
    int minStringSize = A[0].size();
    for(int i=1;i<A.size();i++)
    {
        int size = A[i].size();
        minStringSize = min(minStringSize, size);
    }
    
    string ans;
    for(int j=0;j<minStringSize;j++)
    {
        for(int i=1;i<A.size();i++)
        {
            if(A[i][j] != A[i-1][j])
                return ans;
        }
        ans.push_back(A[0][j]);
    }
    return ans;
}
