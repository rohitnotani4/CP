/*
https://www.interviewbit.com/problems/median-of-array/
*/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    if (A.size() > B.size())
    {
        return findMedianSortedArrays(B,A);
    }
    
    int X = A.size();
    int Y = B.size();
    int total = (X + Y + 1)/2;
    int low = 0, high = X;
    int partionX, partionY,maxLeftX,maxLeftY,minRightX,minRightY;
    while(low <= high)
    {
        partionX = (low + high)/2;
        partionY = total - partionX;
        
        maxLeftX = partionX == 0 ? INT_MIN : A[partionX-1];
        minRightX = partionX == X ? INT_MAX : A[partionX];
        
        maxLeftY = partionY == 0 ? INT_MIN : B[partionY-1];
        minRightY = partionY == Y ? INT_MAX : B[partionY];
        
        if(maxLeftX<=minRightY && maxLeftY <= minRightX)
        {
            if((X+Y)%2)
                return max(maxLeftX,maxLeftY);
            else
                return ((max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2.0);
        }
        else
        if(maxLeftX > minRightY)
            high = partionX - 1;
        else
            low = partionX + 1;
    }
    return 0;
}
