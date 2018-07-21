/*
https://www.interviewbit.com/problems/min-xor-value/
*/

int Solution::findMinXor(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    //for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
        
    int minXor = A[A.size()-1];
    for(int i=0;i<A.size()-1;i++)
    {
        if((A[i] ^ A[i+1]) < minXor)
            minXor = A[i] ^ A[i+1];
    }
    return minXor;
}
