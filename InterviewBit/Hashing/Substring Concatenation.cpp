/*
https://www.interviewbit.com/problems/substring-concatenation/
*/

int checkIfFound
(string A, map<string,int>& wordMap,int startIndex, int concatenatedLen, int wordLen)
{
    map<string,int> outputMap;
    int words = 0;
    for(int i=startIndex;i<(startIndex+concatenatedLen);i+= wordLen)
    {
        string thisSubStr = A.substr(i,wordLen);
        if(wordMap.find(thisSubStr) == wordMap.end())
             return -1;
         else
         {
            outputMap[thisSubStr]++;
            if(outputMap[thisSubStr] > wordMap[thisSubStr])
                return -1;
            else
                words++;
        }
    }
    
    return startIndex;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    
    if(B.size()==0 || A.size()==0)
        return ans;
        
    map<string,int> wordMap;
    
    int wordLen = B[0].size();
    int stringLen = A.size();
    int numberOfWords = B.size();
    int concatenatedLen = wordLen * numberOfWords;
    
    
    for(int i=0;i<B.size();i++)
        wordMap[B[i]]++;
    
    int i = 0, index=-1; //abab
    while(i + concatenatedLen <= stringLen)
    {
        index = checkIfFound(A,wordMap,i,concatenatedLen,wordLen); 
        if(index != -1)
            ans.push_back(index);
        i++;
    }
    return ans; 
}
