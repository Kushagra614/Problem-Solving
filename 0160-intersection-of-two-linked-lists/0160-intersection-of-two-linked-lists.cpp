/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //brute force
        unordered_map<ListNode*, int>mp;
        
        //iterate one ll
        ListNode* curr = headA;
        while(curr!=NULL)
        {
            mp[curr] = 1;
            curr = curr->next;
        }

        ListNode* purr = headB;
        while(purr!=NULL)
        {
            if(mp.find(purr) != mp.end())
            {
                return purr;
            }
            purr = purr->next;
        }
        return NULL;

    }
};