/*
https://www.interviewbit.com/problems/divide-integers/
*/

int Solution::divide(int A, int B) 
{
    int dividend = A, divisor = B;
    
    if(!divisor || (dividend==INT_MIN && divisor==-1))
        return INT_MAX;
    
    // Check if both are negative/positive using XOR
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int ans = 0;    
    while(dvd >= dvs)
    {
        long long temp = dvs, multiple = 1;
        while(dvd >= (temp<<1))
        {
            temp <<= 1;
            multiple <<= 1;
        }
        
        dvd -= temp;
        ans += multiple;
    }
    return sign == 1 ? ans : -ans;
}
