/*
https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
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
listnode* swapPairs(listnode* A) 
{
    if(A == NULL || A->next == NULL)
        return A;
        
    listnode* head = A->next, *prev = A, *curr = A->next, *lastChanged = NULL;
    
    while(prev != NULL && curr != NULL)
    {
        // Previous node of current 2 nodes being swapped
        if(lastChanged != NULL)
        {
            lastChanged->next = curr;
        }
        
        // Swap prev and current nodes    
        listnode* temp = curr->next;
        curr->next = prev;
        prev->next = temp;
        lastChanged = prev;
        
        
        // Check if we have 2 more nodes ahead
        if(prev->next == NULL || prev->next->next == NULL)
            return head;
        
        // Change both pointers (prev and next) to nodes ahead
        prev = prev->next;
        curr = prev->next;
    }
    return head;   
}
