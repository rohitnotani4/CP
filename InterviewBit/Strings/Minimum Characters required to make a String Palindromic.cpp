/*
https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
*/

int computeLPS(string input)
{
    vector<int> LPS(input.size(),0);
    int prefixEnd = 0;
    for(int currentIndex = 1;currentIndex < LPS.size(); currentIndex++)
    {
        if(input[prefixEnd]==input[currentIndex])
        {
            LPS[currentIndex] = LPS[currentIndex-1] + 1;
            prefixEnd++; //Extend match in prefix and postfix
        }
        else
        {
            // We try to match a shorter substring by assigning prefixEnd to 
            // LPS[currentIndex-1], we will shorten the match string length, 
            // and jump to the prefix part that we used to match postfix ended at i - 1
            prefixEnd = LPS[currentIndex - 1];
            
            while(prefixEnd > 0 && input[prefixEnd]!=input[currentIndex])
            {
                prefixEnd = LPS[prefixEnd - 1];
            }
            
            if(input[prefixEnd]==input[currentIndex])
            {
                prefixEnd++;
            }
            
            LPS[currentIndex] = prefixEnd;
        }
    }
    return LPS[input.size()-1];
}

int Solution::solve(string A) {

    if(A.size() < 1)
        return 0;
        
    string copyInput(A); // Create to copy to reverse and concatenate
    reverse(copyInput.begin(),copyInput.end());
    string combinedString = A + " " + copyInput;
    
    //Get the maximum size palindrome in combined string from start i.e. 0
    int longestPalindromeFromStart = computeLPS(combinedString);
    return A.size() - longestPalindromeFromStart;
}
