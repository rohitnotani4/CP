/*
https://www.interviewbit.com/problems/spiral-order-matrix-ii/
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
        // DO STUFF HERE AND POPULATE result
    vector<vector<int> > result(A, vector<int>(A,0));
    
    if(A==0)
        return result;
    int T=0,B=A-1,L=0,R=A-1, dir = 0;
    
    int number = 1;
    while(T<=B && L<=R)
    {
        if(dir==0) // Traverse Left to Right
        {
            for(int j=L;j<=R;j++)
                result[T][j] = number++;
            T++;
        }
        else
        if(dir==1) // Traverse Top to Bottom
        {
            for(int i=T;i<=B;i++)
                result[i][R] = number++;
            R--;
        }
        else
        if(dir==2)
        {
            for(int j=R;j>=L;j--)
                result[B][j] = number++;
            B--;
        }
        else
        {
            for(int i=B;i>=T;i--)
                result[i][L] = number++;
            L++;    
        }
        dir = (dir + 1)%4;
    }
    
    return result;
}
