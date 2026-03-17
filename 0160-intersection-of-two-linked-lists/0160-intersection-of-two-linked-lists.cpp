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

        // unordered_map<ListNode*, int>mp;
        // //iterate one ll
        // ListNode* curr = headA;
        // while(curr!=NULL)
        // {
        //     mp[curr] = 1;
        //     curr = curr->next;
        // }

        // ListNode* purr = headB;
        // while(purr!=NULL)
        // {
        //     if(mp.find(purr) != mp.end())
        //     {
        //         return purr;
        //     }
        //     purr = purr->next;
        // }
        // return NULL;

// --------------------------------------------------------------------------------
        //OPT APPROACH

        int lenA = 0;
        ListNode* curr = headA;
        while(curr!=NULL)
        {
            curr = curr->next;
            lenA++;
            
        }
        

        int lenB = 0;
        ListNode* purr = headB;
        while(purr!=NULL)
        {
            purr = purr->next;
            lenB++;
        }
        
        ListNode* A = headA;
        ListNode* B = headB;
        if(lenA > lenB)
        {
            int diff = lenA - lenB;
            while(diff > 0 && A!=NULL)
            {
                A = A->next;
                diff--;
            }
        }
        else if(lenA < lenB)
        {
            int diff = lenB - lenA;
            while(diff > 0 && B!=NULL)
            {
                B = B->next;
                diff--;
            }
        }
        
        //start comparing nodes
            while(A!=NULL && B!=NULL)
            {
                if(A == B) return A;
                A = A->next;
                B = B->next;
            }
            
        return NULL;

    }
};