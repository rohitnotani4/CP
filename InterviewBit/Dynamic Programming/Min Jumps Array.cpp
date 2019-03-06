/*
https://www.interviewbit.com/problems/min-jumps-array/
*/

int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() <= 1)
        return 0;
    
    if(A[0]==0)
        return -1;
    int inputSize = A.size(), maxReach = A[0],step = A[0],jump = 1;
    int dp[inputSize];
    dp[0] = 0;
    
    for(int i=1;i<inputSize;i++)
    {
        if(i==inputSize-1)
            return jump;
            
        maxReach = max(maxReach,i+A[i]);
        
        step--;
        
        if (step == 0)
        {
            jump++;
            if(i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }
    return -1;
}
