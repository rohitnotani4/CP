/*
https://www.interviewbit.com/problems/redundant-braces/
*/

int isOperator(char op)
{
    if(op =='+' || op =='-' || op=='*' || op=='/')
        return 1;
    return 0;
}

int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> bracketsStack;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == '(' || isOperator(A[i]))
            bracketsStack.push(A[i]);
        else
        if(A[i]==')')
        {
            if(bracketsStack.size() > 1)
            {
                int top = bracketsStack.top();
                if(isOperator(top))
                {
                    bracketsStack.pop();
                    bracketsStack.pop();
                }
                else
                    return 1;
            }
            else
                return 1;            
        }
    }
    return 0;
}
