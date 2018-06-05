/*
https://www.interviewbit.com/problems/wave-array/
*/

vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector<int> B;
    int temp,first,second,flag=1;
    
    sort(A.begin(),A.end());
    
    first=A[0];
    for(int i=1;i<A.size();i++)
    {
     if(i%2==1)
     {
        second=A[i];
        B.push_back(second);
        B.push_back(first);
        flag=0;
     }
     else
     {
         first=A[i];
         flag=1;
     }
    }
    
    if(flag==1)
        B.push_back(first);
    return B;
}
