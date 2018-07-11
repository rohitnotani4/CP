/*
https://www.interviewbit.com/problems/power-of-2/
*/

int isPowerOf2(string& number)
{
    if(number.size()==1 && (number[0]-'0')==1)
    {
        return  1;
    }
    
    if((number[number.size()-1]-'0')%2==0)
    {
        string newDividend;
        int i = 0, carry = 0;
        while(i < number.size())
        {
            int digit = carry * 10 + (number[i]-'0');
            if(digit < 2 && i+1 < number.size())
            {
                i++;
                if(newDividend.size() > 0)
                {
                    newDividend.push_back(0 +'0');
                    // cout<<0;
                }
                digit = digit * 10 + (number[i]-'0');
            }
            carry = digit%2;
            // cout<<digit/2;
            newDividend.push_back((digit/2)+'0');
            i++;
        }
        // cout<<"\n";
        return isPowerOf2(newDividend);
    }
    return 0;
}

int Solution::power(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if((A[A.size()-1]-'0')<2)
    {
        return 0;
    }
    int ans = isPowerOf2(A);
    return ans;
}
