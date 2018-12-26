/*
https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/

vector<int> Solution::dNums(vector<int> &A, int B) 
{
    vector<int> ans;
    map<int,int> numberCountMap;
    if(B > A.size())
        return ans;
        
    for(int currIndex=0;currIndex<A.size();currIndex++)
    {
        numberCountMap[A[currIndex]]++;
        
        if(currIndex - B >= 0)
        {
            numberCountMap[A[currIndex-B]]--;
            int currentCount = numberCountMap[A[currIndex-B]];
            if (!currentCount)
                numberCountMap.erase(A[currIndex-B]);
        }
        
        if(currIndex - (B-1) >= 0)
        {
            ans.push_back(numberCountMap.size());
        }
    }
    return ans;
}
