/*
https://www.interviewbit.com/problems/anagrams/
*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<string, vector<int> > hashTable;
    vector<vector<int> > ans;

    for(int i=0;i<A.size();i++)
    {
        string currWord = A[i];
        sort(currWord.begin(),currWord.end());
        hashTable[currWord].push_back(i+1);
    }
    
    auto it = hashTable.begin();
    while(it != hashTable.end())
    {
        ans.push_back(it->second);
        it++;
    }
    return ans;
}
