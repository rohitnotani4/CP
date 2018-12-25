/*
https://www.interviewbit.com/problems/magician-and-chocolates/
*/

int Solution::nchoc(int A, vector<int> &B) 
{

    priority_queue<int> chocsInBags(B.begin(),B.end());
    
    long long int maxChoc = 0,currMax = 0;
    for(int i=0;i<A;i++)
    {
        currMax = chocsInBags.top();
        maxChoc = (maxChoc + currMax)%1000000007;
        chocsInBags.pop();
        chocsInBags.push(currMax/2);
    }
    
    return maxChoc;
}
