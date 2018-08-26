/*
https://www.interviewbit.com/problems/window-string/
*/

string Solution::minWindow(string s, string t) 
{
    if(s.size() == 0 || t.size() == 0)
        return "";
    
    int strSize = s.size();
    // Pattern to find
    int patSize = t.size();
    
    unordered_map<char,int> patMap, strMap;
    for(int i=0;i<patSize;i++)
        patMap[t[i]]++;
    
    int start = 0, end = 0, minLen = INT_MAX, minStart = -1, minEnd = -1, counter = 0;
    while(end < strSize)
    {
        strMap[s[end]]++;
        
        if(patMap[s[end]] > 0 && strMap[s[end]] <= patMap[s[end]])
            counter++;
        
        if(counter == patSize)
        {
            // cout<<"Yo Pattern matched :  start : "<<start<<" end : "<<end<<"\n";
            while(start <= end && counter == patSize)
            {
                strMap[s[start]]--;
                
                if(patMap[s[start]] > 0 && strMap[s[start]] < patMap[s[start]])
                    counter--;

                if(end-start+1 < minLen)
                {
                    minLen =  end - start + 1;
                    minStart = start;
                    minEnd = end;
                    // cout<<"Optimized - minStart : "<<minStart<<" minEnd : "<<minEnd<<"\n";
                }
                start++;
            }
        }
        end++;
    }
        
    if(minStart == -1)
        return "";
    
    return s.substr(minStart, minLen);
}
