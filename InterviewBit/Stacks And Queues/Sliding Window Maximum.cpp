/*
https://www.interviewbit.com/problems/sliding-window-maximum/
*/



void initializeWindow(const vector<int> &A,int n,int begin,int k,deque<int> &DQ){
    int i=begin;
    while(i<n && i<begin+k)
    {
        if(DQ.empty() || DQ.back()<=A[i])
            DQ.push_back(A[i]);
        i++;
    }
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    deque<int> DQ;

    int i = 0, p =-1;
    int n = A.size();

    vector<int> ans;
    initializeWindow(A,n,0,B,DQ);
    ans.push_back(DQ.back());
    i+=B;

    while(i<n)
    {
        p=i-B;

        if(A[p]==DQ.front())
            DQ.pop_front();

        if(DQ.empty())
        {
            initializeWindow(A,n,p+1,B,DQ);
            ans.push_back(DQ.back());
        }
        else
        {
            if(A[i]>=DQ.back())
                DQ.push_back(A[i]);

            ans.push_back(DQ.back());
        }
        i++;
    }
    return ans;
}
