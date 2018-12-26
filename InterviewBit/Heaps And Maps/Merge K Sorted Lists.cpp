/*
https://www.interviewbit.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct CustomStruct
{
    int value;
    int ListNo;
    ListNode* nextNode;
    
    CustomStruct(int val, int listno, ListNode* node)
    {
        value = val;
        ListNo = listno;
        nextNode = node;
    }
};
 
struct compare  
{  
    bool operator()(CustomStruct l, CustomStruct r)  
    {  
       return l.value > r.value;  
    } 
};  
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    priority_queue<CustomStruct, vector<CustomStruct>, compare> minQueue;
    
    ListNode* head=NULL, *curr = NULL;
    
    for(int i=0;i<A.size();i++)
    {
        // cout<<"Pushed "<<A[i]->val<<" to queue"<<"\n";
        minQueue.push(CustomStruct(A[i]->val,i,A[i]));
    }
    
    ListNode* newNode = new ListNode(0);
    curr = newNode;
    while(!minQueue.empty())
    {
        CustomStruct currentMin = minQueue.top();
        minQueue.pop();
        // cout<<"Poped Element "<<currentMin.first.first<<"\n";
        
        newNode = new ListNode(currentMin.value);
        
        if(head==NULL)
            head = newNode;
        
        curr->next = newNode;
        // cout<<"newNode Address = "<<curr<<"\n";
        
        if(currentMin.nextNode->next != NULL)
        {
            minQueue.push(CustomStruct(currentMin.nextNode->next->val,currentMin.ListNo,currentMin.nextNode->next));
        
        // cout<<"Value = "<<curr->next->val<<" Index = "<<currentMin.first.second
        // <<" Address "<<currentMin.second->next<<"\n";
        }
        curr = curr->next;
    }
    
    return head;
}
