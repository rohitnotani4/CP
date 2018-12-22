/*
https://www.interviewbit.com/problems/kth-permutation-sequence/
*/

void calculateFactorials(vector<int>& fact, int n) 
{
    fact.push_back(1);
    fact.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int prod = 1;
        for(int j=i;j>=1;j--)
        {
            prod *= j;
        }
        fact.push_back(prod);
    }
}
 
string getPermutationsHelper(vector<int>& numbers, vector<int>& fact, int n, int k)
{
    string result;
    for(int i=1;i<=n;i++)
    {
        int index = k/fact[n-i];
        int selectedDigit = numbers[index];
        result.push_back(selectedDigit + '0');
        numbers.erase(numbers.begin() + index);
        k = k - (index * fact[n-i]);            
    }
    return result;
}
 
string Solution::getPermutation(int A, int B) 
{
    vector<int> numbers, fact;
    for(int i=1;i<=A;i++)
    {
        numbers.push_back(i);
    }
    
    calculateFactorials(fact, A);
    
    B--;// Because number indexes are zero based
    
    return getPermutationsHelper(numbers, fact, A, B);
}
