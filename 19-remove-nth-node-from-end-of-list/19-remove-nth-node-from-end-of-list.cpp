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
    int getSize(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = getSize(head);
        if(m == 1){
            head = NULL;
            return head;
        }
        if(m-n == 0){
            ListNode* cur = head;
            head=head->next;
            cur = NULL;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        for(int i = 0;i<(m-n);i++){
            prev = cur;
            cur = prev->next;
        }
        prev->next = cur->next;
        cur->next=NULL;
        delete cur;
        return head;
    }
};