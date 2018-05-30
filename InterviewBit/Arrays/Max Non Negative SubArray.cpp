/*
https://www.interviewbit.com/problems/max-non-negative-subarray/
*/

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result;
    int currentStart= -1, currentEnd= -1, resultStart= -1, resultEnd=0;
    long currentSum = 0, maxSum = -1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] >=0)
        {
            currentSum += A[i];
            currentStart = currentStart == -1 ? i : currentStart;
            currentEnd = i;
        }
        else
        {
            currentSum = 0;
            currentStart = currentEnd = -1;
        }
        
        if(currentSum > maxSum
            || (currentSum == maxSum && (currentEnd-currentStart) > (resultEnd - resultStart)))
        {
            maxSum = currentSum;
            resultStart = currentStart;
            resultEnd = currentEnd;
        }
    }
    for(int i=resultStart;i>=0 && i<=resultEnd;i++)
    {
        result.push_back(A[i]);
    }

    return result;
}
