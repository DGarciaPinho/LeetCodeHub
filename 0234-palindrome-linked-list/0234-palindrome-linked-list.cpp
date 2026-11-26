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

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. Encontra o meio
        ListNode* lento = head;
        ListNode* rapido = head;
        while (rapido != nullptr && rapido->next != nullptr) {
            lento = lento->next;
            rapido = rapido->next->next;
        }

        // 2. Inverte a segunda metade
        ListNode* anterior = nullptr;
        while (lento != nullptr) {
            ListNode* proximo = lento->next;
            lento->next = anterior;
            anterior = lento;
            lento = proximo;
        }

        // 3. Compara as metades
        ListNode* esquerda = head;
        ListNode* direita = anterior;
        while (direita != nullptr) {
            if (esquerda->val != direita->val) {
                return false;
            }
            esquerda = esquerda->next;
            direita = direita->next;
        }

        return true;
    }
};