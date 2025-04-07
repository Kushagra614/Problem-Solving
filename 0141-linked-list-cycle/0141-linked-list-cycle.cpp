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
        
        //USING HASHSET
        unordered_set<ListNode*>vis;

        ListNode* curr = head;

        while(curr!= nullptr)
        {
            if(vis.count(curr))
            {
                return true;
            }

            vis.insert(curr);
            curr = curr->next;
        }

        return false;

        
    }
};