/*
https://www.interviewbit.com/problems/copy-list/
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) 
{
    RandomListNode* curr = A, *next = NULL;
    if(curr == NULL)
        return NULL;

    // Create copy of each node and attach it beside the same node
    // Ex. : A->B->C changes to A->A'->B->B'->C->C'
    while(curr != NULL)
    {
        next = curr->next;
        RandomListNode* newNode = new RandomListNode(curr->label);
        curr->next = newNode; // A->A'
        newNode->next = next; // A'->B
        curr = next;
    }
    
    curr = A;
    // Assign the random pointers in the same way
    while(curr != NULL)
    {
        if(curr->random != NULL)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // Detach the original list i.e A->A'->B->B'->C->C' becomes A'->B'->C'
    RandomListNode* originalNode = A, *copy = NULL, *finalHead;
    RandomListNode* dummyNode = new RandomListNode(0);
    finalHead = dummyNode;
    while(originalNode != NULL)
    {
        next = originalNode->next->next; // next = B
        
        // Extract the copy 
        copy = originalNode->next; // A'
        dummyNode->next = copy; // A'->next
        dummyNode = copy; // A'

        // restore the original list
        originalNode->next = next; // A->A'->B to A->B

        originalNode = next; // B
    }
    
    return finalHead->next;
}
