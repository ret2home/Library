---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/PersistentArray.cpp
    title: structure/PersistentArray.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (ll i = 0; i < n;\
    \ i++)\n#define REP(i, n) for (ll i = 1; i < n; i++)\n#define rev(i, n) for (ll\
    \ i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/PersistentArray.cpp\"\
    \n\ntemplate <class T>\nstruct PersistentArray {\n    struct Node {\n        T\
    \ val;\n        Node *ch[20];\n    };\n    void destructive_set(ll idx, T val,\
    \ Node *&t) {\n        if (!t) t = new Node();\n        if (idx == 0)\n      \
    \      t->val = val;\n        else\n            destructive_set(idx / 20, val,\
    \ t->ch[idx % 20]);\n    }\n    Node *set(ll idx, T val, Node *t) {\n        Node\
    \ *res = (t ? new Node(*t) : new Node());\n        if (idx == 0)\n           \
    \ res->val = val;\n        else\n            res->ch[idx % 20] = set(idx / 20,\
    \ val, res->ch[idx % 20]);\n        return res;\n    }\n    T get(ll idx, Node\
    \ *t) {\n        assert(t);\n        if (!idx) return t->val;\n        return\
    \ get(idx / 20, t->ch[idx % 20]);\n    }\n};\n#line 4 \"structure/PersistentUnionFind.cpp\"\
    \n\nstruct PersistentUnionFind {\n    using node = PersistentArray<P>::Node;\n\
    \    PersistentArray<P> data;\n    P find(ll x, node *t) {\n        P p = data.get(x,\
    \ t);\n        if (p.first == x) return p;\n        p = find(p.first, t);\n  \
    \      data.set(x, p, t);\n        return p;\n    }\n    bool same(ll x, ll y,\
    \ node *t) {\n        return find(x, t) == find(y, t);\n    }\n    ll size(ll\
    \ x, node *t) {\n        return data.get(find(x, t).first, t).second;\n    }\n\
    \    node *merge(ll x, ll y, node *t) {\n        P u = find(x, t), v = find(y,\
    \ t);\n        if (u.first == v.first) return new node(*t);\n        if (u.second\
    \ > v.second) swap(u, v);\n        node *res = data.set(u.first, {v.first, u.second},\
    \ t);\n        node *res2 = data.set(v.first, {v.first, u.second + v.second},\
    \ res);\n        delete (res);\n        return res2;\n    }\n    node *init(ll\
    \ x) {\n        node *root = new node();\n        rep(i, x) {\n            data.destructive_set(i,\
    \ {i, 1}, root);\n        }\n        return root;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"PersistentArray.cpp\"\
    \n\nstruct PersistentUnionFind {\n    using node = PersistentArray<P>::Node;\n\
    \    PersistentArray<P> data;\n    P find(ll x, node *t) {\n        P p = data.get(x,\
    \ t);\n        if (p.first == x) return p;\n        p = find(p.first, t);\n  \
    \      data.set(x, p, t);\n        return p;\n    }\n    bool same(ll x, ll y,\
    \ node *t) {\n        return find(x, t) == find(y, t);\n    }\n    ll size(ll\
    \ x, node *t) {\n        return data.get(find(x, t).first, t).second;\n    }\n\
    \    node *merge(ll x, ll y, node *t) {\n        P u = find(x, t), v = find(y,\
    \ t);\n        if (u.first == v.first) return new node(*t);\n        if (u.second\
    \ > v.second) swap(u, v);\n        node *res = data.set(u.first, {v.first, u.second},\
    \ t);\n        node *res2 = data.set(v.first, {v.first, u.second + v.second},\
    \ res);\n        delete (res);\n        return res2;\n    }\n    node *init(ll\
    \ x) {\n        node *root = new node();\n        rep(i, x) {\n            data.destructive_set(i,\
    \ {i, 1}, root);\n        }\n        return root;\n    }\n};"
  dependsOn:
  - template/template.cpp
  - structure/PersistentArray.cpp
  isVerificationFile: false
  path: structure/PersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-12-15 15:31:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PersistentUnionFind.cpp
layout: document
redirect_from:
- /library/structure/PersistentUnionFind.cpp
- /library/structure/PersistentUnionFind.cpp.html
title: structure/PersistentUnionFind.cpp
---
