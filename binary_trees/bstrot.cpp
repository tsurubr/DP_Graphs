#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include <variant>
#include <utility>
#include <cassert>

using namespace std;

template <typename T> struct node;
template <typename T> node<T> *null();

template <typename T> bool is_null();

// !is_null(p)
template <typename T> void adjust_height(node<T> *p) {
    assert(!is_null(p));
    p->height = max(p->left->height, p->right->height) + 1;
} 

template <typename T>
struct node {
    T info;
    node *left, *right;
    int height;
    node() { height = -1; };
    node(T i) {
        info = i; left = null<T>(); right = null<T>();
        height = 0;
    }
    node(T i, node *l, node *r) {
        info = i; left = l; right = r;
        adjust_height(this);
    }
};

template <typename T>
inline node<T> *null() {
    static node<T> p = node<T>();
    return &p;
}

template <typename T>
inline bool is_null(node<T>* p) { 
    return p == null<T>(); 
}

/* Rotações em ABB
    10             8
   /  \   rotE    / \
  8   t3   =>    t1 10
 / \               /  \  
t1 t2             t2  t3
*/

// !is_null(r) && !is_null(r->left) 
template <typename T>
node<T> *rotE(node<T> *r) {
    node<T> *p = r->left;
    r->left = p->right;
    p->right = r;
    adjust_height(r);
    adjust_height(p);
    return p;
}

template <typename T>
node<T> *rotD(node<T> *r) {
    node<T> *p = r->right;
    r->right = p->left;
    p->left = r;
    adjust_height(r);
    adjust_height(p);
    return p;
}


template <typename T>
node <T> *contains(node<T> *r, T key) {
    if (is_null(r)) return r;
    if (key == r->info) return r;
    if (key < r->info) {
        if (is_null(r->left)) return r;
        r->left = contains(r->left, key);
        if (r->left->info == key) return rotE(r);
        return r;
    }
    if (is_null(r->right)) return r;
    r->right = contains(r->right, key);
    if (r->right->info == key) return rotD(r);
    return r;
}

template <typename T>
node <T> *insert(node<T> *r, T key) {
    if (is_null(r)) return new node<T>(key);
    if (key == r->info) return r;
    if (key < r->info) {
        r->left = insert(r->left, key);
        return rotE(r);
    }
    r->right = insert(r->right, key);
    return rotD(r);
}

template <typename T>
node <T> *remove(node<T> *r, T key) {
    if (is_null(r)) return r;
    if (key < r->info) {
        r->left = remove(r->left, key);
        return r;
    }
    if (key > r->info) {
        r->right = remove(r->right, key);
        return r;
    }
    if (is_null(r->left)) {
        auto p = r->right;
        delete r;
        return p;
    }
    if (is_null(r->right)) {
        auto p = r->left;
        delete r;
        return p;
    }
    r = rotE(r);
    r->right = remove(r->right, key);
    return r;
}
template <typename T>
node<T> insertav(node<T>*r, T info) {
  if(is_null(r)) return new node<T>(info);
  if(info == r->key) return r;
  if(info < r->key) {
    r->left = insert(r->left, info);
    if(r->left->height - r->right->height == 2) {
      auto p = r->left;
      if(p->left->height >= p->right->height)
        r = rotE(r);
      else {
        r->left = rotD(r->left);
        r = rotE(r);
      }
    }
  }
  adjust_height(r); return;
}

//       20
//      /
//     16

node<int> *build(int b, int e) {
    if (b == e) return null<int>();
    int m = b + (e-b)/2;
    node<int> *left = build(b, m);
    node<int> *right = build(m+1, e);
    return new node<int>(m, left, right);
}

template <typename T>
void print_tree(node<T> *r, int d = 0) {
    if (is_null(r)) return;
    for (int i = 0; i < d; ++i) cout << ' ';
    cout << r->info << endl;
    print_tree(r->left, d + 2);
    print_tree(r->right, d + 2);
}

int main() {
    auto r = build(10, 20);
    r = remove(r, 15);
    print_tree(r);
    adjust_height(null<int>());
}

