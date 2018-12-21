/*
https://www.interviewbit.com/problems/combinations/
*/

void combinationsHelper(vector<vector<int> >& result,vector<int>& chosen, int n,int currNumber,int k)
{
    if(chosen.size()==k)
    {
        result.push_back(chosen);
    }
    else
    {
        for(int i=currNumber;i<=n;i++)
        {
            chosen.push_back(i);
            
            combinationsHelper(result,chosen,n,i+1,k);
            
            chosen.pop_back();
        }
    }
}
 
vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> chosen;
    vector<vector<int> > result;
    combinationsHelper(result, chosen, n, 1, k);
    return result;   
}
