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
    listnode* head = listnode_new(0);
    listnode* temp = head;
    
    unsigned long long firstSum =0,secondSum=0,totalSum=0;
    
    if(A==NULL && B==NULL)
        return A;
    
    int carry=0;
    while(A!=NULL && B!=NULL)
    {
        totalSum = ( (unsigned long long)(A->val) +  (unsigned long long)(B->val)) + carry;
        if(totalSum >= 10)
        {
            carry = 1;
            totalSum %= 10;
        }
        else
            carry = 0;
            
        // printf("Total Sum = %d\n",totalSum);
        listnode* newNode = listnode_new(totalSum);
        temp->next = newNode;
        temp = temp->next;
        A = A->next;
        B = B->next;
    }
    
    
    while(A!=NULL)
    {
        totalSum = ( (unsigned long long)(A->val) + carry);
        if(totalSum >= 10)
        {
            carry = 1;
            totalSum %= 10;
        }
        else
            carry = 0;
        
        // printf("Total Sum = %d\n",totalSum);
        listnode* newNode = listnode_new(totalSum);
        temp->next = newNode;
        temp = temp->next;
        
        A = A->next;
    }
    
    while(B!=NULL)
    {
        totalSum = ( (unsigned long long)(B->val) + carry);
        if(totalSum >= 10)
        {
            carry = 1;
            totalSum %= 10;
        }
        else
            carry = 0;
        
        // printf("Total Sum = %d\n",totalSum);
        listnode* newNode = listnode_new(totalSum);
        temp->next = newNode;
        temp = temp->next;
        
        B = B->next;
    }
    
    if(carry > 0)
    {
        listnode* newNode = listnode_new(carry);
        temp->next = newNode;
        temp = temp->next;
    }    
    return head->next;
}
