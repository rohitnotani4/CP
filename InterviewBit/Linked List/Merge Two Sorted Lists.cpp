/*
https://www.interviewbit.com/problems/merge-two-sorted-lists/
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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* mergeTwoLists(listnode* A, listnode* B) {
    
    if(A == NULL)
        return B;
    
    if(B == NULL)
        return A;
    
    listnode* head = NULL;
    
    if(A->val < B->val)       
    { 
        head = A; 
        A = A->next; 
    }
    else                        
    { 
        head = B; 
        B = B->next; 
    }
    
    listnode* curr = head;     // pointer to form new list
    
    while(A != NULL && B != NULL)
    {
        if(A->val < B->val)
        {
            curr->next = A;
            A = A->next;
        }
        else
        {
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }
    
    if(A!=NULL)
        curr->next = A;
    else
        curr->next = B;
        
    
    
    return head;
}
