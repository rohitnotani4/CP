/*
https://www.interviewbit.com/problems/sliding-window-maximum/
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    deque<int> dq;
    int windowSize = B;
    vector<int> result;
    for(int i=0;i<A.size();i++)
    {
        // Remove indexes from front of deque which don't fall in current 
        // window i.e window ending at ith index
        while(!dq.empty() && dq.front() <= (i-windowSize))
            dq.pop_front();
            
        // Now compare the rear of deque with the current index. 
        // If the element at current index is greater than element at index at deque end(rear)
        // We remove that index from rear. To understand this, think of going left from 
        // current index upto windowSize, since A[rear_index] < A[currentIndex], any window 
        // which invovle these 2 indexes would never have rear_index element as Maximum
        while(!dq.empty() && A[dq.back()] < A[i])
            dq.pop_back();
 
        // Push the current index to deque
        dq.push_back(i);
        
        // Store the max of current window to the result
        if(i >= windowSize-1)
            result.push_back(A[dq.front()]);
    }
    return result;
}
