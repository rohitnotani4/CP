/*
https://www.interviewbit.com/problems/sorted-insert-position/
*/

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.empty()) 
        return -1;
    if(B <= A[0])
        return 0;
    if(B > A[A.size()-1])
        return A.size();
        
    int low = 0, mid, high = A.size()-1;
    while(low <= high)
    {
        mid = low + ((high - low)/2);
        
        if(A[mid] == B)
            return mid;
        else
        if(A[mid] > B)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
