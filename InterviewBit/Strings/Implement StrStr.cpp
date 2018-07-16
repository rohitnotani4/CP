/*
https://www.interviewbit.com/problems/implement-strstr/
*/

int Solution::strStr(string haystack, string needle) {
        // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    int patternSize = needle.size();
    int stringSize = haystack.size();
    vector<int> matchTable(patternSize,0);
    if(needle.empty() || haystack.empty() || (patternSize > stringSize))
        return -1;
    
    
    //aba   
    matchTable.push_back(0);
    // cout<<"0 ";
    for(int i=1;i<patternSize;i++)
    {
        int pos = 0;
        if(needle[i] == needle[pos + matchTable[i-1]])
            matchTable[i] = matchTable[i-1] + 1;
        else
            matchTable[i] = 0;
        // cout<<matchTable[i]<<" ";
    }    
    
    int i = 0, j =0,start=-1,partialMatchLength = 0,flag = 0;
    while(i<stringSize)
    {
        if(haystack[i] == needle[j])
        {
            if(j==0)
                start = i;
            // cout<<"i = "<<i<<" and j= "<<j<<"\n";
            j++;
            i++;
            partialMatchLength++;
            if(j==patternSize)
            {
                flag=1;
                break;
            }
            
        }
        else
        {
            if((partialMatchLength - 1) >=0)
            {
                i = start + (partialMatchLength - matchTable[partialMatchLength - 1]);
            }
            else
                i++;
            j=0;
            partialMatchLength = 0;
            start = -1;
            // cout<<"i = "<<i<<"\n";
        }
    }
    
    if(!flag)
        start = -1;
    return start;   
}
