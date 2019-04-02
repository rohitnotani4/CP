/*
https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
*/

int findMaxArea(vector<int> bars)
{
    stack<int> trackLeft;
    int top, i = 0, currArea= 0, maxArea=0;
    while(i < bars.size())
    {
        if(trackLeft.empty() || bars[trackLeft.top()] <= bars[i])
        {
            trackLeft.push(i);
            i++;
        }
        else
        {
            top = trackLeft.top();
            trackLeft.pop();
            
            if(trackLeft.empty())
                currArea = bars[top] * i;
            else    
                currArea = bars[top] * (i-trackLeft.top()-1); 
            
            maxArea = max(currArea,maxArea);    
        }
    }
    
    while(!trackLeft.empty())
    {
        top = trackLeft.top();
        trackLeft.pop();
        
        if(trackLeft.empty())
            currArea = bars[top] * i;
        else    
            currArea = bars[top] * (i-trackLeft.top()-1); 
        
        maxArea = max(currArea,maxArea);    
    }
    
    return maxArea;
}
 
int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxArea = 0, currArea = 0;
    vector<int> oneRow;
    for(int i=0;i<A.size();i++)
    {
        if(i==0)
        {
            oneRow = A[i];
        }
        else
        {
            for(int j=0;j<A[i].size();j++)
            {
                if(A[i][j] == 0)
                    oneRow[j] = 0;
                else
                    oneRow[j] = oneRow[j] + A[i][j];
                
                // cout<<oneRow[j]<<" ";
            }
        }    
        currArea = findMaxArea(oneRow);
        // cout<<"Area = "<<currArea<<"\n";
        maxArea = max(currArea,maxArea);      
    }
    return maxArea;
}
