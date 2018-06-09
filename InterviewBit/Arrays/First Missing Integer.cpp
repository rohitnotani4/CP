/*
https://www.interviewbit.com/problems/first-missing-integer/
*/

// This approach doesn't delete the negative array elements instead it shifts them to the left of array
// Hence all the calculation for making the array value at index negative involves use of shift value.

void Swap(vector<int> &A, int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int MoveAllNonPositiveToLeftSide(vector<int> &A)
{
    int j = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] <= 0)
        {
            Swap(A,i,j);
            j++;
        }
    }
    return j;
}

int FindFirstMissingPositive(vector<int> &B, int shift)
{
    vector<int>::iterator it = B.begin() + shift;
    
    int positiveElements = B.size() - shift;

    for(;it!=B.end();it++)
    {
        if(abs(*it)-1 < positiveElements) 
        { 
            B[abs(*it)+shift-1] = -B[abs(*it)+shift - 1];
        }
    }


    int j=0;
    for(it = B.begin() + shift;it!=B.end();it++)
    {
        if(*it > 0) 
            return j+1;
        j++;
    }
    
    return positiveElements+1;
}

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int shift = MoveAllNonPositiveToLeftSide(A);
    return FindFirstMissingPositive(A,shift);
}
