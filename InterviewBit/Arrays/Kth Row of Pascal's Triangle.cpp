/*
https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> result,prevRow;
    if(A>=0)
        result.push_back(1);
    
    for(int columnNumber=0;columnNumber<A;columnNumber++)
    {
        prevRow = result;
        for(int j=0;j<=columnNumber+1;j++)
        {
            if(j==0)
	    	result[j] = prevRow[j];
	    else if(j==(columnNumber+1))
                result.push_back(prevRow[0]);
            else
                result[j] = prevRow[j] + prevRow[j-1];
        }
    }
    return result;
}
