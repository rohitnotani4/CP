/*
https://www.interviewbit.com/problems/add-one-to-number/
*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    int i=0;
    
    while(i < A.size() && A[i]==0)
        i++;
    
    if(i >= A.size())
    {
        result.push_back(0);
    }
    
    while(i < A.size())
    {
        result.push_back(A[i]);
        i++;
    }
    
    int j =result.size()-1;
    int carry = 1;
    while(j>=0)
    {
        int sum = result[j] + carry;
        result[j] = sum%10;
        carry = sum/10;
        j--;
    }
    
    if(carry)
    {
        vector<int>::iterator it = result.begin();
        it = result.insert ( it , 1 );
    }
    
    return result;
}
