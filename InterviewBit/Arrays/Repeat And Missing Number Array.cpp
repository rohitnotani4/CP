/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

/*
Explanation with example:

Consider array of 4 elements then :
Actual Array: 1 2 2 3  --> ActualSum = 8  --> ActualSquareSum = 18 
Expected Array: 1 2 3 4  --> ExpectedSum = 10 -->  ExpectedSquareSum = 30

Equation:
ActualSum - A + B = ExpectedSum

A - B = ActualSum - ExpectedSum;

A - B = -2

ActualSquareSum - A^2 + B^2 = ExpectedSquareSum

A^2 - B^2 = ActualSquareSum - ExpectedSquareSum;

(A-B) * (A+B) = 18 - 30 = -12

A + B = 6

A = 4/2 = 2

B = (A + B) - A = 6 - 2 = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    long long int n = A.size();
    long long int expectedSum ,expectedSquareSum ,acutalSum = 0, acutalSquareSum = 0;
    int a, b, aPlusb, aMinusb;
    
    expectedSum = (n * (n+1))/2;
    expectedSquareSum = ( (n) * (n+1) * (2*n + 1) ) /6 ;    

    for(int i=0;i<n;i++)
    {
        acutalSum += (long long int)A[i];
        acutalSquareSum +=  (long long int)A[i] * (long long int)A[i];
    }
    
    aMinusb = acutalSum - expectedSum;
    aPlusb = (acutalSquareSum - expectedSquareSum)/(aMinusb);
    
    a = (aPlusb + aMinusb)/2;    
    b = aPlusb  - a;
    
    ans.push_back(a);
    ans.push_back(b);
    
    return ans;        
}
