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
 * @Output Integer
 */

listnode* reverseList(listnode* head)
{
    listnode* curr = head;
    listnode* prev = NULL;
    while(curr != NULL)
    {
        listnode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int compareLists(listnode* firstHalfHead, listnode* secondHalfHead)
{
    while(firstHalfHead != NULL && secondHalfHead != NULL)
    {
        if(firstHalfHead->val != secondHalfHead->val)
            return 0;
        
        firstHalfHead = firstHalfHead->next;
        secondHalfHead = secondHalfHead->next;
    }
    return 1;
}

int lPalin(listnode* A) {
    
    listnode* head = A;
    if (head == NULL)
        return 0;

    
    // Find the middle node of list using slow and fast pointer 
    listnode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    listnode *firstHalfStart = head;
    listnode *secondHalfStart = slow;
    // If the list size is odd, then fast is not NULL and the slow pointer points to 
    // the middle element, hence we take the slow->next which will be "head" for the 
    // secondHalf that we have to reverse
    if(fast != NULL)
        secondHalfStart = slow->next;
    
    // Reverse the secondHalf of list
    listnode *newHead = reverseList(secondHalfStart); 
    
    // Compare the values of first and second half
    return compareLists(firstHalfStart, newHead);
}
