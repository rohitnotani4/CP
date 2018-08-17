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

    ListNode* curr, *prev, *head;
    
    if(A == NULL)
        return A;
    
    vector<pair<ListNode* ,bool> > trackData;
    
    curr = A;
    while(curr!=NULL)
    {
        trackData.push_back(make_pair(curr,true));
        curr = curr->next;
    }
    
    curr = trackData[0].first, prev = NULL;
    for(int i=1;i<trackData.size();i++)
    {
        curr = trackData[i].first;
        prev = trackData[i-1].first;
        if(prev != NULL && (curr->val == prev->val))
        {
            trackData[i].second = false;
            trackData[i-1].second = false;   
            //cout<<i<<" ->false"<<" ";
        }
    }
    // cout<<"\n";
    head = NULL, curr = NULL;
    int first = 1;
    for(int i=0;i<trackData.size();i++)
    {
        if(trackData[i].second)
        {
            if(first)
            {
                head = curr = prev = trackData[i].first;
                curr->next = prev->next = NULL;
                first = 0;
            }
            else
            {
                curr = trackData[i].first;
                prev->next = curr;
                prev = curr;
            }
        }
    }
    
    return head;
}
