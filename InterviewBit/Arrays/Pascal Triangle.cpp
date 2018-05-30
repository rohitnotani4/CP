/*
https://www.interviewbit.com/problems/pascal-triangle/
*/

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > B; 

    vector<int> firstrow(1,1);
    vector<int> secondrow(2,1);

    if(A>=1)    
        B.push_back(firstrow);
    if(A>=2)
        B.push_back(secondrow);

    for(int i=2;i<A;i++)
    {
        vector<int> myRow(i+1,0);
        B.push_back(myRow);
        for(int j=0;j<i+1;j++)
        {
            if(j==0 || j==i)
           //B[i].push_back(B[i-1][0]);
           B[i][j] = B[i-1][0];
            else
               //B[i].push_back(B[i-1][j] + B[i-1][j-1]);   
               B[i][j] = B[i-1][j] + B[i-1][j-1];
        }
    }
    return B;
}

