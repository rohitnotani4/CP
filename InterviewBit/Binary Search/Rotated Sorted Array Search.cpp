/*
https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int findByBinarySearch(const vector<int> &A, int low, int high, int key)
{
    if(low > high)
        return -1;
    
    int mid = low + (high-low)/2;
    if(A[mid] == key)
        return mid;
        
    if(A[low] <= A[mid]) // low to mid is sorted
    {
        if(key >= A[low] && key <= A[mid])
            return findByBinarySearch(A,low,mid,key);
            
        return findByBinarySearch(A,mid+1,high,key);
    }
    
    if (key >= A[mid] && key <= A[high])
        return findByBinarySearch(A, mid+1, high, key);
 
    return findByBinarySearch(A, low, mid-1, key);
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans = findByBinarySearch(A,0,A.size()-1,B);
    return ans;
}
