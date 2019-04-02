/*
https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
*/

int findMaxArea(vector<int>& bars)
{
    int index = 0, maxArea = 0, currentArea = 0;
    stack<int> trackIndexes;
    while(index < bars.size())
    {
        if (trackIndexes.empty() || bars[trackIndexes.top()] <= bars[index])
        {
            trackIndexes.push(index);
            index++;
        }
        else
        {
            while (!trackIndexes.empty() && bars[trackIndexes.top()] > bars[index])
            {
                int popedIndex = trackIndexes.top();
                trackIndexes.pop();
                
                currentArea = trackIndexes.empty()
                    ? bars[popedIndex] * index
                    : bars[popedIndex] * (index - 1 - trackIndexes.top());
                maxArea = max(maxArea, currentArea);
            }              
        }
    }
    
    while (!trackIndexes.empty())
    {
        int popedIndex = trackIndexes.top();
        trackIndexes.pop();

        currentArea = trackIndexes.empty()
            ? bars[popedIndex] * index
            : bars[popedIndex] * (index - 1 - trackIndexes.top());
        maxArea = max(maxArea, currentArea);
    }
    
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (A.size() < 1)
        return 0;
    
    int maxArea = 0, currArea = 0;
    vector<int> oneRow (A[0].size(), 0);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j] == 0)
                oneRow[j] = 0;
            else
                oneRow[j] = oneRow[j] + A[i][j];
            
        }
        currArea = findMaxArea(oneRow);
        maxArea = max(currArea,maxArea);      
    }
    return maxArea;
}
