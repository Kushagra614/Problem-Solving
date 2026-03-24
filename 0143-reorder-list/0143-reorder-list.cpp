/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* curr = head;
        while (curr != NULL) {
            dq.push_back(curr);
            curr = curr->next;
        }

        ListNode* ll = head;
        while (!dq.empty()) {
            ListNode* fro = dq.front();
            dq.pop_front();
            ll->next = fro;
            ll = ll->next;

            if (!dq.empty()) {
                ListNode* bak = dq.back();
                dq.pop_back();
                ll->next = bak;
                ll = ll->next;
            }
        }
        ll->next = NULL;
    }
};