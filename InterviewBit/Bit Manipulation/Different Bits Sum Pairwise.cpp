/*
https://www.interviewbit.com/problems/different-bits-sum-pairwise/
*/

bool isBitSet(int number, int position)
{
    return number & (1 << position);
}

int Solution::cntBits(vector<int> &A) 
{
    long long int sum = 0;
    long int MOD = 1000000007;
    for(int i=0;i<32;i++)
    {
        int count = 0;    
        for(int j=0;j<A.size();j++)
        {
            if(isBitSet(A[j],i))
            {
                count++;
            }
        }
        
        sum = ((sum%MOD) + (count * (A.size()-count) * 2LL)%MOD)%MOD;
    }
    return sum;
}
