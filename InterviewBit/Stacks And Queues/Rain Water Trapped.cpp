/*
https://www.interviewbit.com/problems/rain-water-trapped/
*/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() <= 1)
        return 0;
    
    // For each index find what it is the maximum height on right side
    vector<int> maxHeightOnRight(A.size(), 0);
    int currMax = INT_MIN;
    for(int i=A.size()-1;i>=0;i--)
        currMax = maxHeightOnRight[i] = max(currMax,A[i]);
    
    // We aren't storing maxOfLeft in array because we can use the maxHeightOnLeft
    // for all indexes when we move from 0 to array length
    int maxHeightOnLeft = INT_MIN;
    int waterTrapped = 0, totalWaterTrapped = 0;
    for(int i=0;i<A.size();i++)
    {
        maxHeightOnLeft = max(maxHeightOnLeft,A[i]);
            
        waterTrapped = min(maxHeightOnLeft, maxHeightOnRight[i]) - A[i];
        totalWaterTrapped += waterTrapped;
    }
    return totalWaterTrapped;
}
