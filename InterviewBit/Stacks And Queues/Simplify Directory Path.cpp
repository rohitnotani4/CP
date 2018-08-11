/*
https://www.interviewbit.com/problems/simplify-directory-path/
*/

string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string ans, revAns;
    if(!A.size())
        return ans;

    int len = 0;
    stack<char> track;
    //ans.push_back('/');
    while(len < A.size())
    {
        if(A[len] == '/')
        {
            if(track.empty() || track.top() != '/')
                track.push('/');
            len++;
        }
        else
        if(A[len] == '.')
        {
            if(len+1 < A.size() && A[len+1]=='.')
            {
                while(!track.empty())
                {
                    track.pop();
                    if(!track.empty() && track.top()=='/')
                        break;
                }

                len += 2;
            }
            else
                len++;
        }
        else
        {
            track.push(A[len]);
            len++;
        }
        //if(!track.empty())
        //    cout<<"Top "<<track.top()<<" and stack size = "<<track.size()<<"\n";
    }

    if(track.empty())
        track.push('/');

    if(track.size() > 1 && track.top()=='/')
        track.pop();


    while(!track.empty())
    {
        revAns.push_back(track.top());
        track.pop();
    }

    for(int i=revAns.size()-1;i>=0;i--)
        ans.push_back(revAns[i]);

    return ans;    

}
