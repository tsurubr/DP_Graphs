#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int info;
    node *next;
};

node *make_node(int info, node *next){
    node *p = new node();
    p->info = info; p->next = next;
    return p;
}

node *build(int *b, int *e){
    if(b==e) return nullptr;
    node *h = build(b+1, e);
    return make_node(*b,h);
}

node *isorting(node *h){
    if(!h || !h->next) return h; // ll vazia ou com somente um elemento

    node dummy;
    dummy.next = h;
    node *prev = h, *cur = h->next; 
    
    while(cur){
        if(cur->info >= prev->info){ // avancar caso esteja ordenado
            prev = cur;
            cur = cur->next;
        }
        node *tmp = &dummy;
        while(cur->info > tmp->next->info){ // avanco ate um no com atributo valor  maior que o atual
            tmp = tmp->next;
        }
        // insiro no apontado em cur entre temp e temp.next
        prev->next = cur->next; // retiro cur e salvo prox no a ser ordenado
        cur->next = tmp->next; // aponta cur para o posterior ao tmp
        tmp->next = cur; // aponta tmp para cur, terminando insercao
        // advance
        cur = prev->next; // defino proximo no a ser inserido 
    }
    return dummy.next;
}

void pr_list(node *h) {
    if (h == nullptr) return;
    cout << h-> info << " ";
    pr_list(h->next);
}

int main() {
    int v[] {4, 1, 2, 3, 7, 8, 5, 6, 9, 0};
    node *h = build(v, v + 10);
    pr_list(isorting(h));
}
