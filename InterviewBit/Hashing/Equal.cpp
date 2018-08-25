/*
https://www.interviewbit.com/problems/equal/
*/

struct indices
{
    int a, b, c, d;
};

bool customCompare(indices first, indices second)
{
    if(first.a == second.a)
    {
        if(first.b == second.b)
        {
            if(first.c==second.c)
            {
                return first.d < second.d;
            }
            return first.c < second.c;
        }
        return first.b < second.b;
    }
    return first.a < second.a;
}

bool validIndices(indices currIndices)
{
    if(currIndices.a<currIndices.b && currIndices.c<currIndices.d && currIndices.a<currIndices.c
        && currIndices.b!=currIndices.c && currIndices.b!=currIndices.d) 
        return true;
    return false;
}

vector<int> Solution::equal(vector<int> &A) 
{
    vector<indices> answers;
    vector<int> ans;
    if(A.size() < 4)
        return ans;
        
    unordered_map<int, pair<int,int> > sumMap;
    // unordered_map<int, pair<int,int> >::const_iterator got = mymap.find (input);
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int sum = A[i] + A[j];
            if(sumMap.find(sum) != sumMap.end())
            {
                struct indices currAnswer;
                currAnswer.a = sumMap[sum].first;
                currAnswer.b = sumMap[sum].second;
                currAnswer.c = i;
                currAnswer.d = j;
                if(validIndices(currAnswer))
                    answers.push_back(currAnswer);
            }
            else
            {
                sumMap[sum] = make_pair(i,j);
            }
        }
    }
    
    sort(answers.begin(), answers.end(), customCompare);
    
    if (answers.size())
    {
        ans.push_back(answers[0].a);
        ans.push_back(answers[0].b);
        ans.push_back(answers[0].c);
        ans.push_back(answers[0].d);
    }
    return ans;
}
