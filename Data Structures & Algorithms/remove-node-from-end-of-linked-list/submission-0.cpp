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
private:
    int getSize(ListNode* head) {
        int sz = 0;
        while(head) {
            sz++;
            head = head->next;
        }
        return sz;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        if(size == n) return head->next;
        
        int target = size - n;
        ListNode *prev, *cur = head;
        while(target-- > 0) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return head;
    }
};