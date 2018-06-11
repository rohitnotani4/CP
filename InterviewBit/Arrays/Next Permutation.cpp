/*
https://www.interviewbit.com/problems/next-permutation/
*/

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //Find the last pair 
    
    int swapIndex = -1;
    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i] < A[i+1])
        {
            swapIndex = i;
            break;
        }
    }
    
    if(swapIndex ==-1)
    {
        sort(A.begin(), A.end());
        return ;
    }
    
    int l = -1;
    for(int j=A.size()-1;j>swapIndex;j--)
    {
        if(A[j] > A[swapIndex])
        {
            l = j;
            break;
        }
    }
    
    int temp = A[l];
    A[l] = A[swapIndex];
    A[swapIndex] = temp;
    
    
    sort(A.begin()+swapIndex+1, A.end());
    return ;
}
