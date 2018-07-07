/*
https://www.interviewbit.com/problems/search-for-a-range/
*/

int binarySearch(const vector<int> &A,int l, int h, int B)
{
    int low = l, high = h, mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
            return mid;
        else
        if(A[mid] > B)
            high = mid-1;
        else
            low = mid + 1;
    }
    return -1;
}
 
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int found = binarySearch(A,0,A.size()-1,B);
    ans.push_back(found);
    ans.push_back(found);
    int finalStart=-1,finalEnd=-1;
    
    if(found != -1)
    {
        int startIndex = 0, endIndex = ans[0]-1;
        while(startIndex <= endIndex && found !=-1)
        {
            found = binarySearch(A,startIndex,endIndex,B);
            if(found !=-1)
                finalStart = found;
            startIndex = 0, endIndex = found-1;
        }
        startIndex = ans[1]+1, endIndex = A.size()-1, found=1;
        while(startIndex <= endIndex && found!=-1)
        {
            found = binarySearch(A,startIndex,endIndex,B);
            if(found !=-1)
                finalEnd = found;
            startIndex = found+1, endIndex = A.size()-1;
        }
        
        if(finalStart != -1)
            ans[0] = finalStart;
            
        if(finalEnd !=-1)
            ans[1] = finalEnd;
    }
    return ans;       
}
