/*
https://www.interviewbit.com/problems/reverse-linked-list/
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
 * 
 * @Output head pointer of list.
 */
listnode* reverseList(listnode* A) 
{
    
    listnode* curr, *prev, *head = A;
    curr = A;
    prev = NULL;
    while(curr != NULL)
    {
        listnode* next = curr->next; // Copy the address of next node
        curr->next = prev; // Assign prev address in next field of current node
        prev = curr; // Change prev pointer to current
        curr = next; // Change curr pointer to next
    }
    head = prev;
    return head;
}
