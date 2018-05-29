/*
https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    int curr_max = A[0]; 
    int max_sum = A[0];
    for (int i=1;i<A.size();i++)
    {
        curr_max = max(A[i],curr_max+A[i]);
        max_sum = max(curr_max,max_sum);
    }

    return max_sum;
}

