/*
https://www.interviewbit.com/problems/counting-triangles/
*/

int Solution::nTriang(vector<int> &A) 
{
    int MOD = pow(10,9) + 7, count = 0, size = A.size();
    
    if(size < 3)
        return count;
        
    sort(A.begin(),A.end());
    for(int i=0;i<size-2;i++)
    {
        int k = i+2;
        for(int j=i+1;j<size;j++)
        {
            while(k<size && A[i]+A[j] > A[k])
                k++;
                
            count = (count%MOD + (k-j-1)%MOD)%MOD;
        }
    }
    return count;
}
