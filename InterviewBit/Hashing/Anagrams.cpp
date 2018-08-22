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
    vector<string> sortedInput;

    for(int i=0;i<A.size();i++)
    {
        string temp ="";
        temp.append(A[i]);
        sort(temp.begin(),temp.end());
        sortedInput.push_back(temp);
    }
    
    for(int i=0;i<sortedInput.size();i++)
    {
        hashTable[sortedInput[i]].push_back(i+1);
    }
    
    auto it = hashTable.begin();
    while(it != hashTable.end())
    {
        ans.push_back(it->second);
        it++;
    }
    // ans = pairs;
    return ans;
}
