/*
https://www.interviewbit.com/problems/letter-phone/
*/

void letterCombinationsHelper(vector<string>& result, string& chosen, map<char, string>& digitToChars, int currIndex, string& input)
{
    if(chosen.size() == input.size())
    {
        result.push_back(chosen);
        return ;
    }
    
    string phoneChars = digitToChars[input[currIndex]];
    for(int i = 0;i<phoneChars.length();i++)
    {
        chosen.push_back(phoneChars[i]);
        
        letterCombinationsHelper(result, chosen, digitToChars, currIndex + 1, input);
        
        chosen.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> result;
    string chosen;
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
    
    letterCombinationsHelper(result,chosen,digitToChars,0,A);
    return result;
}
