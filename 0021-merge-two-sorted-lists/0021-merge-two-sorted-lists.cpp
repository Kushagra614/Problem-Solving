class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the starting point for the merged list
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy; // Tail pointer to keep track of the end of the merged list
        
        // While both lists are non-empty, compare their values and append the smaller one to the merged list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1; // Append list1 node to merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2; // Append list2 node to merged list
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move the tail pointer
        }
        
        // Append the remaining nodes of either list1 or list2 (whichever is not empty)
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // Return the merged list starting from the next node of dummy (since dummy itself is just a placeholder)
        return dummy->next;
    }
};
