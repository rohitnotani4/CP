/*
https://www.interviewbit.com/problems/evaluate-expression/
*/

bool isOperator(char opr)
{
    return opr=='+' || opr == '*' || opr == '-' || opr =='/';
}

int applyOperation(char opr, int firstNumber, int secondNumber)
{
    if(opr =='+')
        return (firstNumber + secondNumber);
    else
    if(opr =='*')
        return (firstNumber * secondNumber);
    else
    if(opr =='-')
        return (firstNumber - secondNumber);
    else
    if(opr =='/')
        return (firstNumber / secondNumber);
    else
        return 0;
}

int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> numbers;
    int answer = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i].size() == 1 && isOperator(A[i][0]))
        {
            int secondNumber = numbers.top();
            numbers.pop();
            int firstNumber = numbers.top();
            numbers.pop();
            numbers.push(applyOperation(A[i][0], firstNumber,secondNumber));
        }
        else
        {
            string::size_type sz;
            if(A[i][0]=='-')
            {
                string temp(A[i].begin()+1, A[i].end());
                numbers.push(-1 * stoi(temp,&sz));
            }
            else
            {
                string temp(A[i]);
                numbers.push(stoi(temp,&sz));
            }
        }
    }
    return numbers.top();
}
