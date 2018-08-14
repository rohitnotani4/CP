/*
https://www.interviewbit.com/problems/min-stack/
*/

vector<int> stackList, minStack;
int currentMin = INT_MAX;
 
MinStack::MinStack() {
    stackList.clear();
    minStack.clear();
    // currentMin = null;
}
 
void MinStack::push(int x) {
    stackList.push_back(x);
    minStack.push_back(min(currentMin,x));
    if(x < currentMin)
        currentMin = x;
}
 
void MinStack::pop() {
    if(stackList.size()!=0)
    {
       minStack.pop_back();
       stackList.pop_back();    
    }
    currentMin = INT_MAX;
}
 
int MinStack::top() {
    if(stackList.size()!=0)
    {
        int topIndex = stackList.size()-1;
        return stackList[topIndex];
    }
    return -1;
}
 
int MinStack::getMin() {
    if(stackList.size()!=0)
    {
        return minStack[stackList.size()-1];
    }
    return -1;
}
