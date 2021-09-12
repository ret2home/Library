---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/PersistentUnionFind.cpp
    title: structure/PersistentUnionFind.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,\
    \ int>\n#define pi acos(-1)\n#define len(s) (int)s.size()\n#define compress(v)\
    \ \\\n    sort(all(v));   \\\n    v.erase(unique(all(v)), v.end());\n#define comid(v,\
    \ x) lower_bound(all(v), x) - v.begin()\n\ntemplate<class T>\nusing prique=priority_queue<T,vector<T>,greater<>>;\n\
    \ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr ll inf\
    \ = 3e18;\n#line 3 \"structure/PersistentArray.cpp\"\n\ntemplate <class T>\nstruct\
    \ PersistentArray {\n    struct Node {\n        T val;\n        Node *ch[20];\n\
    \    };\n    void destructive_set(ll idx, T val, Node *&t) {\n        if (!t)\
    \ t = new Node();\n        if (idx == 0)\n            t->val = val;\n        else\n\
    \            destructive_set(idx / 20, val, t->ch[idx % 20]);\n    }\n    Node\
    \ *set(ll idx, T val, Node *t) {\n        Node *res = (t ? new Node(*t) : new\
    \ Node());\n        if (idx == 0)\n            res->val = val;\n        else\n\
    \            res->ch[idx % 20] = set(idx / 20, val, res->ch[idx % 20]);\n    \
    \    return res;\n    }\n    T get(ll idx, Node *t) {\n        assert(t);\n  \
    \      if (!idx) return t->val;\n        return get(idx / 20, t->ch[idx % 20]);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T>\n\
    struct PersistentArray {\n    struct Node {\n        T val;\n        Node *ch[20];\n\
    \    };\n    void destructive_set(ll idx, T val, Node *&t) {\n        if (!t)\
    \ t = new Node();\n        if (idx == 0)\n            t->val = val;\n        else\n\
    \            destructive_set(idx / 20, val, t->ch[idx % 20]);\n    }\n    Node\
    \ *set(ll idx, T val, Node *t) {\n        Node *res = (t ? new Node(*t) : new\
    \ Node());\n        if (idx == 0)\n            res->val = val;\n        else\n\
    \            res->ch[idx % 20] = set(idx / 20, val, res->ch[idx % 20]);\n    \
    \    return res;\n    }\n    T get(ll idx, Node *t) {\n        assert(t);\n  \
    \      if (!idx) return t->val;\n        return get(idx / 20, t->ch[idx % 20]);\n\
    \    }\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/PersistentArray.cpp
  requiredBy:
  - structure/PersistentUnionFind.cpp
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PersistentArray.cpp
layout: document
redirect_from:
- /library/structure/PersistentArray.cpp
- /library/structure/PersistentArray.cpp.html
title: structure/PersistentArray.cpp
---
