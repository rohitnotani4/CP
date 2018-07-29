/*
https://www.interviewbit.com/problems/sort-by-color/
*/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int countBlue = 0, countRed = 0,countWhite = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 0)
            countRed++;
        else
        if(A[i] == 1)
            countWhite++;
        else
            countBlue++;
    }
    
    
    for(int i=0;i<countRed;i++)
        A[i] = 0;
        
    for(int i=countRed;i<(countRed+countWhite);i++)
        A[i] = 1; 
        
    for(int i=countRed+countWhite;i<(countRed+countWhite+countBlue);i++)
        A[i] = 2; 
    
}
