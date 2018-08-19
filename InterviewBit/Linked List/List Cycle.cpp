/*
https://www.interviewbit.com/problems/list-cycle/
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
 
listnode* detectCycle(listnode* A) {
    listnode* cycleNode = NULL;
    
    if(A == NULL || A->next == NULL)
        return cycleNode;
    
    listnode* slow = A, *fast = A;    
    int cycleFlag = 0;
    while(slow != NULL && fast !=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            cycleFlag = 1;
            break;
        }
    }
    
    if(!cycleFlag)
        return NULL;
    
    fast = A;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
