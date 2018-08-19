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
 
listnode* swapNodes(listnode* node1, listnode* node2)
{
    // Eg: 1 -> 2 -> 3, swap 1 and 2
    // Here first we first change 1->next to 3 and then 2->next to 1
    node1->next = node2->next;
    node2->next = node1;
    return node2;
}

listnode* swapPairs(listnode* A) 
{
    if(A == NULL || A->next == NULL)
        return A;
    
    listnode* dummyNode = listnode_new(0);
    dummyNode->next = A;

    listnode* curr = dummyNode;
    while(curr->next != NULL && curr->next->next != NULL)
    {
        curr->next = swapNodes(curr->next, curr->next->next);
        curr = curr->next->next;
    }

    return dummyNode->next;
}
