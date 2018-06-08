/*
https://www.interviewbit.com/problems/noble-integer/
*/
int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    
    int size = A.size();
    for(int i=0;i<size;i++)
    {
        int count  = size - i-1;
        if(i+1 < size && A[i] != A[i+1])
        {
            if(A[i] == count)
                return 1;
        }
        else
        if(i==size-1 && A[i]==0)
        {
            return 1;
        }
    }
    return -1;
}
