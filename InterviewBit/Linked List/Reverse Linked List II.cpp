/*
https://www.interviewbit.com/problems/reverse-link-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* newHead = new ListNode(0); 
    
    newHead->next = A;
    ListNode* prev = newHead;
    for(int i=0;i<m-1;i++)
        prev = prev->next;
    
    ListNode* curr = prev->next;
    
    for(int i=0;i<n-m;i++)
    {
        ListNode* nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }
    
    return newHead->next;
}
