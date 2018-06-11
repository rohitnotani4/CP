/*
https://www.interviewbit.com/problems/rotate-matrix/
*/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    int n = A.size();
    int left=0,right=n-1,top=0,bottom=n-1;

    while(left < right)
    {
        //i=1, i < 12, left = 1, bottom = 12,right=12 
        for(int i=0;i<right-left;i++)
        {
            int temp = A[bottom-i][left]; 
            A[bottom-i][left] = A[bottom][right-i];
            A[bottom][right-i] = A[top+i][right];
            A[top+i][right] = A[top][left+i];
            A[top][left+i] = temp;
            
        }
        left++;
        right--;
        top++;
        bottom--;
    }
}
