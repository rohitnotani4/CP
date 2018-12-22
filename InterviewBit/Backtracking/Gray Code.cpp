/*
https://www.interviewbit.com/problems/gray-code/
*/

vector<int> Solution::grayCode(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result(1, 0);        
    for (int i = 0; i < A; i++) {
        int curSize = result.size();
        // push back all element in result in reverse order
        for (int j = curSize - 1; j >= 0; j--) {
            result.push_back(result[j] + (1 << i));
        } 
    }
    return result;
}
