/*
https://www.interviewbit.com/problems/maximum-consecutive-gap/
*/

// Solution Explanation: https://leetcode.com/problems/maximum-gap/solution/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 2)
        return 0;
    
    int min = INT_MAX,max = INT_MIN, maxGap = 0;
    for(int i=0;i<A.size();i++)
    {
        min = A[i] < min ? A[i] : min;
        max = A[i] > max ? A[i] : max;
    }
    
    int bucketSize = (max - min)/A.size() + 1;
    vector< pair<int,int> > buckets ((max-min)/bucketSize + 1,  {-1, -1});
    
    for(int i=0;i<A.size();i++)
    {
        int bucketIndex = (A[i] - min)/bucketSize;
        
        buckets[bucketIndex].first =  
            buckets[bucketIndex].first == -1 || A[i] < buckets[bucketIndex].first 
            ?  A[i] 
            : buckets[bucketIndex].first;
        buckets[bucketIndex].second = 
            buckets[bucketIndex].second == -1 || A[i] > buckets[bucketIndex].second  
            ?  A[i] 
            : buckets[bucketIndex].second;
    }
    
    int gap = 0;
    int prev = 0;
    for(int i=1;i<buckets.size();i++)
    {
        if (!(buckets[i].first==-1))
        {
            gap = buckets[i].first - buckets[prev].second;
            maxGap = gap > maxGap ? gap : maxGap;
            prev = i;
        }
        
    }
    return maxGap;
}
