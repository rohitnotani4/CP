/*

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

listnode* InsertInsortedList(listnode* head, int value)
{
    int tempValue;
    listnode* prevNode = NULL, *nextNode = NULL, *currNode = head, *temp;
    listnode* nodeToInsert = listnode_new(value);

    if (head == NULL || head->val >= nodeToInsert->val)
    {
        head = nodeToInsert;
        nodeToInsert->next = currNode;
        return head;
    }
    while (currNode != NULL && currNode->val < value)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    temp = prevNode->next;
    prevNode->next = nodeToInsert;
    nodeToInsert->next = temp;

    return head;
}
 
listnode* insertionSortList(listnode* A) 
{
    listnode * outPutListHead = NULL, *inputList = A;
    while (inputList != NULL)
    {
        outPutListHead = InsertInsortedList(outPutListHead, inputList->val);
        inputList = inputList->next;
    };
    return outPutListHead;
}
