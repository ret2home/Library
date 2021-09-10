---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/SparseTable.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n#define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n\
    #define comid(v,x) lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class\
    \ U>\ninline bool chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\ntemplate <class T, class U>\ninline\
    \ bool chmax(T &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SparseTable.cpp\"\
    \n\ntemplate <class T, T (*f)(T, T)>\nstruct SparseTable {\n    vector<T> table[20];\n\
    \    vector<int> log;\n    SparseTable(vector<T> v)\n        : log(v.size() +\
    \ 1) {\n        int mx = 0;\n        while (1 << (mx + 1) <= len(v)) ++mx;\n \
    \       rep(i, mx + 1) {\n            table[i].resize(len(v));\n            rep(j,\
    \ v.size() - (1 << i) + 1) {\n                if (i)\n                    table[i][j]\
    \ = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n                else\n\
    \                    table[i][j] = v[j];\n            }\n        }\n        for\
    \ (int i = 2; i <= len(v); i++) log[i] = log[i >> 1] + 1;\n    }\n    T query(int\
    \ l, int r) {\n        return f(table[log[r - l]][l], table[log[r - l]][r - (1\
    \ << log[r - l])]);\n    }\n};\n/*\n@brief Sparse Table\n@docs docs/SparseTable.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T,\
    \ T (*f)(T, T)>\nstruct SparseTable {\n    vector<T> table[20];\n    vector<int>\
    \ log;\n    SparseTable(vector<T> v)\n        : log(v.size() + 1) {\n        int\
    \ mx = 0;\n        while (1 << (mx + 1) <= len(v)) ++mx;\n        rep(i, mx +\
    \ 1) {\n            table[i].resize(len(v));\n            rep(j, v.size() - (1\
    \ << i) + 1) {\n                if (i)\n                    table[i][j] = f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n                else\n        \
    \            table[i][j] = v[j];\n            }\n        }\n        for (int i\
    \ = 2; i <= len(v); i++) log[i] = log[i >> 1] + 1;\n    }\n    T query(int l,\
    \ int r) {\n        return f(table[log[r - l]][l], table[log[r - l]][r - (1 <<\
    \ log[r - l])]);\n    }\n};\n/*\n@brief Sparse Table\n@docs docs/SparseTable.md\n\
    */\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:00:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SparseTable.test.cpp
documentation_of: structure/SparseTable.cpp
layout: document
redirect_from:
- /library/structure/SparseTable.cpp
- /library/structure/SparseTable.cpp.html
title: Sparse Table
---
## 概要

前計算を $O(N\ log N)$,クエリを $O(1)$ で処理するデータ構造。$f(a,f(b,c))=f(f(a,b),f(b,c))=f(f(a,b),c)$ が成り立つようなものしか載せられない。

例えばRMQはOKだが、RSQはNG。

- ```query(l,r)``` : $[l,r)$ の演算の結果

## 計算量

- 構築 : $O(N\ log N)$
- ```query(l,r)``` : $O(1)$