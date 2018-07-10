/*
https://www.interviewbit.com/problems/length-of-last-word/
*/

int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans = 0;
    char space =' ';
    string word;
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]!=' ')
        {
            do
            {
                word.push_back(A[i]);
                i--;
            } while(i>=0 && A[i]!=' ');
            
            if(word.size() > 0)
                break;
        }
    }    
    return word.size();
}
