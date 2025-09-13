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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* curr = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry!= 0) {

            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // now the core logic
            int dig = sum % 10;
            carry = sum / 10;
            

            // create a new node
            ListNode* nn = new ListNode(dig);


            if (ans == nullptr) {
                ans = nn;
                curr = nn;
            } else {
                curr->next = nn;
                curr = nn;
            }

            
        }

        return ans;
    }
};