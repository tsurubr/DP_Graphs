#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include <variant>


using namespace std;

template <typename T>
struct node {
    T info;
    node *left, *right;
    node() {};
    node(T i, node *l, node *r) {
        info = i; left = l; right = r;
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

template <typename T>
bool search(node<T>* r, T key) {
    return is_null(r)
           ? false
           : key == r->info
             ? true
             : key < r->info
               ? search(r->left, key)
               : search(r->right, key);
}

template <typename T>
bool search_2(node<T>* r, T key) {
    if (is_null(r)) return false;
    if (key == r->info) return true;
    if (key < r->info) return search(r->left, key);
    return search(r->right, key);
}


template <typename T>
node<T> *insert(node<T> *r, T key) {
    if (is_null(r)) return new node<T>(key, r, r); // arvore vazia
    if (key == r->info) return r; // key ja esta na arvore
    if (key < r->info)  // key deve ser inserido na sub esq de r
        r->left = insert(r->left, key);
    else 
        r->right = insert(r->right, key);
    return r;
}

// !is_null(r)
template <typename T>
node <T> *min(node<T> *r) {
    return is_null(r->left)
           ? r
           : min(r->left); 
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
    // key == r->info
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
    r->info = min(r->right)->info;
    r->right = remove(r->right, r->info);
    return r;
}

/*
       10
      /
     2

     3 11
      /  \               
   1 5    20 2                        
    /    /  \
 0 2  1 15  21 0       
       /  \
    0 14  17 0
        
    null<int>()

    1 2
     \ 
      2 1
       \
        3 0
*/


int count() {
    static int value = 0;
    return value++;
}


/* "equivale" a fazer o seguinte:
int value = 0;
int count() { return value++; }

*/

/* [10:20) 
          15
  [10:15)    [16:20)
*/

// pré-condição: b <= e
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


template <typename T>
vector<T> tree2vec(node<T> *r) {

    auto t2v = [](auto&& t2v, node<T> *r, vector<T>& v) {
        if (is_null(r)) return;
        t2v(t2v, r->left, v);
        v.push_back(r->info);
        t2v(t2v, r->right, v);
    }; 

    vector<T> v;
    t2v(t2v, r, v);
    return v;
}

int reduce(vector<int>& v, int neutro, function<int(int, int)> op) {
    for (int x: v) neutro = op(neutro, x);
    return neutro;
}

int sum(vector<int>& v) {
    return reduce(v, 0, [](int x, int y) {return x + y;});
}

int prod(vector<int>& v) {
    return reduce(v, 1, [](int x, int y) {return x * y;});
}


template <typename T>
int height(node<T> *r) {
    return is_null(r) 
           ? -1
           : max(height(r->left), height(r->right)) + 1;
}

template <typename T>
void erd(node<T>* r) {
    stack<variant<T, node<T>*>> s;
    s.push(r);
    while (!s.empty()) {
        auto x = s.top(); s.pop();
        if (holds_alternative<node<T>*>(x)) {
            auto r = get<node<T>*>(x);
            if (is_null(r)) continue;
            s.push(r->right);
            s.push(r->info);
            s.push(r->left);
        } else {
            T info = get<T>(x);
            cout << info << ' ';
        }

    }
}

int main() {
    auto p = build(10, 20);
    print_tree(p);
    p = insert(p, 2);
    p = insert(p, 8);
    vector<int> v = tree2vec(p);
    //for (int x: v) cout << x << ' ';
    //cout << search(p, 19) << ' ' << search(p, 8);
    erd(p);
}


