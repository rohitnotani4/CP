/*
https://www.interviewbit.com/problems/jump-game-array/
*/

int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 2)
        return 1;
    
    vector<int> canReach(A.size(),-1);
    
    int canReachMaxIndex = A[0];
    for(int i=0;i<A.size();i++)
    {
        
        if(canReachMaxIndex <=i && A[i] == 0)
            return 0;
        
        if(i + A[i] > canReachMaxIndex)
            canReachMaxIndex = i+A[i];
        
        if(canReachMaxIndex >= A.size()-1)
            return 1;
    }    
    return 0;
}
