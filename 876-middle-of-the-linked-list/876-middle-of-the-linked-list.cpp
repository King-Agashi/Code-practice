class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       
       ListNode*    temp    = head;
       ListNode*    ans     = head;
        
        while(temp != NULL && temp -> next != NULL){
            temp = temp -> next -> next;
            ans  = ans  -> next;
        }
        return ans;
    }
};