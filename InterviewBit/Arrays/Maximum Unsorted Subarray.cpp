/*
https://www.interviewbit.com/problems/maximum-unsorted-subarray/
*/

int findMin(int a,int b)
{
    return a < b ? a : b;
}

int findMax(int a,int b)
{
    return a > b ? a : b;
}

vector<int> Solution::subUnsort(vector<int> &A) 
{
    vector <int> ans;
    int size = A.size();
    int start = size, end = -1;
    
    int swap;
    for(int i=0;i<size-1;i++)
    {
        if(A[i] > A[i+1])
        {
            start  = i;
            break;
        }
    }
    
    //Early return 
    if(start == size)
    {
        ans.push_back(-1);
        return ans;
    }
    
    for(int j=size-1;j>0;j--)
    {
        if(A[j] < A[j-1])
        {
            end = j;
            break;
        }
    }
    
    int min = INT_MAX, max = INT_MIN;
    for(int i=start;i<=end;i++)
    {
        min = findMin(min, A[i]);
        max = findMax(max, A[i]);
    }
    
    for(int i=0;i<start;i++)
    {
        if(A[i] > min)
        {
            start = i;
            break;
        }
    }
    
    for(int j=size-1;j>=end-1;j--)
    {
        if(A[j] < max)
        {
            end = j;
            break;
        }
    }
    
    
    ans.push_back(start);
    ans.push_back(end);
    
    return ans;
}
