/*
https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
*/

int Solution::solve(string A) {
    
    int mid,left,right,ans;
    
    if(A.size() <= 1 || (A.size() == 2 && A[0]==A[1]))
        return 0;
    else
    if(A.size() == 2)
        return 1;
    
    if(A.size()%2)
    {
        mid = A.size()/2;
        left = mid - 1;
        right = mid + 1;
    }
    else
    {
        left = (A.size()/2) - 1;
        mid = right = left + 1;
    }
    
    while(mid >=1 && left>=0 && right<=A.size()-1)
    {
        if(A[left] == A[right])
        {
            left--;
            right++;
        }
        else
        {
            mid = left;
            left = mid - 1;
            right = mid + 1;
        }
    }
        
    if(right > A.size() && left < 0)
        return 0;
    else
    {
        ans = A.size()-right;
        //cout<<"Ans = "<<ans<<" and Right = "<<right<<"\n";
        if(ans > 0 && (A[0] == A[1]))
            ans = ans -1;
    }
    return ans;   
}
