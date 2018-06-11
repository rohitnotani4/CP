/*
https://www.interviewbit.com/problems/find-permutation/
*/

vector<int> Solution::findPerm(const string A, int B) {

    vector<int> ans;
    int IndexOfD = 0, IndexOfI=B+1;

    for(int i=0;i<B-1;i++)
    {
        if(A[i]=='D')
            IndexOfD++;
        else
            IndexOfI--;
    }

    if(A[0]=='D')
        ans.push_back(IndexOfD+1);
    else
        ans.push_back(IndexOfI-1);

    for(int i=0;i<B-1;i++)
    {
        if(A[i]=='D')
            ans.push_back(IndexOfD--);
        else
            ans.push_back(IndexOfI++);
    }
    return ans;
}
