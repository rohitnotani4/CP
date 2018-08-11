/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
*/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int arraySize = A.size(), duplicateCount = 1;
    if(arraySize <= duplicateCount)
        return arraySize;
        
    int count = 1, currentIndex = 1, i =1, ;      
    while(i < arraySize)
    {
        if(A[i] != A[i-1])
        {
            count = 1;
            A[currentIndex++] = A[i];
        }
        else
        if(count < duplicateCount)
        {
            A[currentIndex++] = A[i];
            count++;
        }
        i++;
    }
    return currentIndex;
}
