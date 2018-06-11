/*
https://www.interviewbit.com/problems/next-permutation/
*/

void Swap(vector<int> &A, int i,int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void reverseSort(vector<int> &A, int start,int end)
{
    while(start < end)
    {
        Swap(A,start,end);
        start++;
        end--;
    }
}

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int size = A.size();
    if(size<2)
        return;
        
    int swapIndex = -1;
    for(int i=size-2;i>=0;i--)
    {
        if(A[i] < A[i+1])
        {
            swapIndex = i;
            break;
        }
    }
    
    if(swapIndex ==-1)
    {
        reverseSort(A, 0, size-1);
        return ;
    }
    else
    {
        int j = size-1;
        while(j>swapIndex)
        {
           if(A[j] > A[swapIndex])
                break;
           j--;
        }
            
        Swap(A, swapIndex, j);
        reverseSort(A, swapIndex+1, size-1);
    }
    
    return ;
}
