/*
https://www.interviewbit.com/problems/combinations/
*/

bool calculateRecursive(vector<vector<int> >& ans,vector<int>& temp, int n, int currentIndex,int k)
{
    if(temp.size()==k)
    {
        return true;
    }
    else if(temp.size() < k && k<=n)
    {
        for(int j=currentIndex;j<=n;j++)   
        {
            temp.push_back(j);
            if(calculateRecursive(ans,temp,n,j+1,k))
                ans.push_back(temp);
            temp.pop_back();
        }
    }
    return false;
}


vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> temp;
    vector<vector<int> > ans;
    calculateRecursive(ans,temp,n,1,k);
    return ans;   
}
