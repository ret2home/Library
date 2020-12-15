#pragma once
#include "../template/template.cpp"

template <class T>
struct PersistentArray {
    struct Node {
        T val;
        Node *ch[20];
    };
    void destructive_set(ll idx, T val, Node *&t) {
        if (!t) t = new Node();
        if (idx == 0)
            t->val = val;
        else
            destructive_set(idx / 20, val, t->ch[idx % 20]);
    }
    Node *set(ll idx, T val, Node *t) {
        Node *res = (t ? new Node(*t) : new Node());
        if (idx == 0)
            res->val = val;
        else
            res->ch[idx % 20] = set(idx / 20, val, res->ch[idx % 20]);
        return res;
    }
    T get(ll idx, Node *t) {
        assert(t);
        if (!idx) return t->val;
        return get(idx / 20, t->ch[idx % 20]);
    }
};