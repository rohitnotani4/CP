/*
https://www.interviewbit.com/problems/square-root-of-integer/
*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int i=1, left = 1, right = A, mid,ans;
    if(A==0 || A==1)
        return A;
    
    while(left<=right)
    {
        mid = left + (right - left)/2;
        
        if(mid * mid == A)
            return mid;
        else
        if(mid * mid > A)
            right = mid - 1;
        else
        {
            left = mid + 1;
            ans = mid;
        }
    }
    
    return ans;
}
