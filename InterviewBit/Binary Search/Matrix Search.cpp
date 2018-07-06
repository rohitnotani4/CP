/*
https://www.interviewbit.com/problems/matrix-search/
*/

int customRowBinarySearch(vector<vector<int> > &A, int B)
{
    int rowSize = A[0].size();
    int left = 0,right = A.size()-1,mid;
    
    while(left <= right)
    {
        mid = left + (right - left)/2;
        if(B >= A[mid][0] && B <= A[mid][rowSize-1])
            return mid;
        else
        if(A[mid][rowSize-1] < B)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}

int customBinarySearch(vector<vector<int> > &A, int element,int rowNum)
{
    int left = 0,right = A[0].size()-1,mid;
    
    while(left <= right)
    {
        mid = left + (right - left)/2;
        
        if(A[rowNum][mid] == element)
            return 1;
        else
        if(A[rowNum][mid] < element)
            left = mid+1;
        else
            right = mid-1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int rowToSearch = customRowBinarySearch(A,B);    
    // cout<<"Row to search "<<rowToSearch<<"\n";
    if(rowToSearch == -1)
        return 0;
    return customBinarySearch(A,B,rowToSearch);   
}
