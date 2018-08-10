/*
https://www.interviewbit.com/problems/minimize-the-absolute-difference/
*/

char calculateMin(vector<int> &A, vector<int> &B, vector<int> &C,int i,int j,int k)
{
    char minEleArray;
    if(A[i] <= B[j] && A[i] <= C[k])
    {
        minEleArray='A';
    }
    else
    if(B[j] <= A[i] && B[j] <= C[k])
    {
        minEleArray='B';
    }
    else
        minEleArray='C';
        
    return minEleArray;
}
 
 
int calculateMaxMinDiff(vector<int> &A, vector<int> &B, vector<int> &C,int i,int j,int k)
{
    return abs(max(max(A[i],B[j]),C[k]) - min(min(A[i],B[j]),C[k]));
}
 
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int totalSize = A.size() + B.size() + C.size();
    int minEleIndex = 0, minDiff,currDiff;
    
    
    char minEleArray;
    minDiff = INT_MAX;
    for(int i=0,j=0,k=0;i<A.size() && j<B.size() && k < C.size();)
    {
        currDiff = calculateMaxMinDiff(A,B,C,i,j,k);
        if(currDiff < minDiff)
            minDiff = currDiff;
        
        minEleArray = calculateMin(A,B,C,i,j,k);
        // Increase the min 
        if(minEleArray == 'A')
            i++;
        else
        if(minEleArray == 'B')
            j++;
        else
            k++;
    }
    return minDiff;
}
