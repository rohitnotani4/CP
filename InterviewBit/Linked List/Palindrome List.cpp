/*
https://www.interviewbit.com/problems/palindrome-list/
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
 * @Output Integer
 */
 
listnode* originalHead = NULL;
int half = 0, findIfHalf=0;
void Reverse(listnode* newHead, int *ansPointer, int *countPointer)
{
    (*countPointer)++;
	if (newHead->next == NULL)
	{
		half = (*countPointer) / 2;
		return;
	}
	Reverse(newHead->next,ansPointer, countPointer);
	if (findIfHalf < half)
	{
		if (originalHead->val == newHead->next->val)
			(*ansPointer) &= 1;
		else
			(*ansPointer) &= 0;
		listnode * temp = newHead->next; // temp = head
		temp->next = newHead;
		newHead->next = NULL;
		originalHead = originalHead->next;
	}
	
	findIfHalf++;
	// printf("FindIfHalf = %d\n",findIfHalf);
}
 
int lPalin(listnode* A) {
    
    if (A == NULL)
		return 0;
 
	listnode*newHead, *temp;
	int ans = 1, count = 0;
	int *ansPointer = &ans, *countPointer = &count;
	originalHead = newHead = temp = A;
	Reverse(newHead, ansPointer, countPointer);
	
	//This is specific for InterviewBit, clearing out all global variables
	// Not clearing this would give different results for same output in multiple runs
    originalHead = NULL;
    half = 0, findIfHalf=0;
	return ans;
}
