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
listnode* removeNthFromEnd(listnode* A, int B) {
    listnode* curr = A, *nextNext;
    
    if(curr==NULL)
        return curr;
    
    int count=1;
    while(curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    curr = A;
    if(count - B > 0)
    {
        int i=1;
        while(i!= (count-B))
        {
            curr = curr->next;
            i++;
        }
        nextNext = curr->next->next;
        free(curr->next);
        curr->next = nextNext;
    }
    else
    {
        if(curr->next != NULL)
        {
            nextNext = curr->next;
            free(curr);
            curr = nextNext;
        }
        else
            curr = NULL;
            
        return curr;    
    }
    return A;
}
