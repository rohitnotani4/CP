/*
https://www.interviewbit.com/problems/rotate-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    ListNode* head = A;
    if(B <= 0 || head == NULL || head->next == NULL)
        return head;
        
    int listSize = 1;
    ListNode * permanentHead = head, *tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
        listSize++;
    }
    
    int numberOfRotations = B;      
    if(numberOfRotations >= listSize)
    {
        numberOfRotations = numberOfRotations%listSize;
    }
    
    int index = 0;
    ListNode *newTail;
    //move head to find tail in rotated list
    if(numberOfRotations > 0)
    {
        while(index < (listSize-numberOfRotations))
        {
            newTail = head;
            head = head->next;
            index++;
        }
        tail->next = permanentHead;
        newTail->next = NULL;
    }
    return head;
}
