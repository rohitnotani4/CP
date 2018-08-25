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
    RandomListNode* head = A;
    if(head == NULL)
            return head;
        
    unordered_map<RandomListNode*,RandomListNode*> randomPointerMap;
    RandomListNode* curr = head;
    while(curr != NULL)
    {
        randomPointerMap[curr] = new RandomListNode(curr->label);
        curr = curr->next;
    }
    
    curr = head;
    while(curr!=NULL)
    {
        RandomListNode* temp = randomPointerMap[curr];
        temp->next = randomPointerMap[curr->next];
        temp->random = randomPointerMap[curr->random];
        curr = curr->next;
    }
    return randomPointerMap[head];       
}
