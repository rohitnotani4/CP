/*

*/

string Solution::convert(string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(B <= 1 || B >= A.size())
        return A;
    
    string ans;
    int currentRow = 1;
    int size = A.size();
    int ansSize = 0,startIndex,nextIndex,noOfElements, down = 1;
    while(currentRow <= B)
    {
        nextIndex = startIndex = currentRow-1;
        ans.push_back(A[startIndex]);
        down = 0; 
        
        if(currentRow == 1 || currentRow == B)
            noOfElements = 2 *(B - 2) + 1;
        else
            noOfElements = 2 *(B - currentRow - 1) + 1;
            
            
        noOfElements = noOfElements <= 0 ? size : noOfElements;
        
        while( (nextIndex + noOfElements + 1) < size)
        {
            nextIndex = nextIndex + noOfElements + 1;
            ans.push_back(A[nextIndex]);
            
            if(currentRow == 1 || currentRow == B)
                noOfElements = 2 *(B - 2) + 1;
            else
            {
               if(down)
                {
                    noOfElements = 2 *(B - currentRow - 1) + 1;    
                    down = 0;
                }
                else
                {
                    noOfElements = 2 *(currentRow - 2) + 1;
                    down = 1;
                }
            }
            
        }
        currentRow++;
    }
    return ans;   
}
