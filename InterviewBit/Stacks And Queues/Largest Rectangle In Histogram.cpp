/*
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> IndexStack;
    int maxArea = 0, currArea = 0, i=0, currIndex, popedIndex;
    for(;i<=A.size();i++)
    {
        if(IndexStack.empty() || (i!=A.size() && A[IndexStack.top()] <= A[i]))
        {
            // cout<<"Pushed Index i = "<<i<<"\n";
            IndexStack.push(i);
        }
        else
        {
            // cout<<"Start poping i = "<<i<<"\n";
            currIndex = i;
            currArea = 0;
            while(!IndexStack.empty() && (i==A.size() || A[IndexStack.top()] > A[i]))
            {
                popedIndex = IndexStack.top();
                IndexStack.pop();
                if(IndexStack.empty())
                    currArea = A[popedIndex] * i;
                else
                    currArea = A[popedIndex] * (currIndex - IndexStack.top() - 1);
                maxArea = max(maxArea, currArea);
                // cout<<"CurrArea = "<<currArea<<" Maxarea = "<<maxArea<<"\n";
            }
            IndexStack.push(i);
        }
    }
    return maxArea;
}
