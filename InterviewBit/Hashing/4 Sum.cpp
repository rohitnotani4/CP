/*
https://www.interviewbit.com/problems/4-sum/
*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    vector<vector<int> > ans;
    if(A.size() < 4)
        return ans;
    
    sort(A.begin(), A.end());
    
    for(int i=0;i<A.size();i++)
    {
        int target3Sum = B - A[i];
        
        for(int j=i+1;j<A.size();j++)
        {
            int target2Sum = target3Sum - A[j];
            
            int startIndex = j+1, endIndex = A.size()-1;
            while(startIndex < endIndex)
            {
                if(A[startIndex] + A[endIndex] == target2Sum)
                {
                    vector<int> temp(4, 0);
                    temp[0] = A[i];
                    temp[1] = A[j];
                    temp[2] = A[startIndex];
                    temp[3] = A[endIndex];
                    
                    ans.push_back(temp);
                    
                    startIndex++;
                    endIndex--;
 
                    // Processing duplicates of Number 3
                    // Rolling the front pointer to the next different number forwards
                    while (startIndex < endIndex && A[startIndex] == temp[2]) 
                        startIndex++;
 
                    // Processing duplicates of Number 4
                    // Rolling the back pointer to the next different number backwards
                    while (startIndex < endIndex && A[endIndex] == temp[3]) 
                        endIndex--;                        
                }
                else
                if(A[startIndex] + A[endIndex] > target2Sum)
                    endIndex--;
                else
                    startIndex++;
            }
            
            // Processing duplicates of Number 2
            while(j+1 < A.size() && A[j+1] == A[j])
                j++;  
        }
        
        // Processing duplicates of Number 1
        while(i+1 < A.size() && A[i+1] == A[i])
            i++;  
    } 
    return ans;
}
