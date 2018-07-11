/*
https://www.interviewbit.com/problems/add-binary-strings/
*/

string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string minString="",maxString="",result="";
    int sizeOfA, sizeOfB, max;
    sizeOfA = A.size();
    sizeOfB = B.size();
    
    
    for(int i=0;i<abs(sizeOfA - sizeOfB);i++)
        minString.push_back('0');
    
    if(sizeOfA > sizeOfB)
    {
        minString += B;
        maxString += A;
    }
    else
    {
        minString += A;
        maxString += B;
    }  
    
    int ans, carry = 0;
    for(int i=minString.size()-1;i>=0;i--)
    {
        
        ans = (minString[i]-'0') ^ (maxString[i]-'0') ^ carry;
        carry = ( (minString[i]-'0') & (maxString[i]-'0') ) || ( (minString[i]-'0') & (carry) ) || ( (maxString[i]-'0') & carry);    
        
        minString[i] = ans + '0';
    }
    
    if(carry)
        result += '1';
    
    result += minString;
    return result;

}
