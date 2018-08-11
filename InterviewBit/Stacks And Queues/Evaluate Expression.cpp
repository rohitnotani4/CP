/*
https://www.interviewbit.com/problems/evaluate-expression/
*/

int applyOperation(vector<string> &A,int firstNumber, int secondNumber,int i)
{
    if(A[i][0] =='+')
        return (firstNumber + secondNumber);
    else
    if(A[i][0] =='*')
        return (firstNumber * secondNumber);
    else
    if(A[i][0] =='-')
        return (firstNumber - secondNumber);
    else
    if(A[i][0] =='/')
        return (firstNumber / secondNumber);
    else
        return 0;
}

int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> operands;
    int answer = 0;
    string::size_type sz;   // alias of size_t
    // cout<<"Array size "<<A.size()<<"\n";
    for(int i=0;i<A.size();i++)
    {
        
        if(A[i].size()==1 && (A[i][0] =='+' || A[i][0] =='*' || A[i][0] =='-' || A[i][0] =='/'))
        {
            int secondNumber,firstNumber = 0;
            if(!operands.empty())
            {
                secondNumber = operands.top();
                operands.pop();
                if(!operands.empty())
                {
                    firstNumber = operands.top();
                    operands.pop();
                }
                answer = applyOperation(A,firstNumber,secondNumber,i);
                operands.push(answer);
            }
        }
        else
        {
            //cout<<"String size "<<A[i].size()<<"\n";
            string temp;
            int minus = 1,j=0;
            if(A[i][0] == '-')
            {
                minus = -1;
                j=1;
            }
                
            for(;j<A[i].size();j++)
                temp.push_back(A[i][j]);
                
            int number = minus * (stoi(temp,&sz));
            operands.push(number);    
            
            // cout<<"This is : "<<number<<"\n";
        }
    }
    return operands.top();
}
