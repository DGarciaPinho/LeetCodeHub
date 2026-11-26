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

 // Primeira soluÃ§Ã£o 
 /* 
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = Maior(head);
        ListNode* antigo = head;
        ListNode* atual = head;

        while(atual->next!=nullptr){
            if(atual->val < atual->next->val){
                antigo->next = atual->next;
                atual = atual->next;
            }else{
                antigo = atual;
                atual = atual->next;
            }

        }

        return head;
    }

    ListNode* Maior(ListNode* No){
        ListNode* Maior = No;
        No = No->next;
        while(No!=nullptr){
            if(Maior->val<No->val){
                Maior = No;
            }
            No = No->next; 
        }
        return Maior;
    }
};
*/ 

// SoluÃ§Ã£o N^2 

/*
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = Maior(head);
        ListNode* antigo = head;
        ListNode* atual = head->next;
        while(atual != nullptr){
            if(atual != Maior(atual)){
                antigo->next = Maior(atual);
                antigo = antigo->next;
            }else{
                antigo = atual;
            }
            atual = antigo->next;
        }
        return head;
    }

    ListNode* Maior(ListNode* No){
        ListNode* Maior = No;
        No = No->next;
        while(No!=nullptr){
            if(Maior->val<No->val){
                Maior = No;
            }
            No = No->next; 
        }
        return Maior;
    }
};
*/

// Fim da soluÃ§Ã£o NÂ²   

// SoluÃ§Ã£o Um pouco melhor que NÂ²

/*
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = Maior(head);
        ListNode* antigo = head;
        ListNode* atual = head->next;
        while(antigo->next != nullptr){
            antigo->next = Maior(antigo->next);
            antigo = antigo->next;
        }
        return head;
    }

    ListNode* Maior(ListNode* No){
        ListNode* Maior = No;
        No = No->next;
        while(No!=nullptr){
            if(Maior->val<No->val){
                Maior = No;
            }
            No = No->next; 
        }
        return Maior;
    }
};
*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> pilha;
        ListNode* atual = head;
        while(atual!=nullptr){
            pilha.push(atual);
            atual = atual->next;
        }
        ListNode* Maior = pilha.top();
        pilha.pop();
        while(!pilha.empty()){
            atual = pilha.top();
            pilha.pop();
            if(Maior->val<=atual->val){
                atual->next = Maior;
                Maior = atual;
            }
        }
        return Maior;
    }
};