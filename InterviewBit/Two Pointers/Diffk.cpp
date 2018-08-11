/*
https://www.interviewbit.com/problems/diffk/
*/

int Solution::diffPossible(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, size = A.size(), j=0,ans = 0;

    if(size > 1)
    {
        for(int i=0;i<size;i++)
        {
            j = max(i+1,j);
            while(j < size && (A[j]-A[i] < B))
                j += 1;
            if(i !=j && A[j]-A[i] == B)
            {
                ans=1;
                return ans;
            }
        }
    }
    return ans;
}
