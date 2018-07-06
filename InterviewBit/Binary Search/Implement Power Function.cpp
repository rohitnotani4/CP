/*
https://www.interviewbit.com/problems/implement-power-function/
*/

int solve(long int x,long int n,long long int d)
{
    long long int temp = 0;
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    if(n==1)
        return x%d;
        
    temp = solve(x,n/2,d);
    long long  evenProd = ( (temp%d) * (temp%d) )%d; // (a*b)%c = ((a%c) * (b%c))%c
    if(n%2==0)
        return evenProd;
    else
        return ( (x%d) * evenProd)%d;
}

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans;
    ans = solve(x,n,d);
    if(ans < 0)
        return ans + d;
    else
        return ans;
}
