/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
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
 
ListNode* Solution::deleteDuplicates(ListNode* A) {

    if(A == NULL)
        return A;
    
    ListNode  *head = A, *prev = A, *curr = A->next;
    while(curr != NULL)
    {
        // If the previous and current value match, we have a duplicate
        // In this case, we simply change the "next" of prev pointer to 
        // point to next element instead of curr element
        // E.x: 1->1->2
        // Here prev = 1 and curr = 1, so we make prev point to 2 directly
        if(prev->val == curr->val)
            prev->next = curr->next;
        else
            prev = prev->next; 
        curr = curr->next;
    }
    return head;
}
