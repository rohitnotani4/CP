/*
https://www.interviewbit.com/problems/square-root-of-integer/
*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==0 || A==1)
        return A;
    
    long long int start = 0, end = A, mid,prevMid;
    double diff, precision = 0.0005;
    prevMid = 0;
    mid = start + (end - start)/2;
    diff = abs(mid - prevMid);
    while((mid*mid) != A && diff > precision)
    {
        if(mid * mid > A)
            end = mid;
        else
            start = mid;
        prevMid = mid;
        mid = start + (end - start)/2;
        diff = abs(mid - prevMid);
    }
    return mid;
}
