/*
https://www.interviewbit.com/problems/reverse-bits/
*/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int test = 1;
    unsigned int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(A & test)
        {
            ans = ans | ((unsigned int)pow(2,32-i-1));
        }
        test = test << 1;
    }
    return ans;
}
