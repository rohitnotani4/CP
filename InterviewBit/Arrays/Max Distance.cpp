/*
https://www.interviewbit.com/problems/max-distance/
*/

Solution : O(n) time complexity and O(n) space complexity
int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxProfit = 0;
    if(A.size() < 2)
        return maxProfit;
    
    int LeftMin[A.size()], RightMax[A.size()];
    
    LeftMin[0] = A[0];
    for(int i=1;i<A.size();i++)
    {
        LeftMin[i] = min(LeftMin[i-1],A[i]);
    }
    
    RightMax[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        RightMax[i] = max(RightMax[i+1],A[i]);
    }
    
    int i=0,j=0;
    while(i < A.size() && j < A.size())
    {
        if(LeftMin[i] <= RightMax[j])
        {
            maxProfit = max(maxProfit, j-i);
            j++;
        }
        else
            i++;
    }
    
    return maxProfit;
}
