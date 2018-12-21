/*
https://www.interviewbit.com/problems/gray-code/
*/

long long converToDecimal(string& bits)
{
    long long number = 0;
    for(int i=bits.size()-1,j=0;i>=0;i--,j++)
    {
        number += ((bits[i]-'0') * (int)pow(2,j));
    }
    return number;
}
 
 
void generateGrayCode (vector<string>& prev,int length)
{
    int i=1;
    vector<string> curr;
    string newCode;
    while(i < length)
    {
        curr.clear();
       for(int i=0;i<prev.size();i++)
       {
           newCode = "0" + prev[i];
           curr.push_back(newCode);
       }
       
       for(int j=prev.size()-1;j>=0;j--)
       {
           newCode = "1" + prev[j];
           curr.push_back(newCode);
       }
       
       prev.clear();
       prev = curr;
       i++;
    }
}
 
 
vector<int> Solution::grayCode(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    
    if(A==0)
    {
        ans.push_back(0);
        return ans;
    }
        
    
    vector<string> prev;
    string temp1("0"), temp2("1"), newCode;
    prev.push_back(temp1);
    prev.push_back(temp2);
    
    generateGrayCode(prev,A);
    
    for(int i=0;i<prev.size();i++)
        ans.push_back(converToDecimal(prev[i]));
    
    return ans;
}

