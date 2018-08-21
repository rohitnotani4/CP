/*
https://www.interviewbit.com/problems/valid-sudoku/
*/

int Solution::isValidSudoku(const vector<string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows[9][9] = {0}, columns[9][9] ={0}, subset[9][9] ={0};
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j] != '.')
            {
                int number = A[i][j] - '0' - 1;
                int subsetIndex = (i/3) * 3 + (j/3);
                if(rows[i][number] > 0 || columns[j][number] > 0 || subset[subsetIndex][number] > 0)
                    return 0;
                else
                {
                    rows[i][number] = 1; 
                    columns[j][number] = 1;
                    subset[subsetIndex][number] = 1;
                }
            }
        }
    }
    return 1;
}
