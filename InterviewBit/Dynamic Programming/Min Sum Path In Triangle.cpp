/*
https://www.interviewbit.com/problems/min-sum-path-in-triangle/
*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 1)
        return 0;

    int rows = A.size();
    vector<int> minSumDP(A.back()); // Assign last row to DP array
    
    for(int i = rows-2;i>=0;i--)
    {
        for(int j=0;j<A[i].size();j++)
        {
            minSumDP[j] = min (minSumDP[j], minSumDP[j+1]) + A[i][j];
        }
    }    
    return minSumDP[0];        
}
