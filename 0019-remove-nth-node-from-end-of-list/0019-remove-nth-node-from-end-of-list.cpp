class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;

        ListNode* cu = head;
        int nodes = 0;
        while (cu != NULL) {
            nodes++;
            cu = cu->next;
        }

        int nodegon = nodes - n + 1;


        if (nodegon == 1) {
            return head->next;
        }

        ListNode* curr = head;
        int count = 1;

        while (curr != NULL) {
            if (count == nodegon - 1) {

                curr->next = curr->next->next;
                break; 
            }
            curr = curr->next;
            count++;
        }

        return head;
    }
};