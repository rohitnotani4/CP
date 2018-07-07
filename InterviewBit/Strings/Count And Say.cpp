/*
https://www.interviewbit.com/problems/count-and-say/
*/

string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string answer;
    vector<int> temp,ans;
    
    int index =1;
    ans.push_back(1);
    while(index<A)
    {
        int j = 0,value,count;
        while(j < ans.size())
        {
            value = ans[j];
            count = 0;
            while((j < ans.size()) && value == ans[j])
            {
                j++;
                count++;
            }
            temp.push_back(count);
            temp.push_back(value);
        }
        ans.clear();
        ans = temp;
        temp.clear();
        index++;
    }
    
    for(int k=0;k<ans.size();k++)
        answer.push_back((ans[k]+48));
    
    return answer;
}
