---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
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
    \ = 3e18;\n#line 3 \"structure/Mo.cpp\"\n\nstruct Mo {\n    vector<int> left,\
    \ right, order;\n    vector<bool> v;\n    int width, l = 0, r = 0, cur = 0;\n\
    \    Mo(int n) : width(sqrt(n)), v(n) {}\n    void insert(int l, int r) {\n  \
    \      left.push_back(l);\n        right.push_back(r);\n    }\n    void init()\
    \ {\n        order.resize(len(left));\n        iota(all(order), 0);\n        sort(all(order),\
    \ [&](int a, int b) {\n            if (left[a] / width != left[b] / width) return\
    \ left[a] < left[b];\n            return right[a] < right[b];\n        });\n \
    \   }\n    int process() {\n        int id = order[cur];\n        while (l > left[id])\
    \ dis(--l);\n        while (r < right[id]) dis(r++);\n        while (l < left[id])\
    \ dis(l++);\n        while (r > right[id]) dis(--r);\n        return order[cur++];\n\
    \    }\n    inline void dis(int idx) {\n        v[idx].flip();\n        if (v[idx])\n\
    \            add(idx);\n        else\n            del(idx);\n    }\n    void add(int);\n\
    \    void del(int);\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Mo {\n    vector<int>\
    \ left, right, order;\n    vector<bool> v;\n    int width, l = 0, r = 0, cur =\
    \ 0;\n    Mo(int n) : width(sqrt(n)), v(n) {}\n    void insert(int l, int r) {\n\
    \        left.push_back(l);\n        right.push_back(r);\n    }\n    void init()\
    \ {\n        order.resize(len(left));\n        iota(all(order), 0);\n        sort(all(order),\
    \ [&](int a, int b) {\n            if (left[a] / width != left[b] / width) return\
    \ left[a] < left[b];\n            return right[a] < right[b];\n        });\n \
    \   }\n    int process() {\n        int id = order[cur];\n        while (l > left[id])\
    \ dis(--l);\n        while (r < right[id]) dis(r++);\n        while (l < left[id])\
    \ dis(l++);\n        while (r > right[id]) dis(--r);\n        return order[cur++];\n\
    \    }\n    inline void dis(int idx) {\n        v[idx].flip();\n        if (v[idx])\n\
    \            add(idx);\n        else\n            del(idx);\n    }\n    void add(int);\n\
    \    void del(int);\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/Mo.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/Mo.cpp
layout: document
redirect_from:
- /library/structure/Mo.cpp
- /library/structure/Mo.cpp.html
title: structure/Mo.cpp
---
