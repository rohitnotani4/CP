/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
*/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 5
    int size = A.size();
    
    if(size <= 1)
        return size;
    
    int prevIndex = 0, currIndex = 1, uniqueElements = 1;
    while(currIndex < size)
    {
        if(A[currIndex] == A[prevIndex])
        {
            currIndex++;
        }
        else
        {
            A[uniqueElements] = A[currIndex];
            prevIndex = currIndex;
            uniqueElements++;
            currIndex++;
        }
    }
    
    while(uniqueElements <= A.size())
    {
        A.pop_back();
    }
    
    return uniqueElements;
}
