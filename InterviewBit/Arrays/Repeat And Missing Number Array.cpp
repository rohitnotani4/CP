/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    long long int n = A.size();

    long long int expectedSum,expectedSquareSum,firstNum,secondNum;
    expectedSum = (n * (n+1))/2;
    //cout<<"Expected Sum = "<<expectedSum<<"\n";

    expectedSquareSum = ( (n) * (n+1) * (2*n + 1) ) /6 ;    
    // cout<<"Expected Square Sum = "<<expectedSquareSum<<"\n";
    for(int i=0;i<n;i++)
    {
        expectedSum -= (long long int)A[i];
        expectedSquareSum -=  (long long int)A[i] * (long long int)A[i];
    }

    firstNum = (expectedSum + expectedSquareSum/expectedSum)/2;

    secondNum = firstNum  - expectedSum;
    ans.push_back(secondNum);
    ans.push_back(firstNum);


    // actualSquareSum = (n * (n+1) * (2*n + 1))/6 + A^2 - B^2;
    // (A-B) * (A+B) = actualSquareSum - expectedSquareSum;

    //A+B = (actualSquareSum - expectedSquareSum)/(A-B);



    return ans;

}
