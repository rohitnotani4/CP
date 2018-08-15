/*
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> indexes;
    int currArea = INT_MIN, maxArea = INT_MIN;
    int i=0;
    while(i<A.size())
    {
        if(indexes.empty() ||  A[indexes.top()] <= A[i])
        {
            indexes.push(i);
            i++;
        }
        else
        {
            while(!indexes.empty() && A[indexes.top()] > A[i])
            {
                int popedIndex = indexes.top();
                indexes.pop();
                currArea =  indexes.empty()
                            ? A[popedIndex] * i
                            : A[popedIndex] * (i - 1 - indexes.top());
                    
                maxArea = max(maxArea, currArea);    
            }
        }
    }
    
    while(!indexes.empty())
    {
        int popedIndex = indexes.top();
        indexes.pop();
        currArea =  indexes.empty()
                    ? A[popedIndex] * i
                    : A[popedIndex] * (i - 1 - indexes.top());
                    
        maxArea = max(maxArea, currArea);  
    }
    
    return maxArea;
}
