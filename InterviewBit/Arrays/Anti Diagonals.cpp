/*
https://www.interviewbit.com/problems/anti-diagonals/
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n=A.size();
    
    vector<vector<int> > ans;
    
    for(int i=0;i<2*n-1;i++)
    {
        vector <int> temp;
        ans.push_back(temp);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i+j].push_back(A[i][j]);
        }
    }
    
    return ans;
    
}
