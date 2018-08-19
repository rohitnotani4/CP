/*
https://www.interviewbit.com/problems/intersection-of-linked-lists/
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
listnode* getIntersectionNode(listnode* A, listnode* B) 
{
    int lenA = 0, lenB = 0;
    listnode* firstPointer = A, *secondPointer = B;
    while(A!=NULL)
    {
        lenA++;
        A = A->next;
    }
    
    while(B!=NULL)
    {
        lenB++;
        B = B->next;
    }
    
    int count = 0;
    if(lenA <= lenB)
    {
        
        while(count < lenB - lenA &&  secondPointer != NULL)
        {
            count++;
            secondPointer = secondPointer->next;
        }
        while(firstPointer != NULL)
        {
            if(firstPointer == secondPointer)
                return firstPointer;
                
            secondPointer = secondPointer->next;
            firstPointer = firstPointer->next;
        }
    }
    else
    {
        while(count < lenA - lenB && firstPointer != NULL)
        {
            count++;
            firstPointer = firstPointer->next;
        }
        while(secondPointer != NULL)
        {
            if(firstPointer == secondPointer)
                return secondPointer;
                
            secondPointer = secondPointer->next;
            firstPointer = firstPointer->next;
        }
    }
    return NULL;
}
