/*
https://www.interviewbit.com/problems/palindrome-partitioning/
*/

bool isPalindrome(string& input, int start, int end)
{
    while(start < end)
    {
        if(input[start++] != input[end--])
            return false;
    }
    return true;
}
    
void partitionHelper(vector<vector<string>>& result, vector<string>& path, string& input, int index)
{
    if(index == input.size())
    {
        result.push_back(path);
        return ;
    }
    
    for(int i = index; i < input.length(); i++)
    {
        if(isPalindrome(input,index, i))
        {
            path.push_back(input.substr(index, i - index + 1));
            
            partitionHelper(result, path, input, i + 1);
            
            path.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> result;
    vector<string> path;
    if(A.empty()) 
        return result;
    
    partitionHelper(result, path, A, 0);
    return result;
}
