/*
https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
*/

vector<int> Solution::lszero(vector<int> &A) 
{
    vector<int> result;

    vector<int> prefixSum(A.size(), 0);
    unordered_map<int, int> sumMap;
    
    sumMap[0] = -1;
    int sum = 0, maxLength = INT_MIN, start = -1, end = -1;
    for(int i=0;i<A.size();i++)
    {
        sum += A[i];
        if(sumMap.find(sum) != sumMap.end())
        {
            int currLength = (i - sumMap[sum]+1) + 1;
            // Since we want the sequence which occurs first, we don't use ">=" below
            // and use onyl ">"
            if(currLength > maxLength)
            {
                maxLength = currLength;
                start = sumMap[sum]+1;
                end = i;
            }
        }
        else
            sumMap[sum] = i;
            
    }
    
    for(int i=start;i>= 0 && i<=end;i++)
        result.push_back(A[i]);
        
    return result;
}
