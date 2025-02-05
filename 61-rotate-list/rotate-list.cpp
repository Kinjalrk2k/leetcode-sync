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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        int size = 0;
        ListNode *current = head, *prev = NULL, *old_head;

        while(current) {
            current = current->next;
            size++;
        }

        k = k >= size ? k % size : k;
        if(k == 0) return head;

        current = head;
        for(int i=0; i<size-k; i++) {
            prev = current;
            current = current->next;
        }

        if(prev) prev->next = NULL;
        old_head = head;
        head = current;

        while(current->next) current = current->next;
        current->next = old_head;

        return head;
    }
};