/*
https://www.interviewbit.com/courses/1/topics/7/problems/max-continuous-series-of-1s/previous_submissions/
*/

vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int windowLeft = 0, windowRight = 0, zeroCount = 0, maxOnes = 0, resultLeft = 0, resultRight = 0;
    
    while(windowRight < A.size())
    {
        if(zeroCount <= B)
        {
            if(A[windowRight] == 0)
                zeroCount++;
            // cout<<"Right ZeroCount: "<<zeroCount<<"\n";
            windowRight++;
        }
        
        if(zeroCount > B)
        {
            if(A[windowLeft] == 0)
                zeroCount--;
            // cout<<"Left ZeroCount: "<<zeroCount<<"\n";
            windowLeft++;
        }
        
        if(windowRight - windowLeft > maxOnes)
        {
            maxOnes = windowRight - windowLeft;
            resultLeft = windowLeft;
            resultRight = windowRight;
        }
    }
    vector<int> result;
    for(int i=resultLeft;i<resultRight;i++)
        result.push_back(i);
        
    return result;
}
