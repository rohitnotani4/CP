/*
https://www.interviewbit.com/problems/2-sum/
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        
    vector<int> ans;
    unordered_map<int,int> cache;
    for(int i=0;i<A.size();i++)
    {
        int numberToLookup = B - A[i];
        if(cache.find(numberToLookup) != cache.end())
        {
            ans.push_back(cache[numberToLookup]);
            ans.push_back(i+1);;
            return ans;
        }
        if(cache.find(A[i]) == cache.end())
        {
            cache[A[i]] = i+1;
        }
    }

    return ans;
}
