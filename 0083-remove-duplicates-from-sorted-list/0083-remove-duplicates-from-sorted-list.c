/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == cur->val) {
            struct ListNode* dup = cur->next;
            cur->next = dup->next;
            free(dup);
        } else {
            cur = cur->next;
        }
    }
    return head;
}