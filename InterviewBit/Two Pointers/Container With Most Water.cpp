/*
https://www.interviewbit.com/problems/container-with-most-water/
*/

int Solution::maxArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxArea = 0,currArea = 0,currMax=0,leftIndex = 0, rightIndex = A.size()-1;
    maxArea = (A.size()-1) * min(A[0], A[A.size()-1]);
 
    while(leftIndex < rightIndex)
    {
        if(A[leftIndex] <= A[rightIndex])
        {
            leftIndex += 1;
            currMax = A[rightIndex];
            currArea = abs(rightIndex - leftIndex) * min(A[leftIndex],currMax);
        }
        else
        {
            rightIndex -= 1;
            currMax = A[leftIndex];
            currArea = abs(rightIndex - leftIndex) * min(A[rightIndex],currMax);
        }
        
        if(currArea > maxArea)
            maxArea = currArea;
    }
    return maxArea;
}
