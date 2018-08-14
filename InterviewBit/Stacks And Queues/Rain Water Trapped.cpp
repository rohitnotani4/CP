/*
https://www.interviewbit.com/problems/rain-water-trapped/
*/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 1)
        return 0;
    vector<int> height;
    height = A;

    int a = 0, b = height.size() - 1, maxLeft = 0, maxRight = 0, res = 0;
    while (a <= b) 
    {
        maxLeft = max(maxLeft, height[a]);
        maxRight = max(maxRight, height[b]);
        if (maxLeft <= maxRight) 
        {
            res += maxLeft - height[a];
            a++;
        } else 
        {
            res += maxRight - height[b];
            b--;
        }
    }
    return res;
}
