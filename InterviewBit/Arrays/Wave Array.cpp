/*
https://www.interviewbit.com/problems/wave-array/
*/

vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(),A.end());
    
    // Swap adjacent pairs
    int i=0;
    while(i+1 < A.size())
    {
        int temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
        i= i+2;
    }
    return A;
}
