/*
https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
int findListLength(listnode* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

listnode* removeNthFromEnd(listnode* A, int B) 
{
    listnode* head = A;
    if(head == NULL)
        return head;
        
    int listSize = findListLength(A);
    if(B >= listSize)
    {
        head = head->next;
        return head;
    }
    
    // Remove (listSize - B + 1)th node from front of list
    int count = 0;
    listnode* curr = head, *prev = NULL;
    while(count < (listSize - B))
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    prev->next = curr->next;
    return head;
}
