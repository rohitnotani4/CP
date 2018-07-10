/*
https://www.interviewbit.com/problems/roman-to-integer/
*/

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    map<char,int> romanToInt;
    romanToInt['I']=1;
    romanToInt['V']=5;
    romanToInt['X']=10;
    romanToInt['L']=50;
    romanToInt['C']=100;
    romanToInt['D']=500;
    romanToInt['M']=1000;
    
    
    int i=0,size = A.size(),ans = 0;
    while(i<size)
    {
        if(i+1 < size && (romanToInt[A[i]] < romanToInt[A[i+1]]))
            ans -= romanToInt[A[i]];
        else
            ans += romanToInt[A[i]];
        i++;    
    }
    return ans;
}
