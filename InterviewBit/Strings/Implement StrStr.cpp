/*
https://www.interviewbit.com/problems/implement-strstr/
*/

vector<int> computeLPSTable(string& pattern, int patternSize)
{
    vector<int> LPS(patternSize,0);    
    int index = 1, len = 0;
    while(index < patternSize)
    {
        if(pattern[index] == pattern[len])
        {
            len++;
            LPS[index] = len;
            index++;
        }
        else
        {
            if(len > 0)
            {
                len = LPS[len-1];
            }
            else
            {
                len = 0;
                index++;
            }
        }
    }
    return LPS;
}

int KMP(string& haystack, string& needle)
{
    vector<int> LPS; 
    LPS = computeLPSTable(needle, needle.size());
    
    int  sIndex=0, pIndex = 0;
    while(sIndex < haystack.size() && pIndex < needle.size())
    {
        if(haystack[sIndex] == needle[pIndex])
        {
            sIndex++;
            pIndex++;
        }
        else
        {
            if(pIndex != 0)
                pIndex = LPS[pIndex-1];
            else
                sIndex++;
        }
    }
    
    if(pIndex == needle.size())
        return sIndex-pIndex; // Since we have to return start of string Index 

    return -1;
}

int Solution::strStr(string haystack, string needle) {
        // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(needle.empty() || haystack.empty() || (needle.size() > haystack.size()))
        return -1;
        
    return KMP(haystack, needle);
}
