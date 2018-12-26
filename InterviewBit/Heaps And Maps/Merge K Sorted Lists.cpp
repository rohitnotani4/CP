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


struct CompareNode 
{  
    bool operator()(ListNode* const & p1, ListNode* const & p2)  
    {  
       return p1->val > p2->val;  
    } 
};  
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> minQueue;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i] != NULL)
        {
            minQueue.push(A[i]);    
        }
    }
    
    ListNode* curr = new ListNode(0);
    ListNode* head = curr;
    while(!minQueue.empty())
    {
        curr->next = minQueue.top();
        minQueue.pop();
        
        curr = curr->next;
        if(curr->next != NULL)
        {
            minQueue.push(curr->next);
        }
    }
    return head->next;
}
