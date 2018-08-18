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
    
    listnode* head = listnode_new(0);
    listnode* permanentHead = head;

    while(A != NULL && B != NULL)
    {
        if(A->val <= B->val)
        {
            head->next = A;
            A = A->next;
        }
        else
        {
            head->next = B;
            B = B->next;
        }
        head = head->next;
    }
    
    if(A != NULL)
        head->next = A;
    
    if(B != NULL)
        head->next = B;
    
    return permanentHead->next;
}
