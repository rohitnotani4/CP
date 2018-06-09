/*
https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    // DO STUFF HERE AND POPULATE result
    int T,L,R,B,dir,j=0;
    T=0;
    L=0;
    R=A[0].size()-1;
    B=A.size()-1;
    
    dir=0;
    
    if(A.size()==1 && A[0].size()==1)
        result.push_back(A[0][0]);
    else
    {
        while(T<=B && L<=R)
            {
                if(dir==0)
                {
                    for(int i=L;i<=R;i++)
                        result.push_back(A[T][i]);
                        T++;
                }
                else if(dir==1)
                {
                    for(int i=T;i<=B;i++)
                        result.push_back(A[i][R]);
                        R--;
                }
                else if(dir==2)
                 {
                    for(int i=R;i>=L;i--)
                        result.push_back(A[B][i]);
                        B--;
                }
                else if(dir==3)
                {
                    for(int i=B;i>=T;i--)
                        result.push_back(A[i][L]);
                        L++;
                }
                dir = (dir + 1)%4;
            }
    }
    return result;
}
