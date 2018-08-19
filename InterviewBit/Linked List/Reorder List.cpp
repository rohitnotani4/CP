/*
https://www.interviewbit.com/problems/reorder-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* start) 
{
    ListNode* curr, *prev, *currHead;
    curr = start;
    prev = NULL;
    while(curr != NULL)
    {
        ListNode* next = curr->next; // Copy the address of next node
        curr->next = prev; // Assign prev address in next field of current node
        prev = curr; // Change prev pointer to current
        curr = next; // Change curr pointer to next
    }
    currHead = prev;
    start = 
    return currHead;
}
    
ListNode* Solution::reorderList(ListNode* A) 
{
    ListNode* head = A;    
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* pre = head;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* secondHalfHead =  slow->next;
    slow->next = NULL;
    
    ListNode* newsecondHalfHeadHead = reverseList(secondHalfHead);        
    while(newsecondHalfHeadHead != NULL)
    {
        ListNode* currNode = head->next;
        head = head->next = newsecondHalfHeadHead;
        newsecondHalfHeadHead = currNode;
    }
    
    return head;
}
