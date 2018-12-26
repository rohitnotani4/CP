/*
https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/

int findDistinctCount(vector<int>& A,map<int,int>& hashMap,int prevIndex,int currentIndex)
{
    
    if(prevIndex >= 0)
    {
        // cout<<"prevIndex = "<<prevIndex<<" and currentIndex = "<<currentIndex<<"\n";
        if(hashMap[A[prevIndex]] < 2)
        {
            // cout<<"Delete the element "<<A[prevIndex]<<"\n";
            hashMap.erase(A[prevIndex]);
        }
        else
        {
            // cout<<"Reduce the count of element "<<A[prevIndex]<<"\n";
            hashMap[A[prevIndex]]--;
        }
            
        if(hashMap.find(A[currentIndex]) != hashMap.end())
        {
            // cout<<"Increment the count of element "<<A[currentIndex]<<"\n";
            hashMap[A[currentIndex]]++;
        }
        else
        {
            // cout<<"Add the element "<<A[currentIndex]<<"\n";
            hashMap[A[currentIndex]] = 1;    
        }
    }
    return hashMap.size();
}
 
vector<int> Solution::dNums(vector<int> &A, int B) 
{
 
    vector<int> ans;
    map<int,int> hashMap;
    if(B > A.size())
        return ans;
        
    
    // Insert first B elements in haspMap
    for(int i=0;i<B;i++)
    {
        if(hashMap.find(A[i]) != hashMap.end())
           hashMap[A[i]]++;
        else
            hashMap[A[i]] = 1;
    }    
    
    int j=-1,i=B-1;
    
    while(i < A.size())
    {
        ans.push_back(findDistinctCount(A,hashMap,j,i));
        i++;
        j++;
    }
    return ans;
}
