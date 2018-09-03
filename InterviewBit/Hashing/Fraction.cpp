/*
https://www.interviewbit.com/problems/fraction/
*/

string Solution::fractionToDecimal(int A, int B) 
{
    int numerator = A, denominator = B;
    string result;
        
    if(numerator == 0)
        return "0";
    
    if(numerator < 0 ^ denominator < 0)
        result += '-';
    
    long num = abs((long)numerator);
    long den = abs((long)denominator);

    result += to_string(num/den);
    
    if(num%den == 0)
        return result;
    
    result += '.';
    
    unordered_map<long, int> remainderMap;
    long quotient = 1, rem = num%den;
    while(rem)
    {
        if(remainderMap.find(rem) != remainderMap.end())
        {
            result.insert(remainderMap[rem], 1, '(');
            result += ')';
            return result;
        }
        
        remainderMap[rem] = result.size();
        
        rem *= 10;
        
        result += to_string(rem/den);
        
        rem = rem%den;
    }
    
    return result;
}
