/*
https://www.interviewbit.com/problems/array-3-pointers/
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{

    int result = INT_MAX;

    int i = 0, j = 0, k = 0;
    while(i<A.size() && j < B.size() && k < C.size())
    {

        int minimum = min(A[i], min(B[j], C[k]));
        int maximum = max(A[i], max(B[j], C[k]));

        // Update result if current diff is less than the min
        // diff so far
        if (maximum-minimum < result)
        {
             result = maximum - minimum;
             if(result == 0)
                break;
        }

        if(A[i]==minimum)
            i++;
        else
        if(B[j]==minimum)
            j++;
        else
            k++;
    }
    return result;
}
