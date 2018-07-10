/*
https://www.interviewbit.com/problems/reverse-the-string/
*/

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> words;
    string word;
    int index=A.size()-1;
    while(index >= 0)
    {
        if(A[index]==' ')
        {
            if(word.size())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word.push_back(A[index]);
        }
        index--;
    }
    words.push_back(word); // Last word
    A.clear();
    for(int wordIndex=0;wordIndex<words.size();wordIndex++)
    {
        for(int letterIndex=words[wordIndex].size()-1;letterIndex>=0;letterIndex--)
            A.push_back(words[wordIndex][letterIndex]);
        if (wordIndex != words.size()-1)
            A += " ";
    }
    return ;
}
