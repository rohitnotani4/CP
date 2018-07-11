/*
https://www.interviewbit.com/problems/atoi/
*/

int Solution::atoi(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int index = 0, result = 0;
    bool isPositive = true;
    
    while(A[index]==' ')
        index++;
    
    if(A[index]=='-' || A[index]=='+')
    {
        isPositive = (A[index]=='-') ? false : true;
        index++;
    }
    
    while(A[index] >= '0' && A[index] <= '9')
    {
        if(result > INT_MAX/10 || (result == INT_MAX/10 && A[index]-'0' > 7))
        {
            if(isPositive)
                return INT_MAX;
            return INT_MIN;
        }
        result = result * 10 + (A[index]-'0');
        index++;
    }
    
    if(isPositive)
        return result;
    
    return -1*result;
}
