/*
https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

// Solution: https://www.youtube.com/watch?v=siKFOI8PNKM
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    // DO STUFF HERE AND POPULATE result
    vector<int> result;
    
    if(A.empty())
        return result;
    int T=0,B=A.size()-1,L=0,R=A[0].size()-1, dir = 0;
    
    while(T<=B && L<=R)
    {
        if(dir==0) // Traverse Left to Right
        {
            for(int j=L;j<=R;j++)
                result.push_back(A[T][j]);
            T++;
        }
        else
        if(dir==1) // Traverse Top to Bottom
        {
            for(int i=T;i<=B;i++)
                result.push_back(A[i][R]);
            R--;
        }
        else
        if(dir==2)
        {
            for(int j=R;j>=L;j--)
                result.push_back(A[B][j]);
            B--;
        }
        else
        {
            for(int i=B;i>=T;i--)
                result.push_back(A[i][L]);
            L++;    
        }
        dir = (dir + 1)%4;
    }
    
    return result;
}
