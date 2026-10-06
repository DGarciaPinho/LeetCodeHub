/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int soma = carry;

        if (l1 != NULL) {
            soma += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            soma += l2->val;
            l2 = l2->next;
        }

        struct ListNode* novo = malloc(sizeof *novo);

        if (novo == NULL) {
            struct ListNode* atual = dummy.next;

            while (atual != NULL) {
                struct ListNode* proximo = atual->next;
                free(atual);
                atual = proximo;
            }

            return NULL;
        }

        novo->val = soma % 10;
        novo->next = NULL;
        carry = soma / 10;

        tail->next = novo;
        tail = novo;
    }

    return dummy.next;
}