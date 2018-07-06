int findByBinarySearch(const vector<int> &A, int low, int high, int key)
{
    int start = 0, end = A.size()-1, mid;
    while(start<=end)
    {
        mid = start + (end - start)/2;
        
        if(A[mid] == key)
            return mid;
            
        if(A[start] == A[mid] && A[mid] == A[end]) // This condition helps with duplicates
        {
            ++start;
            --end;
        }
        else
        if(A[start] <= A[mid]) // Left part is sorted
        {
            if(key >= A[start] && key < A[mid]) 
                end = mid-1;
            else 
                start = mid+1; 
        }
        else // Right part is sorted
        {
            if(key > A[mid] && key <= A[end]) 
                start = mid+1;
            else 
                end = mid-1; 
        }
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans = findByBinarySearch(A,0,A.size()-1,B);
    return ans;
}
