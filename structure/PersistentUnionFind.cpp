#pragma once
#include "../template/template.cpp"
#include "PersistentArray.cpp"

struct PersistentUnionFind {
    using node = PersistentArray<PL>::Node;
    PersistentArray<PL> data;
    PL find(ll x, node *t) {
        PL p = data.get(x, t);
        if (p.first == x) return p;
        p = find(p.first, t);
        data.set(x, p, t);
        return p;
    }
    bool same(ll x, ll y, node *t) {
        return find(x, t) == find(y, t);
    }
    ll size(ll x, node *t) {
        return data.get(find(x, t).first, t).second;
    }
    node *merge(ll x, ll y, node *t) {
        PL u = find(x, t), v = find(y, t);
        if (u.first == v.first) return new node(*t);
        if (u.second > v.second) swap(u, v);
        node *res = data.set(u.first, {v.first, u.second}, t);
        node *res2 = data.set(v.first, {v.first, u.second + v.second}, res);
        delete (res);
        return res2;
    }
    node *init(ll x) {
        node *root = new node();
        rep(i, x) {
            data.destructive_set(i, {i, 1}, root);
        }
        return root;
    }
};