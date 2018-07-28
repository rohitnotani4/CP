/*
https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = A.size(), n = B.size();
    if(m+n < 1)
        return ;
        
    A.resize(m+n);
    
    int AIndex = m-1;
    int BIndex = n-1;
    
    int k = m+n-1;
    while(BIndex >=0 && AIndex >=0)
    {
        if(A[AIndex] >= B[BIndex])
        {
            A[k] = A[AIndex];
            AIndex--;
        }
        else
        {
            A[k] = B[BIndex];
            BIndex--;
        }
        k--;
    }
    
    while(BIndex >=0)
    {
        A[k] = B[BIndex];
        BIndex--;
        k--;
    }
    
    while(AIndex >=0)
    {
        A[k] = A[AIndex];
        AIndex--;
        k--;
    }
}
