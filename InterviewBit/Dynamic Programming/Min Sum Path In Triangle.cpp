/*
https://www.interviewbit.com/problems/min-sum-path-in-triangle/
*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 1)
	    return 0;
 
    if(A.size()==1)
	    return A[0][0];
	    
	int inputSize = A.size();	
	//cout<<"No of rows "<<inputSize<<"\n";
    vector<int> prevRow(inputSize), currRow(inputSize);
    prevRow[0] = A[0][0];
    for(int i=1;i<inputSize;i++)
    {
    	for(int j=0;j<(i+1);j++)
    	{
    		if(j==0)
    			currRow[j] = prevRow[j] + A[i][j];
    		else
    		if(j==i)
    			currRow[j] = prevRow[j-1] + A[i][j];
    		else
    			currRow[j] = min(prevRow[j-1]+A[i][j], prevRow[j] + A[i][j]);
    	}
    	// prevRow.clear();
    	prevRow = currRow;
    }
    
    int minSum = currRow[0];
    for(int i=1;i<inputSize;i++)
    	minSum = min(minSum,currRow[i]);
    
    return minSum;	    
}
