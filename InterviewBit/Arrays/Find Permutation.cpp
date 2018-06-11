/*
https://www.interviewbit.com/problems/find-permutation/
*/

vector<int> Solution::findPerm(const string A, int B) {

    int sizeOfString = A.size();
    int totalD=1,totalI=B;
    for(int i=0;i<sizeOfString;i++)
    {
        if(A[i]=='D')
            totalD++;
        else
            totalI--;
    }

    vector<int> ans;
    //for(int i=0;i<B;i++)
    //{
    //    process.push_back(i+1);
    //}

    int pointerForD = totalD,pointerForI = totalD+1;

    if(A[0]=='I')
        ans.push_back(1);
    else
        ans.push_back(B);

    for(int i=0;i<sizeOfString;i++)
    {
        if(A[i]=='I')
            ans.push_back(pointerForI++);
        else
            ans.push_back(--pointerForD);
    }

    return ans;

}
