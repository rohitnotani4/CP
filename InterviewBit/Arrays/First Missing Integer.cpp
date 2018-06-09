/*
https://www.interviewbit.com/problems/first-missing-integer/
*/

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> :: iterator it = A.begin();
    while(it!=A.end()) {
        if(*it<0) {  
                A.erase(it);
        }
        else {
            it++;    
        }

    }
    it = A.begin();
    //cout<<"Later: "<<A.size();
    //disp(A);
    for(int i=0;i<A.size();i++) {
        if(abs(A[i])-1<A.size()) { 
            //cout<<": "<<abs(A[i])-1<<" is less than : "<<A.size()<<endl;
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }       //cout<<"Marking index: "<<abs(A[i])-1<<" as negative!\n";
    }
    //disp(A);
    int c=A.size()+1;
    for(int i=0;i<A.size();i++) {
        if(A[i]>0) { 
            c=i+1;
            break;
        }
    }
    //cout<<endl;
    return c;

}
