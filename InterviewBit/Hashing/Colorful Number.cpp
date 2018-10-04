/*
https://www.interviewbit.com/problems/colorful-number/
*/

int Solution::colorful(int A) 
{
    vector<int> digits;
    
    int number = A;
    while(number > 0)
    {
        digits.push_back(number%10);
        number = number/10;
    }
    
    long long currProd;
    unordered_map<long long , long long > myMap;
    
    int size = 1;
    for(int i=0;i<digits.size();i++)
    {
        currProd = 1;
        for(int j=i;j<digits.size();j++)
        {
            currProd *= digits[j];
            if(myMap.find(currProd) != myMap.end())
                return 0;
            myMap[currProd] = currProd;
        }
    }
    return 1;
}
