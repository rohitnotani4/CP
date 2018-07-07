/*
https://www.interviewbit.com/problems/palindrome-string/
*/

int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() < 2)
    return 1;

    string alphanumeric;
    for(int i=0;i<A.size();i++)
    {
        if( (A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122) || (A[i] >= 48 && A[i] <= 57) )
            alphanumeric.push_back(A[i]);
    }
    // cout<<alphanumeric<<"\n";
    int n = alphanumeric.size();
    int mid = n/2;
    for(int i=0,j=n-1;i<mid;i++,j--)
    {
        if(alphanumeric[i] >= 65 && alphanumeric[i] <= 90)
        {

            if(alphanumeric[i] ==  alphanumeric[j] || char(alphanumeric[i]+32) == alphanumeric[j])
            {

            }
            else
                return 0;

        }
        else
        if(alphanumeric[i] >= 'a' && alphanumeric[i] <='z')
        {

            if(alphanumeric[i] == alphanumeric[j] || char(alphanumeric[i]-32) == alphanumeric[j])
            {

            }
            else
                return 0; 
        }
        else
        {
            if(alphanumeric[i] != alphanumeric[j])
                return 0;
        }
    }
    return 1;
}
