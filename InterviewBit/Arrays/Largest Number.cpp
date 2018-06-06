/*
https://www.interviewbit.com/problems/largest-number/
*/

bool compareNum(string a, string b) 
{
    return a + b > b + a;
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string result;
    vector<string> str;
    for (int i = 0; i < A.size(); i++) {
        str.push_back(to_string(A[i]));
    }
    
    sort(str.begin(), str.end(), compareNum);
    for (int i = 0; i < str.size(); i++) {
        result += str[i];
    }

    
    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) 
        pos++; 
    return result.substr(pos);
}
