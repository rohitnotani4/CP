/*
https://www.interviewbit.com/problems/partition-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    ListNode dummyNode1(0), dummyNode2(0);
    ListNode *head = A, *p1 = &dummyNode1, *p2 = &dummyNode2;
    // If the value is less than B keep appending to dummyNode1
    // and if value is equal/greater, keep appending to dummyNode1
    // At the end, concat the 2 lists by setting p1->next to dummyNode2.next
    // and set the p2.next to NULL to end the list
    while (head) 
    {
        if (head->val < B)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = dummyNode2.next;
    return dummyNode1.next;
}
