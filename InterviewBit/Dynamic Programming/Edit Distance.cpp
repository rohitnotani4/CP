/*
https://www.interviewbit.com/problems/edit-distance/
*/

int Solution::minDistance(string A, string B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int editDistance[A.size()+1][B.size()+1];
    for(int i=0;i<=A.size();i++)
        editDistance[i][0] = i;
    
    for(int j=0;j<=B.size();j++)
        editDistance[0][j] = j;
        
    for(int i=1;i<=A.size();i++)
    {
        for(int j=1;j<=B.size();j++)
        {
            if(A[i-1]==B[j-1])
                editDistance[i][j] = editDistance[i-1][j-1];
            else
                editDistance[i][j] = 1 + min(editDistance[i][j-1], min(editDistance[i-1][j], editDistance[i-1][j-1]));        }                                           
    }
    
    return editDistance[A.size()][B.size()];
}
