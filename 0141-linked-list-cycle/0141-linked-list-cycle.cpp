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
    bool hasCycle(ListNode *head) {
        
        //USING FAST AND SLOW POINTERS

        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL)
        {
            //they will before getting checked otherwise their starting at head will return true
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                return true;
            }
        }

        return false;


        //USING HASHSET
        // unordered_set<ListNode*>vis;

        // ListNode* curr = head;

        // while(curr!= nullptr)
        // {
        //     if(vis.count(curr))
        //     {
        //         return true;
        //     }

        //     vis.insert(curr);
        //     curr = curr->next;
        // }

        // return false;



        
    }
};