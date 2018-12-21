/*
https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/

bool isValid(string& temp)
{
    stack<char> st;
    
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='(')
            st.push(temp[i]);
        else
        {
            if(st.empty() || st.top()==')')
                return false;
            
            st.pop();
        }
    }
    
    if(st.empty())
        return true;
        
    return false;
}


bool addParanthesisRecursively(vector<string>& ans,string& temp,int n)
{
    if(temp.size() == (2*n) && isValid(temp))
        return true;
    
    if(temp.size() < 2*n)
    {
        for(int i=0;i<2;i++)
        {
            char paranthesis = i+40;
            temp.push_back(paranthesis);
            if(addParanthesisRecursively(ans,temp,n))
                ans.push_back(temp);
            temp.pop_back(); 
        }
    }
    return false;
}

vector<string> Solution::generateParenthesis(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string> ans;
    string temp;
    addParanthesisRecursively(ans,temp,A);
    return ans;
}
