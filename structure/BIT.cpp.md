---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BIT.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BIT.cpp\"\n\ntemplate\
    \ <class T>\nclass BIT {\n    ll N;\n    vector<T> bit;\n    void add_(ll x, T\
    \ y) {\n        while (x <= N) {\n            bit[x] += y;\n            x += x\
    \ & -x;\n        }\n    }\n    T sum_(ll x) {\n        T res = 0;\n        while\
    \ (x > 0) {\n            res += bit[x];\n            x -= x & -x;\n        }\n\
    \        return res;\n    }\n\n   public:\n    ll lower_bound(T w) {\n       \
    \ if (w <= 0) return -1;\n        ll x = 0;\n        ll k = 1;\n        while\
    \ (k * 2 <= N) k *= 2;\n        for (; k > 0; k /= 2) {\n            if (x + k\
    \ <= N && bit[x + k] < w) {\n                w -= bit[x + k];\n              \
    \  x += k;\n            }\n        }\n        return x;\n    }\n    void add(ll\
    \ x, T y) { add_(x + 1, y); }\n    T sum(ll l, ll r) { return sum_(r) - sum_(l);\
    \ }\n    BIT(ll x) : N(x), bit(x + 1) {}\n};\n/*\n@brief Binary Indexed Tree\n\
    @docs docs/BIT.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T>\n\
    class BIT {\n    ll N;\n    vector<T> bit;\n    void add_(ll x, T y) {\n     \
    \   while (x <= N) {\n            bit[x] += y;\n            x += x & -x;\n   \
    \     }\n    }\n    T sum_(ll x) {\n        T res = 0;\n        while (x > 0)\
    \ {\n            res += bit[x];\n            x -= x & -x;\n        }\n       \
    \ return res;\n    }\n\n   public:\n    ll lower_bound(T w) {\n        if (w <=\
    \ 0) return -1;\n        ll x = 0;\n        ll k = 1;\n        while (k * 2 <=\
    \ N) k *= 2;\n        for (; k > 0; k /= 2) {\n            if (x + k <= N && bit[x\
    \ + k] < w) {\n                w -= bit[x + k];\n                x += k;\n   \
    \         }\n        }\n        return x;\n    }\n    void add(ll x, T y) { add_(x\
    \ + 1, y); }\n    T sum(ll l, ll r) { return sum_(r) - sum_(l); }\n    BIT(ll\
    \ x) : N(x), bit(x + 1) {}\n};\n/*\n@brief Binary Indexed Tree\n@docs docs/BIT.md\n\
    */"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BIT.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BIT.test.cpp
documentation_of: structure/BIT.cpp
layout: document
redirect_from:
- /library/structure/BIT.cpp
- /library/structure/BIT.cpp.html
title: Binary Indexed Tree
---
## 概要

Binary Indexed Tree (Fenwick Tree)

1点更新区間取得ができるデータ構造。和しか実装してないけど多分それくらいしか使わないはず？

- ```add(x,y)``` : ```x``` 番目の要素に```y``` を足す
- ```sum(l,r)``` : ```[l,r)``` の和
- ```lower_bound(w)``` : [0,x] の和が```w``` 以上となる最小のindex

## 計算量

全て $O(log\ N)$