/*
https://www.interviewbit.com/problems/max-non-negative-subarray/
*/

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

  vector<int> b;

    int start_index=0,end_index=0,curr_count;
  long int curr_sum;

  int ans_start_index=0;
  int ans_end_index=0;
  long int ans_sum=0;
  int ans_count=0;
  for(int i=0;i<A.size();i++)
  {
    start_index=i;
    curr_sum=0,curr_count=0;
    for(int j=i;j<A.size();j++)
    {
      if(A[j]<0)
      {
        i=j;
        break;
      }
      else
      {
        curr_sum=curr_sum + A[j];
        curr_count+=1;
        end_index=j;
        i=j;
      }
    }
    if(ans_sum < curr_sum)
    {
      ans_sum=curr_sum;
      ans_count=curr_count;
      ans_start_index=start_index;
      ans_end_index=end_index;
    }
    if(ans_sum==curr_sum)
    {
      if(curr_count>ans_count)
      {
        ans_sum=curr_sum;
        ans_count=curr_count;
        ans_start_index=start_index;
        ans_end_index=end_index;	
      }
    }
  }
  if(ans_sum==0 && ans_end_index==0)
  {
    return b;
  }
  else
  {
      //printf("The sub array is ");
      for(int k=ans_start_index;k<=ans_end_index;k++)
      {
        b.push_back(A[k]);
        //printf("%d ",A[k]);
      }
      //printf("\n");
      return b;
  }
}
