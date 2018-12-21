/*
https://www.interviewbit.com/problems/letter-phone/
*/

bool solveRecursively
(vector<string>& ans,string& temp,map<char, string>& digitToChars,int currentIndex,string& A)
{
    if(temp.size() == A.size())
        return true;
        
    if(temp.size() < A.size())
    {
        string mappedString = digitToChars[A[currentIndex]];
        for(int j=0;j<mappedString.size();j++)
        {
            temp.push_back(mappedString[j]);
            if(solveRecursively(ans,temp,digitToChars,currentIndex+1,A))
                ans.push_back(temp);
            temp.pop_back();    
        }
    } 
    return false;
}


vector<string> Solution::letterCombinations(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ans;
    string temp;
    map<char, string> digitToChars;
    digitToChars['0'] = string("0");
    digitToChars['1'] = string("1");
    digitToChars['2'] = string("abc");
    digitToChars['3'] = string("def");
    digitToChars['4'] = string("ghi");
    digitToChars['5'] = string("jkl");
    digitToChars['6'] = string("mno");
    digitToChars['7'] = string("pqrs");
    digitToChars['8'] = string("tuv");
    digitToChars['9'] = string("wxyz");
    
    solveRecursively(ans,temp,digitToChars,0,A);
    return ans;
}
