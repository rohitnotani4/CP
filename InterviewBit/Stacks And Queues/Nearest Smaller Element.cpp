/*
https://www.interviewbit.com/problems/nearest-smaller-element/
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int result;
    vector<int> ans;
    stack<int> currStack;
    
    for(int i=0;i<A.size();i++)
    {
        int top = A[i];
        while(!currStack.empty() && top <= currStack.top())
            currStack.pop();
        
        if(currStack.empty())
            ans.push_back(-1);
        else
            ans.push_back(currStack.top());
            
        currStack.push(A[i]);
    }
    return ans;
}
