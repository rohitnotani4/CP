/*
https://www.interviewbit.com/problems/pascal-triangle/
*/

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > result;
    if(A >=1)
        result.push_back(vector<int>(1,1));

    if(A >=2)
        result.push_back(vector<int>(2,1));
        
    for(int rowNumber=2;rowNumber<A;rowNumber++)
    {
        vector<int> currentRow(rowNumber+1,0);
        result.push_back(currentRow);
        for(int j=0;j<=rowNumber;j++)
        {
            if(j==0 || j==rowNumber)
		       result[rowNumber][j] = result[rowNumber-1][0];
            else
               result[rowNumber][j] = result[rowNumber-1][j] + result[rowNumber-1][j-1];
        }
    }
    return result;
}
