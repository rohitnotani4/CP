/*

*/

bool calculateSumRecursively
(vector<vector<int> >& ans,vector<int>& temp, set<int>& input, int sum,int target, int *prev)
{
    if(sum==target)
    {
        return true;
    }
    
    if(sum < target)
    {
        for(set<int>::iterator it=input.begin(); it!=input.end(); ++it)   
        {
            if(*it >= *prev)
            {
                *prev = (*it);
                temp.push_back(*it);
                sum += (*it);
                if(calculateSumRecursively(ans,temp,input,sum,target,prev))
                    ans.push_back(temp);
                temp.pop_back();
                sum -= (*it);
            }
        }
        *prev = -1;
    }
    return false;
}
 
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int prev = -1;
    vector<int> temp;
    vector<vector<int> > ans;
    set<int> uniqueElements;
    
    for(int i=0;i<A.size();i++)
        uniqueElements.insert(A[i]);
        
    calculateSumRecursively(ans,temp,uniqueElements,0,B,&prev);
    return ans;  
    
}
