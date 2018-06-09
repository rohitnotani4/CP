/*
https://www.interviewbit.com/problems/set-matrix-zeros/
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n=A.size(), m=A[0].size();
    int firstRow=0, firstCol=0;
    for(int j=0; j<m && !firstRow; j++)
    {
        if(A[0][j]==0) 
            firstRow = 1;
    }
    
    for(int i=0; i<n && !firstCol; i++)
    {
        if(A[i][0] == 0) 
            firstCol = 1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<A[i].size(); j++)
        {
            if(A[i][j]==0)
            {
                A[0][j] = 0; 
                A[i][0] = 0;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        if(A[i][0]==0)
        {
            for(int j=0; j<A[i].size(); j++) 
                A[i][j]=0;
        }
    }
    for(int j=1; j<m; j++)
    {
        if(A[0][j]==0)
        {
            for(int i=0; i<n; i++) 
                A[i][j]=0;
        }
    }
    //cout<<firstRow<<" "<<firstCol<<" ";
    if(firstRow) 
        for(int j=0; j<m; j++)
            A[0][j]=0;
    if(firstCol) 
        for(int i=0; i<n; i++) 
            A[i][0]=0;
}
