#include <iostream>

using namespace std;
using ll = long long;

struct node {
    int info;
    node *next;
};

node *make_node(int info, node *next) {
    node *p = new node();
    p->info = info; p->next = next;
    return p;
}

// recebe n >= 0 e devolve uma lista ligada com os números 0,1,2,...n-1, nesta ordem
// VERSÂO HORROROSA
node *build(int n) {
    if (n == 0) return nullptr;
    if (n == 1) return make_node(0, nullptr);
    node *h = build(n-1);
    node *p;
    // 0 -> 1 -> 2 -> 3
    //                p 
    // 0 -> 1 -> 2 -> 3 -> 4
    for (p = h; p->next; p = p->next);
    p->next = make_node(n-1, nullptr);
    return h;
} 

// b <= e
// b -> (b+1) -> ... -> (e-1)
node *build(int b, int e) {
    if (b == e) return nullptr;
    // b < e
    node *h = build(b+1, e);
    // (b+1) -> (b+2) -> ... 
    // h
    // b
    return make_node(b, h);
}

//  b                   e
// {4, 2, 1, 6, 8, 9, 3}
// 4 -> 2 -> 1 -> 6 -> 8 -> 9 -> 3
node *build(int *b, int *e) {
    if (b == e) return nullptr;
    // b < e
    node *h = build(b+1, e);
    // (b+1) -> (b+2) -> ... 
    // h
    // b
    return make_node(*b, h);
}



//            
// d -> 4 -> 2 -> 7 -> 1 -> 8
// d -> 1 -> (4 -> 2 -> 7 -> 8)
//

// 
// ? -> 2 -> 7 -> 4 -> 8 -> 9
//      ? -> 7 -> 4 -> 8 -> 9
//           * 
node *mini(node *r) {
    if (r->next->next == nullptr) return r;
    node *m = mini(r->next);
    return r->next->info < m->next->info ? r : m;
}

node *isort(node *h){
    if (h == nullptr || h->next == nullptr) return h; // vazia
    node dum; d.next = h;
    
}

node *ssort_rec(node *h) {
    if (h == nullptr || h->next == nullptr) return h;
    // h tem pelo menos dois elementos
    node d;
    d.next = h;
    node *m = mini(&d);
    // d -> 4 -> 2 -> 7 -> 1 -> 8
    //                m    p
    node *p = m->next;    
    m->next = m->next->next;
    // d -> 4 -> 2 -> 7 -> 8
    node *s = ssort_rec(d.next);
    // 2 -> 4 -> 7 -> 8
    // s    
    p->next = s;
    return p;

}

//                  d    h
// 10 -> 12 -> 16   ? -> 4 -> 5 -> 9 -> 2 -> 6
// s                          m    mm 
//                                           p            

node *ssort(node *h) {
    node *s = nullptr;
    node d, *m = &d;
    d.next = h;
    while (d.next) {
        for (node *p = &d; p->next; p = p->next)
            if (m->next->info < p->next->info) m = p;
        node *mm = m->next;          
        m->next = m->next->next;
        mm->next = s;
        s = mm;
    }
    return s;
}
 
int len(const char *p) {
    const char * q;
    for (q = p; *q; ++q);
    return q - p;
}

// [b:e)
void foo(int *b, int *e) {
    cout << *b << endl;
    cout << sizeof(*b) << endl;
}


char *copy(const char *src) {
    char *dest = new char[len(src)];
    char *d = dest;
    while (*src) *dest++ = *src++;
    *dest = '\0';
    return d;
}

void pr_list(node *h) {
    if (h == nullptr) return;
    cout << h-> info << " ";
    pr_list(h->next);
}


int main() {
    int v[] {4, 1, 2, 3, 7, 8, 5, 6, 9, 0};
    node *h = build(v, v + 10);
    pr_list(ssort(h));
}
