/*
https://www.interviewbit.com/problems/merge-overlapping-intervals/
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comparison(const Interval& node1, const Interval& node2)
{
    return node1.start < node2.start;
}

bool areOverlapping(Interval a, Interval b) 
{
    if (min(a.end, b.end) < max(a.start, b.start)) 
        return false;
    return true;
}
        
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> final_answer;
    
    if(A.size()==1)
        return A;
    sort(A.begin(),A.end(),comparison);

    int i=0, j = 1;
    while(i<A.size())
    {
        while(j < A.size() && areOverlapping(A[i],A[j]))
        {
            A[i].start = min(A[i].start,A[j].start);
            A[i].end =  max(A[i].end,A[j].end);
            j++;
            // cout<<"("<<A[i].start<<", "<<A[i].end<<"), ";
        }
        final_answer.push_back(A[i]);
        i = j;
        j++;
    }
    
    return final_answer;
    
}
