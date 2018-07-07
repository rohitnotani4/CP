/*
https://www.interviewbit.com/problems/palindrome-string/
*/

bool isAlphanumeric(char c)
{
    if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
        return true;
    return false;
}

int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() < 2)
        return 1;

    int start=0, end=A.size()-1;
    while(start<end)
    {
        while(start<end && !isAlphanumeric(A[start]))
            start++;

        while(end>start && !isAlphanumeric(A[end]))
            end--;

        if(A[start]!=A[end] && (abs((A[start]-'0') - (A[end]-'0'))!=32))
            return 0;

        start++;
        end--;
    }
    return 1;
}
