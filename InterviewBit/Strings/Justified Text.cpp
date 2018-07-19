/*
https://www.interviewbit.com/problems/justified-text/
*/

string constructLastLine(vector<string>& words,int startIndex, int endIndex, int lineLengthLimit)
{
    // cout<<"I am here at last line\n";
    string line(words[startIndex]);
    for(int i=startIndex+1;i<=endIndex;i++)
    {
        line += " ";
        line += words[i];
    }
        
        
    int numberOfSpaces = lineLengthLimit - line.size();
    string quotientSpaces(numberOfSpaces, ' ');
    line += quotientSpaces;
    // cout<<line<<"\n";
    return line;
}

vector<pair<int,int>> constructStartEndPairs(vector<string>& A,int lineLengthLimit)
{
    vector<pair<int,int>> startEndPairs;
    int currentCharCount = 0,startIndex = 0, endIndex = 0;
    for(int wordIndex=0;wordIndex<A.size();wordIndex++)
    {
        // cout<<A[wordIndex].size()<<" ";
        currentCharCount = currentCharCount == 0 ? -1 : currentCharCount;
        if(currentCharCount + A[wordIndex].size() + 1 <= lineLengthLimit)
        {
            endIndex = wordIndex;
            currentCharCount += A[wordIndex].size() + 1;
            // cout<<"CurrentCharCount = "<<currentCharCount<<"\n";
        }
        else
        {
            startEndPairs.push_back(make_pair (startIndex,endIndex));
            // cout<<startIndex<<" "<<endIndex<<"\n";
            startIndex = wordIndex;
            endIndex = wordIndex;
            currentCharCount = A[wordIndex].size();
        }
    }
    startEndPairs.push_back(make_pair (startIndex,endIndex));
    return startEndPairs;
}

string constructLine(vector<string>& words,int startIndex, int endIndex, int lineLengthLimit)
{
    string line(words[startIndex]);
    int numberOfWords = endIndex - startIndex + 1;
    int charCount = 0;
    for(int i=startIndex;i<=endIndex;i++)
        charCount += words[i].size();
        
    int numberOfSpaces = lineLengthLimit - charCount;
    if(numberOfWords > 1)
    {
        int spacesPerGap = numberOfSpaces/(numberOfWords-1);
        int remainingSpaces = numberOfSpaces%(numberOfWords-1);
        int i = startIndex+1;
        while(i<=endIndex)
        {
            string quotientSpaces(spacesPerGap, ' ');
            line += quotientSpaces;
            
            if(remainingSpaces > 0)
                line += " ";
            
            line += words[i];
            remainingSpaces--;
            i++;
        }
    }
    else
    {
        string quotientSpaces(numberOfSpaces, ' ');
        line += quotientSpaces;
    }
    return line;
}

vector<string> constructAllLines(vector<string>& words,int lineLengthLimit)
{
    vector<pair<int,int> > startEndPairs = constructStartEndPairs(words, lineLengthLimit);
    int size = startEndPairs.size();
    vector<string> allLines;
    string currentLine;
    for(int pairIndex=0;pairIndex<size;pairIndex++)
    {
        if (pairIndex == size-1)
            currentLine = constructLastLine(words, startEndPairs[pairIndex].first, startEndPairs[pairIndex].second, lineLengthLimit);
        else
            currentLine = constructLine(words, startEndPairs[pairIndex].first, startEndPairs[pairIndex].second, lineLengthLimit);
        
        allLines.push_back(currentLine);
    }
    return allLines;
}

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> answer;
    
    if(A.size())
        answer = constructAllLines(A,B);
    return answer;
}
