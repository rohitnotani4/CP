/*
https://www.interviewbit.com/problems/count-and-say/
*/

string Solution::countAndSay(int A) {
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  string final;
  vector<int> temp,ans;

  ans.push_back(1);
  int i =1;

  while(i<A)
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
    for(int k = 0;k<temp.size();k++)
      ans.push_back(temp[k]);
    temp.clear();
    i++;
  }

  for(int k=0;k<ans.size();k++)
  {
    // cout<<ans[k]<<" ";
    final.push_back((ans[k]+48));
  }

  return final;
}
