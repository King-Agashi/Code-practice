class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow = head; 
       ListNode* fast = head; 
        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                fast=fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};