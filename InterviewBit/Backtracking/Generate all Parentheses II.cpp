/*
https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/


void generateParenthesisHelper(vector<string>& result,string& chosen,int openBrackets, int closedBrackets, int totalBrackets)
{
   if(openBrackets == closedBrackets && openBrackets + closedBrackets == totalBrackets)
   {
       result.push_back(chosen);
       return ;
   }
   
   if(openBrackets > totalBrackets/2 || closedBrackets > totalBrackets/2)
   {
       return ;
   }
   
   if(closedBrackets > openBrackets)
   {
       return ;
   }
   
   for(int i=0;i<2;i++)
   {
       i == 0 ? openBrackets++ : closedBrackets++;
       chosen.push_back(char(i+40)); // ASCII for '(' is 40 and ')' is 41
       
       generateParenthesisHelper(result, chosen, openBrackets, closedBrackets, totalBrackets);
       
       chosen.pop_back();
       i == 0 ? openBrackets-- : closedBrackets--;
   }
}

vector<string> Solution::generateParenthesis(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string> result;
    string chosen;
    generateParenthesisHelper(result,chosen,0,0,2*A);
    return result;
}
