/*
https://www.interviewbit.com/problems/add-two-numbers-as-lists/
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
listnode* addTwoNumbers(listnode* A, listnode* B) 
{
    
    listnode* curr = listnode_new(0);
    listnode* head = curr;

    int carry = 0;
    while(A != NULL && B!= NULL)
    {
        int sum = A->val + B->val + carry;
        carry = sum/10;
        curr->next = listnode_new(sum%10);
        curr = curr->next;
        A = A->next;
        B = B->next;
    }
    
    while(A != NULL)
    {
        int sum = A->val + carry;
        carry = sum/10;
        curr->next = listnode_new(sum%10);
        curr = curr->next;
        A = A->next;
    }
    
    while(B != NULL)
    {
        int sum = B->val + carry;
        carry = sum/10;
        curr->next = listnode_new(sum%10);
        curr = curr->next;
        B = B->next;
    }
    
    if(carry)
        curr->next = listnode_new(carry);
        
    return head->next;
}
