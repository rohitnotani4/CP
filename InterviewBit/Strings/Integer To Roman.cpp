/*
https://www.interviewbit.com/problems/integer-to-roman/
*/

string findRomanChar(int num)
{
    string ans;
    int temp;
    while(num != 0)
    {
        if(num == 4)
        {
            temp = 4;
            ans.push_back('I');
            ans.push_back('V');
        }
        else
        if(num == 9)
        {
            temp = 9;
            ans.push_back('I');
            ans.push_back('X');
        }
        else
        if(num == 40)
        {
            temp = 40;
            ans.push_back('X');
            ans.push_back('L');
        }
        else
        if(num == 90)
        {
            temp = 90;
            ans.push_back('X');
            ans.push_back('C');
        }
        else
        if(num == 400)
        {
            temp = 400;
            ans.push_back('C');
            ans.push_back('D');
        }
        else
        if(num == 900)
        {
            temp = 900;
            ans.push_back('C');
            ans.push_back('M');
        }
        else
        if(num >= 1000)
        {
            temp = 1000;
            ans.push_back('M');
        }
        else
        if(num >= 500) 
        {
            temp = 500;
            ans.push_back('D');
        }
        else
        if(num >= 100)
        {
            temp = 100;
            ans.push_back('C');
        }
        else
        if(num >= 50)
        {
            temp = 50;
            ans.push_back('L');
            
        }
        else
        if(num >= 10) 
        {
            temp = 10;
            ans.push_back('X');
        }
        else
        if(num >= 5)
        {
            temp = 5;
            ans.push_back('V');
        }
        else
        if(num >= 1)
        {
            temp = 1;
            ans.push_back('I');
        }
        num = num - temp;
    }
    return ans;
    
}

string Solution::intToRoman(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans="";
    vector<string> allRomans;
    int quotient, rem, number = A;
    int count = 0;
    
    while( number > 0)
    {
        rem = (number%10);
        rem = rem * pow(10,count);
        allRomans.push_back(findRomanChar(rem));
        number /= 10;
        count++;
    }
    
    for(int i=allRomans.size()-1;i>=0;i--)
        ans += allRomans[i];
    return ans;
}
